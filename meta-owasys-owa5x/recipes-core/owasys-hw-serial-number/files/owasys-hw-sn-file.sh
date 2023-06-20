#!bin/bash
#===============================================================================
#
#          FILE:  owasys-hw-sn-file.sh
#
#         USAGE:  ./owasys-hw-sn-file.sh
#         DEBUG:  TRACE=1 ./owasys-hw-sn-file.sh
#
#   DESCRIPTION: Creates a file with owasys-sn at /tmp
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
    echo 'Usage: ./owasys-hw-sn-file.sh arg-one arg-two

This creates a file at /tmp with the owasys SN on it.

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

OWASYS_SN_FILE="/tmp/owasys-sn"
OWASYS_SN=$(echo "get sn
exit" | /bin/owasys-test-owa5x | grep "number" | cut -d " " -f 4)

if [ -f '$OWASYS_SN_FILE' ];
then
   echo "OWASYS_HW_SN_FILE: Updating owasys-sn..."
   echo "$OWASYS_SN" > $OWASYS_SN_FILE
else
   touch $OWASYS_SN_FILE
   echo "$OWASYS_SN" > $OWASYS_SN_FILE
   echo "OWASYS_HW_SN_FILE: owasys-sn file not found, created."
fi


}

main "$@"
