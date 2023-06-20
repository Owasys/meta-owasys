#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  rauc-post-install.sh
#
#         USAGE:  ./rauc-post-install.sh
#         DEBUG:  TRACE=1 ./rauc-post-install.sh
#
#   DESCRIPTION: Script executed by rauc in the post-install handler (after installing a bundle for owa5x)
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzgra
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-06-05
#===============================================================================

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

cd "$(dirname "$0")"

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo "Script executed by rauc in the post-install handler (after installing a bundle for owa5x)"
    exit
fi

BOOT_FOLDER_PATH="/boot"
UBOOT_FILE_NAME="owa5x-flash.bin"
MOUNT_PATH="/tmp/main"
BOOT_FOLDER_PATH="$MOUNT_PATH/$BOOT_FOLDER_PATH"
CURRENT_UBOOT="$BOOT_FOLDER_PATH/$UBOOT_FILE_NAME"
NEXT_UBOOT="$MOUNT_PATH/$BOOT_FOLDER_PATH/$UBOOT_FILE_NAME"
UBIPATH="/dev/ubi_file_systemB"
MTDNUMBER=5

################################# aux functions #############################

mount_other_partition(){

    if [ ! -d "$MOUNT_PATH" ]; then
        mkdir "$MOUNT_PATH"
    fi

    if [ "$RAUC_CURRENT_BOOTNAME" == "file-systemA" ]; then
        MTDNUMBER=5
        UBIPATH="/dev/ubi_file_systemB"
    elif [ "$RAUC_CURRENT_BOOTNAME" == "file-systemB" ]; then
        MTDNUMBER=4
        UBIPATH="/dev/ubi_file_systemA"
    fi
    
    if [ ! -h $UBIPATH ]; then
        ubiattach /dev/ubi_ctrl -m "$MTDNUMBER"
        sleep 1
    fi

    mount -t ubifs $UBIPATH $MOUNT_PATH
    rc=$?
    if [ ${rc} -eq 0 ]; then
        echo "$UBIPATH mounted"
    else
        echo "Mount $UBIPATH error ${rc}"
    fi
}

umount_other_partition(){
    umount $MOUNT_PATH
    local rc=$?
    if [ ${rc} -eq 0 ]; then
        echo "main $UBIPATH"
    else
        umount_main
    fi
}

flash_uboot(){
    flash "u-boot" $NEXT_UBOOT
}

flash(){
    MTDNAME=$(cat /proc/mtd | grep "$1"\" | cut -d : -f 1 | xargs basename)
    rc=$?
    if [ ${rc} -ne 0 ]
    then
        echo "ERROR ${rc}, partition u-boot not found"
        exit 1
    else
        echo "PARTITION $1:$MTDNAME"       
        kobs-ng init -v --chip_0_device_path=/dev/"$MTDNAME" --secondary_boot_stream_off_in_MB=4 "$2"
        rc=$?
        if [ ${rc} -ne 0 ]
        then
            echo "ERROR ${rc} flashing $1"
            exit 1
        else
            echo "Flash $1 OK"
        fi
    fi

    local MTDNAME
    MTDNAME=$(cat /proc/mtd | grep "$1"\" | cut -d : -f 1 | xargs basename)
    local rc=$?
    if [ ${rc} -ne 0 ]
    then
        echo "ERROR ${rc}, partition $1 not found"
        exit ${rc}
    else
        echo "PARTITION $1:$MTDNAME"
        /usr/sbin/flash_erase "/dev/$MTDNAME" 0 0 
        rc=$?
        if [ ${rc} -ne 0 ]
        then
            echo "ERROR ${rc} ERASING $1"
            exit ${rc}
        else
            echo "ERASE $1 OK"
        fi
        /usr/sbin/nandwrite -p "/dev/$MTDNAME" "$2"
        rc=$?
        if [ ${rc} -ne 0 ]
        then
            echo "ERROR ${rc} FLASING $1"
            exit ${rc}
        else
            echo "FLASH $1 OK"
        fi
    fi
}

################################# main function #############################

main() {
    local md5_file_path="/data/odm-ota/config/"
    local md5_uboot_file="$md5_file_path/uboot.md5"

    if [ ! -d "$BOOT_FOLDER_PATH" ]; then
        mount_other_partition
    fi

    if [ -f "$UBOOT" ]; then
        echo ""
        echo "Comparing u-boot md5..."
        echo ""
        local current_uboot_md5=($(md5sum "$CURRENT_UBOOT"))
        local next_uboot_md5=($(md5sum "$NEXT_UBOOT"))

        if [ "$current_uboot_md5" != "$next_uboot_md5" ]; then
            echo ""
            echo "U-boot md5 mismatch: $current_uboot_md5. -> $next_uboot_md5. Starting u-boot flash procedure..."
            echo ""
            flash_uboot
        fi
    fi

    umount_other_partition
}
main "$@"