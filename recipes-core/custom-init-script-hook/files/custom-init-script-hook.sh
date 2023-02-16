#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  <name>.sh
#
#         USAGE:  ./<name>.sh
#         DEBUG:  TRACE=1 ./<name>.sh
#
#   DESCRIPTION: External script to do this or that
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzxxx
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  YYYY-MM-DD
#===============================================================================

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: ./script.sh arg-one arg-two

   This script do amazing things.
'
    exit
fi

cd "$(dirname "$0")"

main() {

count=1

if [ -f '/home/custom_actions.sh' ];
then
   echo "Execute custom_actions.sh file"
   /home/custom_actions.sh
else
   echo "Not custom_actions.sh file found"
fi


}

main "$@"
