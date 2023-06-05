#!/bin/sh
#===============================================================================
#
#          FILE:  owasys-timesync.sh
#
#         USAGE:  /opt/scripts/owasys-timesync.sh
#         DEBUG:  
#
#   DESCRIPTION: Synchronizes RTC clock if the system is synchronized via NTP
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzppi
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-02-27
#===============================================================================

NTPSync=$(timedatectl show | grep 'NTPSynchronized=yes')
if [[ -z $NTPSync ]]; then
   echo "System not Synchronized"
   exit 0
fi
touch /var/lib/systemd/timesync/clock
CURRENT_RTC=$(/usr/bin/owasys-rtc)
CURRENT_SYS=$(date -u "+%s")
DIFF=$(($CURRENT_RTC-$CURRENT_SYS))
echo "RTC Difference: $DIFF"
if [ $DIFF -gt 2 ]; then
   sysclktohw
   echo "RTC synchronized"
elif [ $DIFF -lt -2 ]; then
   sysclktohw
   echo "RTC synchronized"
fi
