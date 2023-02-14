#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  manage-hw-file.sh
#
#         USAGE:  ./manage-hw-file.sh
#         DEBUG:  TRACE=1 ./manage-hw-file.sh
#
#   DESCRIPTION: Handles creation and maintenance of hw.json
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzagj
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-02-14
#===============================================================================

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: ./script.sh arg-one arg-two

   This script handles the hw.json file which holds info about the device HW written during owasys maufacturing process.
'
    exit
fi

cd "$(dirname "$0")"

main() {

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

if [ -f '/etc/u-boot-version' ]; then
   rm /etc/u-boot-version
fi
fw_printenv ver | sed "s,[^0-9]*,," | cut -d"=" -f1 >> /etc/u-boot-version


}

main "$@"
