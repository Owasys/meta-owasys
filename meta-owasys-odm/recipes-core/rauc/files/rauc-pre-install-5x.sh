#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  rauc-pre-install.sh
#
#         USAGE:  ./rauc-pre-install.sh
#         DEBUG:  TRACE=1 ./rauc-pre-install.sh
#
#   DESCRIPTION: Script executed by rauc in the pre-install handler (before installing a bundle for owa5x)
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzgra
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-03-16
#===============================================================================

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

cd "$(dirname "$0")"

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo "Script executed by rauc in the pre-install handler (before installing a bundle for owa5x)"
    exit
fi

################################# main function #############################

main() {
    local mtdNumber=5
    local ubiPath="/dev/ubi_file_systemB"
    if [ "$RAUC_CURRENT_BOOTNAME" == "file-systemA" ]; then
        mtdNumber=5
        ubiPath="/dev/ubi_file_systemB"
    elif [ "$RAUC_CURRENT_BOOTNAME" == "file-systemB" ]; then
        mtdNumber=4
        ubiPath="/dev/ubi_file_systemA"
    fi
    
    if [ ! -h $ubiPath ]; then
        ubiattach /dev/ubi_ctrl -m "$mtdNumber"
        sleep 1
    fi
}
main "$@"