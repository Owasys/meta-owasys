SUMMARY = "Linux kernel for Owasys owa5x i.MX8MP based board"
require recipes-kernel/linux/linux-imx.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "lzop-native bc-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# The recipe by default uses KBUILD_DEFCONFIG from the machine
# configuration. Set KBUILD_DEFCONFIG = "" and add a file 'defconfig' to
# SRC_URI to inject your defconfig in a bbappend.
# KERNEL_SRC ?= "git://source.codeaurora.org/external/imx/linux-imx.git;protocol=https"
SRC_URI = " git://source.codeaurora.org/external/imx/linux-imx.git;protocol=https;branch=${SRCBRANCH} \
            file://patch_kernel_5.10.72_1.0.7.patch \
"

LINUX_VERSION = "5.10.72"
SRCREV = "c59614bdd6f6b288a42cebda186f37da87968990"
SRCBRANCH = "lf-5.10.y"
LOCALVERSION = "-2.2.2"
COMPATIBLE_MACHINE = "(owa5x)"
KBUILD_DEFCONFIG ?= ""
KBUILD_DEFCONFIG:owa5x= "defconfig"

KERNEL_CONFIG_COMMAND = "oe_runmake_call ${PARALLEL_MAKE} -C ${S} CC="${KERNEL_CC}" O=${B} ${KBUILD_DEFCONFIG_owa5x}"

FILES:${PN} += " \
            file://patch_kernel_5.10.72_1.0.7.patch \
"

# Deploy symbols to allow for device tree overlays
EXTRA_OEMAKE += "DTC_FLAGS=-@ "

KERNEL_MODULE_AUTOLOAD += " owa5x_gpio "

do_configure:prepend(){
    if [ -e .config ]; then
        rm .config
    fi
    cp ${S}/owa5x_config.OWA ${S}/arch/arm64/configs/defconfig
}

#Create a symbolic link to the dtb so uboot script is able to boot keeping more flexibility for differents dtbs.
do_install:append(){
    install -d ${D}/boot
    cd ${D}/boot
    ln -s imx8mp-owa5x.dtb devicetree.dtb
}


