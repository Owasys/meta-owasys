#!/bin/bash
#Script to perform some basic maintenance actions.
count=1

hwfile_create.sh
hwvar_create.sh
uboot_check.sh
while [ $count -le 12 ]; do
   if [ -f '/var/lock/owaapi.lck' ]; then
      sleep 1
      count=$((count+1))
   else
      count=13
   fi
done
hwclktosys -s
if [ -f '/etc/hostname' ]; then
   hostname -F /etc/hostname
fi
if [ -f '/etc/u-boot-version' ]; then
   rm /etc/u-boot-version
fi
fw_printenv ver | sed "s,[^0-9]*,," | cut -d"=" -f1 >> /etc/u-boot-version

if [ -f '/home/custom_actions.sh' ];
then
   echo "Execute custom_actions.sh file"
   /home/custom_actions.sh
else
   echo "Not custom_actions.sh file found"
fi

exit 0
