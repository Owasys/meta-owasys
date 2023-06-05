#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  snyc-time-rtc.sh
#
#         USAGE:  ./snyc-time-rtc.sh
#         DEBUG:  TRACE=1 ./snyc-time-rtc.sh
#
#   DESCRIPTION: Script to pass rtc date to system at boot.
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

This is an awesome bash script to make your life better.

'
    exit
fi

cd "$(dirname "$0")"

main() {

count=1

while [ $count -le 12 ]; do
   if [ -f '/var/lock/owaapi.lck' ]; then
      sleep 1
      count=$((count+1))
   else
      count=13
   fi
done
hwclktosys

}

main "$@"
