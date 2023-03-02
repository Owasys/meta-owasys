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

expand_data_partitions
create_symlinks
clean_myself

}

expand_data_partitions() 
{

STR_FSTAB="/dev/mmcblk2p2"
DEV_FSTAB=$(grep data_backup /etc/fstab | awk '{print $1}')

if [ "$DEV_FSTAB" = "$STR_FSTAB" ]; then
   echo "No need to update /etc/fstab, data partitions already resized."
   clean_myself
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

main "$@"
