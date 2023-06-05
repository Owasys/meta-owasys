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

MOUNT_PATH="/tmp/main"

 ################################# aux functions #############################

get_booted_partition(){
    echo "$RAUC_CURRENT_BOOTNAME"
}

make_boot_md5_files(){
    local boot_folder_path="/boot"
    local uboot="$boot_folder_path/owa5x-flash.bin"
    local md5_file_path="/data/odm-ota/config/"

    if [ -f "$uboot" ]; then
        echo ""
        echo "Creating uboot md5 file..."
        echo ""
        local md5=($(md5sum "$uboot"))
        echo "$md5" > "$md5_file_path/owa5x-flash.md5"
    fi
}

################################# main function #############################

main() {
    local booted
    local mtdNumber=5
    local ubiPath="/dev/ubi_file_systemB" 
    #booted=get_booted_partition
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