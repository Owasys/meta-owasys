#!/bin/bash
#Script to maintain /etc/default/hw.json file

chkbackup=0
STR_CON="console"

if [ -f '/etc/default/hw.json' ];
then
   echo "HW file does exist"
   chkbackup=1
else
   echo "HW file does not exist"
   fw_printenv hwfile >> 1.txt
   if cat 1.txt | grep -q 'hwfile='; then
      sed '/hwfile=/d' 1.txt >> 2.txt
      echo { >> hw.json 
      cat 2.txt >> hw.json
      rm 1.txt
      rm 2.txt
      mv hw.json /etc/default/
      echo "HW file generated"
      chkbackup=1
   else
      echo "HW variable dos not exist"
      rm 1.txt

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
         exit 1
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
            if [ -f '/tmp/fs/etc/default/hw.json' ];
            then
               cp /tmp/fs/etc/default/hw.json /etc/default/hw.json
               if [ ${rc} -eq 0 ]
               then
                  echo "hw.json file copied from Inactive partition"
               else
                  echo "Unable to cpy hw.json file from Inactive partition"
               fi
            else
               echo "hw.json file is not in Inactive partition"
            fi
            umount /tmp/fs
            ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
         else
            echo "Unable to mount Inactive partition to check hw.json file"
            ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
         fi
      else
         echo "Unable to attach Inactive partition to check hw.json file"
      fi
   fi
fi

if [ ${chkbackup} -eq 1 ]
then
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
      exit 1
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
         if [ ! -d '/tmp/fs/etc/default' ]; then
            mkdir -p /tmp/fs/etc/default
         fi
         if [ -f '/tmp/fs/etc/default/hw.json' ];
         then
            echo "hw.json file is in Inactive partition"
         else
            cp /etc/default/hw.json /tmp/fs/etc/default/hw.json
            if [ ${rc} -eq 0 ]
            then
               echo "hw.json file copied to Inactive partition"
            else
               echo "Unable to cpy hw.json file to Inactive partition"
            fi
         fi
         umount /tmp/fs
         ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
      else
         echo "Unable to mount Inactive partition to check hw.json file"
         ubidetach /dev/ubi_ctrl -p /dev/$MTDNAME
      fi
   else
      echo "Unable to attach Inactive partition to check hw.json file"
   fi
fi

exit 0
