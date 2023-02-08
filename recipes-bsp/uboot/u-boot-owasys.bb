SUMMARY = "U-Boot for Owasys owa5x"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=5a7450c57ffe5ae63fd732446b988025"

require recipes-bsp/u-boot/u-boot.inc

DEPENDS += "bc-native dtc-native bison-native imx-atf-owasys"

SRCREV = "8372631b287e98ffda15d6412a38ebe37433ea0b"
SRCBRANCH = "lf_v2021.04"
SRC_URI = " git://source.codeaurora.org/external/imx/uboot-imx.git;protocol=https;branch=${SRCBRANCH} \
            file://0001-patch_uboot_5.10.72_1.0.5.patch \
"

COMPATIBLE_MACHINE = "(owa5x)"

#UBOOT_INITIAL_ENV = "u-boot-initial-env"
BOOT_TOOLS = "imx-boot-tools"
PROVIDES += "u-boot-owasys"
S = "${WORKDIR}/git"
B = "${WORKDIR}/build"


do_deploy () {
   bbnote "copy mkimage_uboot from tools/ to ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/"
   install -d ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}     
   install -m 0777 ${B}/${UBOOT_CONFIG}_defconfig/tools/mkimage        ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/mkimage_uboot-${MACHINE}-${UBOOT_CONFIG}
   install -m 0644 ${B}/${UBOOT_CONFIG}_defconfig/spl/u-boot-spl.bin   ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot-spl.bin-${MACHINE}-${UBOOT_CONFIG}
   install -m 0644 ${B}/${UBOOT_CONFIG}_defconfig/u-boot.bin           ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot.bin-${MACHINE}-${UBOOT_CONFIG}
   install -m 0644 ${B}/${UBOOT_CONFIG}_defconfig/u-boot-nodtb.bin     ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot-nodtb.bin-${MACHINE}-${UBOOT_CONFIG}
   install -m 0644 ${B}/${UBOOT_CONFIG}_defconfig/u-boot.dtb           ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/${UBOOT_DTB_NAME}-${MACHINE}
}
