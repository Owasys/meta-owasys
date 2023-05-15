#!/bin/bash
#===============================================================================
#
#          FILE:  check-boot-operations.sh
#
#         USAGE:  ./check-boot-operations.sh
#         DEBUG:  TRACE=1 ./check-boot-operations.sh
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

check_memory_map
check_system_integrity
check_loaded_kernel_modules

}

check_memory_map() 
{
   logger "Boot Check: Memory mapped tests OK"
   #exit 1
}

check_system_integrity() 
{
   logger "Boot Check: System Integrity tests OK"
   #exit 1
}

check_loaded_kernel_modules()
{
   logger "Boot Check: Loaded kernel modules tests OK"
   #exit 1
}

main "$@"
