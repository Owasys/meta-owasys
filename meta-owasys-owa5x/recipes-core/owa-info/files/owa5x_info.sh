#!/bin/sh
#===============================================================================
#
#          FILE:  owa5x_info.sh
#
#         USAGE:  ./owa5x_info.sh
#
#   DESCRIPTION: owa5x information log
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owziap
#       COMPANY:  Owasys SL
#       CREATED:  11-23-2021
#===============================================================================

VERSION=0.0.1
LOG_FILE="/tmp/owa5x_info.log"

echo "----owa5x_info version----" > $LOG_FILE
echo $VERSION >> $LOG_FILE
echo "----serial----" >> $LOG_FILE
echo "get sn
exit" | Test_owa5x | grep Serial >> $LOG_FILE
echo "----FW-FS----" >> $LOG_FILE
cat /etc/issue.owa >> $LOG_FILE
echo "getversion
exit" | Test_owa5x | grep Version >> $LOG_FILE
cat /proc/cmdline >> $LOG_FILE
echo "----owasys libraries lib - info----" >> $LOG_FILE
ls -l /lib/lib* >> $LOG_FILE
echo "----owasys libraries lib/owasys - info----" >> $LOG_FILE
ls -l /lib/owasys/* >> $LOG_FILE
echo "----device-info----" >> $LOG_FILE
cat /etc/pmsrv/device.info >> $LOG_FILE
echo "----ppp config----" >> $LOG_FILE
cat /etc/ppp/peers/ppppty >> $LOG_FILE
echo "----FW-Kernel----" >> $LOG_FILE
uname -a >> $LOG_FILE
ls /lib/modules >> $LOG_FILE
lsmod >> $LOG_FILE
echo "" >> $LOG_FILE
echo "----uptime----" >> $LOG_FILE
uptime >> $LOG_FILE
echo "----processes----" >> $LOG_FILE
ps aux | grep -v $0 >> $LOG_FILE
top -b -n 1 >> $LOG_FILE
echo "----memory----" >> $LOG_FILE
cat /proc/meminfo >> $LOG_FILE
free >> $LOG_FILE
echo "----disk----" >> $LOG_FILE
df -h >> $LOG_FILE
du -d 2 --separate-dirs -h / |sort -hr >> $LOG_FILE
echo "----network info----" >> $LOG_FILE
ip a >> $LOG_FILE
ip route >> $LOG_FILE
cat /etc/resolv.conf >> $LOG_FILE
echo "----running services----" >> $LOG_FILE
systemctl list-units | grep running >> $LOG_FILE
echo "----dmesg log----" >> $LOG_FILE
dmesg >> $LOG_FILE
echo "----kernel log----" >> $LOG_FILE
tail --line 15 /var/log/kern.log >> $LOG_FILE
echo "----pmsrv service----" >> $LOG_FILE
systemctl status pmsrv >> $LOG_FILE
cat /etc/pmsrv/pmsrv.info >> $LOG_FILE
echo "----hw.json contents----" >> $LOG_FILE
cat /etc/default/hw.json >> $LOG_FILE
echo "------------------------" >> $LOG_FILE
echo "system info logged succesfully"
echo "please send $LOG_FILE to customer_support@owasys.com"
