#!/bin/bash
#Script to create hwfile environment var from/etc/default/hw.json file

STR_CON="console"

fw_printenv hwfile >> 1.txt
if cat 1.txt | grep -q 'hwfile='; then
   rm 1.txt
   echo "HW environment variable does exist"
else
   rm 1.txt
   echo "HW environment variable does NOT exist"
   if [ -f '/etc/default/hw.json' ];
   then
      echo "Main hw.json file does exist"
      echo "#!/bin/bash" > new1
      printf "fw_setenv hwfile \"" > new2
      sed 's/\"/\\"/g' </etc/default/hw.json >new3
      printf %s "$(< new3)" > new4
      echo "\"" > new5
      cat new1 new2 new4 new5 > new.sh
      chmod +x new.sh
      ./new.sh
      rm new*
      echo "HW environment variable created from main"
      exit 0
   else
      echo "Main hw.json file does NOT exist"
      CONSOLE=$(cat /proc/cmdline | grep file-systemA | cut -d = -f 1 | xargs basename)
      echo "PARTITION:$CONSOLE"
      if [ "$CONSOLE" = "$STR_CON" ]; then
         echo "file-systemA is active"
         FS="B"
      else
         echo "file-systemA is NOT active"
         FS="A"
      fi      

#      CONSOLE=$(cat /proc/cmdline | grep file-systemB | cut -d = -f 1 | xargs basename)
#      echo "PARTITION:$CONSOLE"
#      if [ "$CONSOLE" = "$STR_CON" ]; then
#         echo "file-systemB is active"
#         FS="A"
#      else
#         echo "file-systemB is NOT active"
#         FS="B"
#      fi      

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
               rc=$?
               if [ ${rc} -eq 0 ]
               then
                  echo "hw.json file copied from Backup partition"
                  echo "#!/bin/bash" > new1
                  printf "fw_setenv hwfile \"" > new2
                  sed 's/\"/\\"/g' </etc/default/hw.json >new3
                  printf %s "$(< new3)" > new4
                  echo "\"" > new5
                  cat new1 new2 new4 new5 > new.sh
                  chmod +x new.sh
                  ./new.sh
                  rm new*
                  echo "HW environment variable created from backup"
               else
                  echo "Unable to copy hw.json file from Inactive partition"
               fi
            else
               echo "hw.json file is not in the Inactive partition"
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

exit 0
