#!/bin/bash
#===============================================================================
#
#          FILE:  measured-boot.sh
#
#         USAGE:  ./measured-boot.sh
#         DEBUG:  TRACE=1 ./measured-boot.sh
#
#   DESCRIPTION: Script to determine if a boot was correct. It should return 0,
#                returning 1 ( exit 1 ) means an error and it will reboot the system.
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzagj
#       COMPANY:  Owasys SL
#       VERSION:  0.0.0
#       CREATED:  2023-05-10
#===============================================================================

main() {

measure_bootloader
measure_kernel
measure_dtb
measure_init
measure_linker

if [ ! -d "/device/tpm" ]; then
   /usr/bin/create-provision-keys.sh
fi

}

measure_bootloader() 
{
   SHA256_VALUE=$(sha256sum /dev/mtd0 | cut -d " " -f 1 )
   RET=$(tpm2_pcrextend 0:sha256="$SHA256_VALUE")
   if [ $RET ];then
      echo "Measured bootloader NO OK"
      return 1
   fi
   logger "Measured bootloader OK"
   echo "$(tpm2_pcrread sha256:0)"
   #exit 1
}

measure_kernel() 
{
   SHA256_VALUE=$(sha256sum /boot/Image | cut -d " " -f 1 )
   RET=$(tpm2_pcrextend 1:sha256="$SHA256_VALUE")
   if [ $RET ];then
      echo -"Measured kernel NO OK"
      return 1
   fi
   logger "Measured kernel OK"
   echo "$(tpm2_pcrread sha256:1)"
   #exit 1
}

measure_dtb()
{
   SHA256_VALUE=$(sha256sum /boot/devicetree.dtb | cut -d " " -f 1 )
   RET=$(tpm2_pcrextend 2:sha256="$SHA256_VALUE")
   if [ $RET ];then
      echo "Measured devicetree NO OK"
      return 1
   fi
   logger "Measured devicetree OK"   
   echo "$(tpm2_pcrread sha256:2)"
   #exit 1
}

measure_init() 
{
   SHA256_VALUE=$(sha256sum /sbin/init | cut -d " " -f 1 )
   RET=$(tpm2_pcrextend 3:sha256="$SHA256_VALUE")
   if [ $RET ];then
      echo "Measured init NO OK"
      return 1
   fi
   logger "Measured init OK" 
   echo "$(tpm2_pcrread sha256:3)"
   #exit 1
}

measure_linker()
{
   SHA256_VALUE=$(sha256sum /lib/ld-linux-aarch64.so.1 | cut -d " " -f 1 )
   RET=$(tpm2_pcrextend 4:sha256="$SHA256_VALUE")
   if [ $RET ];then
      echo "Measured linker NO OK"
      return 1
   fi
   logger "Measured linker OK"    
   echo "$(tpm2_pcrread sha256:4)"
   #exit 1
}

main "$@"
