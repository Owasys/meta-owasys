SUMMARY = "First Owasys owa5X YOCTO initramfs image"
# Simple initramfs image. Mostly used for live images.
DESCRIPTION = "Small image capable of booting a device. The kernel includes \
the Minimal RAM-based Initial Root Filesystem (initramfs), which one can use \
to check the hardware efficiently."
IMAGE_LINGUAS = "en-us"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

IMAGE_FSTYPES:append = " cpio.xz"

PACKAGE_INSTALL = " \
                    initramfs-debug \
                    busybox \
                    base-passwd \
                    ${ROOTFS_BOOTSTRAP_INSTALL} \ 
                    kernel-module-dm-bufio \
                    kernel-module-dm-mod \
                    kernel-module-dm-verity \
                    kernel-module-dm-crypt \
                    "

# Do not pollute the initrd image with rootfs features
IMAGE_FEATURES = ""

export IMAGE_BASENAME = "cetus-initramfs-debug-image"

# Some BSPs use IMAGE_FSTYPES_<machine override> which would override
# an assignment to IMAGE_FSTYPES so we need anon python
python () {
    d.setVar("IMAGE_FSTYPES", d.getVar("INITRAMFS_FSTYPES"))
}

inherit core-image

IMAGE_ROOTFS_SIZE = "8192"
IMAGE_ROOTFS_EXTRA_SPACE = "0"

BAD_RECOMMENDATIONS += "busybox-syslog"

