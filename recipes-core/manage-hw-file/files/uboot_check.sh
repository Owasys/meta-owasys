#!/bin/bash
#Script to check if u-boot has started from primary or secondary image offset
#If started from secondary flash again u-boot file

PRIMARY_IMAGE="100000"

fw_printenv uboot_img_addr >> 1.txt
if cat 1.txt | grep -q 'uboot_img_addr='; then
   rm 1.txt
   echo "U-BOOT address environment variable does exist"
   
   ADDRESS=$(fw_printenv uboot_img_addr | cut -d"=" -f 2)
   echo "ADDRESS:$ADDRESS"
   if [ "$ADDRESS" = "$PRIMARY_IMAGE" ]; then
      echo "START FROM U-BOOT PRIMARY IMAGE"
   else
      echo "START FROM U-BOOT SECONDARY IMAGE"
      if [ -f '/boot/uboot/flash.bin' ];
      then
         echo "Uboot file FOUND"

         MTDNAME=$(cat /proc/mtd | grep u-boot\" | cut -d : -f 1 | xargs basename)
         rc=$?
         if [ ${rc} -ne 0 ]
         then
            echo "ERROR ${rc}, partition u-boot not found"
         else
            echo "PARTITION u-boot:$MTDNAME"       
            kobs-ng init -v --chip_0_device_path=/dev/$MTDNAME /boot/uboot/flash.bin
            rc=$?
            if [ ${rc} -ne 0 ]
            then
               echo "ERROR ${rc} flashing u-boot"
            else
               echo "Flash u-boot OK"
            fi
         fi
      else
         echo "Uboot file NOT FOUND"
      fi
   fi      
else
   rm 1.txt
   echo "U-BOOT address environment variable does not exist"
fi

exit 0
