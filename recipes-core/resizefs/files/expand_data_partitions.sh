#!/bin/bash
# This script checks if there is a partitions p2 in mmcblk2 device and proceed to create if it doesn't.

STR_FSTAB="/dev/mmcblk2p2"
DEV_FSTAB=$(grep data_backup /etc/fstab | awk '{print $1}')

if [ "$DEV_FSTAB" = "$STR_FSTAB" ]; then
   echo "No need to update /etc/fstab, data partitions already resized."
   rm /usr/bin/expand_data_partitions.sh
   systemctl disable resizefs
   rm /etc/systemd/system/resizefs.service
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