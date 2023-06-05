# Copyright 2017-2018 NXP

require imx-mkimage_git.inc

DESCRIPTION = "Generate Boot Loader for owa5x device"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"
SECTION = "BSP"

DEPENDS += " \
    u-boot-owasys \
    imx-atf-owasys \
"
DEPENDS:append:owa5x = " dtc-native"
BOOT_NAME = "imx-boot-owasys"
PROVIDES = "${BOOT_NAME}"

inherit deploy

# Add CFLAGS with native INCDIR & LIBDIR for imx-mkimage build
CFLAGS = "-O2 -Wall -std=c99 -I ${STAGING_INCDIR_NATIVE} -L ${STAGING_LIBDIR_NATIVE}"

# This package aggregates output deployed by other packages,
# so set the appropriate dependencies
do_compile[depends] += " \
    virtual/bootloader:do_deploy \
    imx-atf-owasys:do_deploy \
    ${@bb.utils.contains('MACHINE_FEATURES', 'optee', 'optee-os:do_deploy', '', d)} \
"

ATF_MACHINE_NAME:owa5x = "bl31-imx8mp.bin"
ATF_MACHINE_NAME:append = "${@bb.utils.contains('MACHINE_FEATURES', 'optee', '-optee', '', d)}"

UBOOT_NAME = "u-boot-${MACHINE}.bin-${UBOOT_CONFIG}"
BOOT_CONFIG_MACHINE = "${BOOT_NAME}-${MACHINE}-${UBOOT_CONFIG}.bin"

TOOLS_NAME ?= "mkimage_imx8"

SOC_TARGET       ?= "INVALID"
SOC_TARGET:owa5x  = "iMX8MP"

DEPLOY_OPTEE = "${@bb.utils.contains('MACHINE_FEATURES', 'optee', 'true', 'false', d)}"

IMXBOOT_TARGETS ?= \
    "${@bb.utils.contains('UBOOT_CONFIG', 'fspi', 'flash_flexspi', \
        bb.utils.contains('UBOOT_CONFIG', 'nand', 'flash_nand', \
                                                  'flash flash_dcd', d), d)}"

BOOT_STAGING       = "${S}/${SOC_TARGET}"
BOOT_STAGING:owa5x = "${S}/iMX8M"


SOC_FAMILY      = "INVALID"
SOC_FAMILY:mx8-nxp-bsp  = "mx8"
SOC_FAMILY:mx8m-nxp-bsp = "mx8m"
SOC_FAMILY:mx8x-nxp-bsp = "mx8x"
SOC_FAMILY:owa5x = "owa5x"

compile_owa5x() {
    bbnote "owa5x boot binary build"

    for ddr_firmware in ${DDR_FIRMWARE_NAME}; do
        bbnote "Copy ddr_firmware: ${ddr_firmware} from ${DEPLOY_DIR_IMAGE} -> ${BOOT_STAGING} "
        cp ${WORKDIR}/${ddr_firmware} ${BOOT_STAGING}
    done

    bbnote "copy u-boot-spl.bin from ${DEPLOY_DIR_IMAGE} to ${BOOT_STAGING} "
    cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot-spl.bin-${MACHINE}-${UBOOT_CONFIG} ${BOOT_STAGING}/u-boot-spl.bin

    bbnote "copy u-boot.bin from ${DEPLOY_DIR_IMAGE} to ${BOOT_STAGING} "
    cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot.bin-${MACHINE}-${UBOOT_CONFIG} ${BOOT_STAGING}/u-boot.bin
    
    bbnote "copy ${UBOOT_DTB_NAME} from ${DEPLOY_DIR_IMAGE} to ${BOOT_STAGING} "
    cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/${UBOOT_DTB_NAME}-${MACHINE} ${BOOT_STAGING}/${UBOOT_DTB_NAME}

    bbnote "copy u-boot-nodtb.bin-${MACHINE}-${UBOOT_CONFIG} from {DEPLOY_DIR_IMAGE}/${BOOT_TOOLS} to ${BOOT_STAGING} "
    cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/u-boot-nodtb.bin-${MACHINE}-${UBOOT_CONFIG} ${BOOT_STAGING}/u-boot-nodtb.bin

    bbnote "copy mkimage_uboot from ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS} to ${BOOT_STAGING} "                                                             
    install -m 0755 ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/mkimage_uboot-${MACHINE}-${UBOOT_CONFIG} ${BOOT_STAGING}/mkimage_uboot

    bbnote "copy bl31.bin from ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/${ATF_MACHINE_NAME} to ${BOOT_STAGING} "
    cp ${DEPLOY_DIR_IMAGE}/${BOOT_TOOLS}/${ATF_MACHINE_NAME} ${BOOT_STAGING}/bl31.bin
}

do_compile() {
    bbnote "Enter do_compile"
    compile_${SOC_FAMILY}
    # mkimage for i.MX8
    if ${DEPLOY_OPTEE}; then
        bbnote "flash.bin includes trusted execution environment "
        cp ${DEPLOY_DIR_IMAGE}/tee.bin ${BOOT_STAGING}
    fi

    for target in ${IMXBOOT_TARGETS}; do
        bbnote "building ${SOC_TARGET} - ${target}"
        make SOC=${SOC_TARGET} ${target}
        if [ -e "${BOOT_STAGING}/flash.bin" ]; then
            cp ${BOOT_STAGING}/flash.bin    ${DEPLOY_DIR_IMAGE}/${MACHINE}-flash.bin
            cp ${BOOT_STAGING}/flash.bin    ${DEPLOY_DIR_IMAGE}/u-boot.bin
            bbnote "Copied flash.bin from ${BOOT_STAGING}/ to ${S}/${BOOT_CONFIG_MACHINE}-${target}"
        fi
    done
}

do_install () {
    install -d ${D}/boot
    for target in ${IMXBOOT_TARGETS}; do
        install -m 0644 ${S}/iMX8M/flash.bin ${D}/boot/
    done
}

deploy_owa5x() {
    install -d ${DEPLOYDIR}/${BOOT_TOOLS}
    install -m 0644 ${DEPLOY_DIR_IMAGE}/u-boot-spl.bin-${MACHINE}-${UBOOT_CONFIG} \
                                                             ${DEPLOYDIR}/${BOOT_TOOLS}
    for ddr_firmware in ${DDR_FIRMWARE_NAME}; do
        install -m 0644 ${DEPLOY_DIR_IMAGE}/${ddr_firmware}  ${DEPLOYDIR}/${BOOT_TOOLS}
    done
    install -m 0644 ${BOOT_STAGING}/signed_dp_imx8m.bin      ${DEPLOYDIR}/${BOOT_TOOLS}
    install -m 0644 ${BOOT_STAGING}/signed_hdmi_imx8m.bin    ${DEPLOYDIR}/${BOOT_TOOLS}
    install -m 0755 ${BOOT_STAGING}/${TOOLS_NAME}            ${DEPLOYDIR}/${BOOT_TOOLS}
    install -m 0755 ${BOOT_STAGING}/mkimage_fit_atf.sh       ${DEPLOYDIR}/${BOOT_TOOLS}
}

do_deploy() {
    bbnote "Everything has been already deployed"
}
addtask deploy before do_build after do_compile

PACKAGE_ARCH = "${MACHINE_ARCH}"
FILES:${PN} = "/boot"

COMPATIBLE_MACHINE = "(owa5x)"
