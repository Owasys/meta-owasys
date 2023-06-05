#!/bin/bash
#===============================================================================
#
#          FILE:  first-boot-operations.sh
#
#         USAGE:  ./first-boot-operations.sh
#         DEBUG:  TRACE=1 ./first-boot-operations.sh
#
#   DESCRIPTION: External script to do this or that
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzagj
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-02-21
#===============================================================================

main() {

block_tpm_clear_command
expand_data_partitions
rc=$?
echo "EXPAND return ${rc}"
if [ ${rc} -eq 0 ]
then
   create_symlinks
fi
clean_myself
setup_the_other_partition

}

expand_data_partitions() 
{

STR_FSTAB="/dev/mmcblk2p2"
DEV_FSTAB=$(grep data_backup /etc/fstab | awk '{print $1}')

if [ "$DEV_FSTAB" = "$STR_FSTAB" ]; then
   echo "No need to update /etc/fstab, data partitions already resized."
   return 1
else

echo "
d
4

d
3

d
2

d
1

d

n
p
1
2048
12000000
n
p
2
12000010

w" | fdisk /dev/mmcblk2

   echo "y" | mkfs.ext4 /dev/mmcblk2p1
   echo "y" | mkfs.ext4 /dev/mmcblk2p2
   echo "/dev/mmcblk2p1    /data/            ext4          defaults         0      0" >> /etc/fstab
   echo "/dev/mmcblk2p2    /data_backup/     ext4          defaults         0      0" >> /etc/fstab
   echo "/etc/fstab updated"
   mkdir /data_backup
   mount -a

fi
return 0
}

create_symlinks() 
{
   mkdir -p /data/home/db
   mkdir -p /data/var/log
   ln -s /data/home/db /home/db
   ln -s /data/var/log /home/log 
}

clean_myself()
{
   rm /usr/bin/first-boot-operations.sh
   systemctl disable owasysd-first-boot-operations
   rm /etc/systemd/system/owasysd-first-boot-operations.service
}

block_tpm_clear_command()
{
   tpm2_clearcontrol -C p -P owasys s
}

setup_the_other_partition() 
{
   STR_CON="console"

   CONSOLE=$(cat /proc/cmdline | grep file-systemA | cut -d = -f 1 | xargs basename)
   echo "PARTITION:$CONSOLE"
   if [ "$CONSOLE" = "$STR_CON" ]; then
      echo "file-systemA is active"
      FS="B"
   else
      echo "file-systemA is NOT active"
      FS="A"
   fi      
   MTDNAME=$(cat /proc/mtd | grep file-system$FS | cut -d : -f 1 | xargs basename)
   rc=$?
   if [ ${rc} -ne 0 ]
   then
      echo "ERROR ${rc}, partition not found"
      return
   else
      echo "PARTITION:$MTDNAME"
   fi

   if [ ! -d '/tmp/fs' ]; then
      mkdir -p /tmp/fs
   fi
   ubiattach /dev/ubi_ctrl -p /dev/$MTDNAME
   rc=$?
   if [ ${rc} -eq 0 ]
   then
      mount -t ubifs ubi1_0 /tmp/fs
      rc=$?
      if [ ${rc} -eq 0 ]
      then
         rm -r /tmp/fs/var/log
         ln -s /data/var/log /tmp/fs/var/log
         cp /etc/fstab /tmp/fs/etc/fstab
         rc=$?
         if [ ${rc} -eq 0 ]
         then
            echo "/etc/fstab file copied to file-system$FS"
         else
            echo "Unable to copy /etc/fstab file copied to file-system$FS"
         fi
         umount /tmp/fs
         ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
      else
         echo "Unable to mount Inactive partition to update /etc/fstab"
         ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
      fi
   else
      echo "Unable to attach Inactive partition to update /etc/fstab"
   fi
}

main "$@"
