SUMMARY = "Linux kernel for Owasys owa5x i.MX8MP based board"
require recipes-kernel/linux/linux-imx.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

DEPENDS += "lzop-native bc-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# The recipe by default uses KBUILD_DEFCONFIG from the machine
# configuration. Set KBUILD_DEFCONFIG = "" and add a file 'defconfig' to
# SRC_URI to inject your defconfig in a bbappend.
SRC_URI = " git://github.com/nxp-imx/linux-imx.git;protocol=https;branch=${SRCBRANCH} \
            file://0000-patch_kernel_5.10.72_1.0.7.patch \
            file://0001-imx8mp-owa5x.dts-Disabled-hdmi.patch \
            file://0002-owa5x_config.OWA-Added-can-ISOTP.patch \
            file://0003-new-eMMC-and-LAN8710.patch \
            file://0004-LED_TRIGGERS-Added-several.patch \
            file://0005-owa5x_config.OWA-BPF-for-docker-installation.patch \
            file://0006-owa5x_config.OWA-Bosch-Iptables.patch \
            file://0007-owa5x_config.OWA-Wireguard.patch \
            file://0008-owa5x_config.OWA-IPVLAN-Azure.patch \
            file://0009-owa5x_config.OWA-Bridge-netfilter.patch \
            file://0010-owa5x_config.OWA-sdma-driver.patch \
            file://0011-V1.0.8_Changes_in_readme.txt.patch \
            file://0012-Remove_error_caam.patch \
            file://0013-UBI_FAST_MAP.patch \
            file://0014-Changeg-.gitignore.patch \
            file://0015-qReapply-.gitignore.patch \
            file://0016-Set-release-version-1.0.8-rc0.patch \
            file://0017-Update-readme.txt.patch \
            file://0018-owa5x_config.OWA-added-verity.patch \
            file://0019-V1.0.8-rc1.-Add-USB_NET_CDC_MBIM.patch \
"

LINUX_VERSION = "5.10.72"
SRCREV = "c59614bdd6f6b288a42cebda186f37da87968990"
SRCBRANCH = "lf-5.10.y"
LOCALVERSION = "-2.2.2"
COMPATIBLE_MACHINE = "(owa5x)"
KBUILD_DEFCONFIG ?= ""
KBUILD_DEFCONFIG:owa5x= "defconfig"

#KERNEL_CONFIG_COMMAND = "oe_runmake_call ${PARALLEL_MAKE} -C ${S} CC="${KERNEL_CC}" O=${B} ${KBUILD_DEFCONFIG:owa5x}"

# Deploy symbols to allow for device tree overlays
EXTRA_OEMAKE += "DTC_FLAGS=-@ "

KERNEL_MODULE_AUTOLOAD += " owa5x_gpio "

do_patch:append(){
    if [ -e .config ]; then
        rm .config
    fi
    bbnote "Copying Owasys Defconfig from do_configure:prepend()"
    cp ${S}/owa5x_config.OWA ${S}/arch/arm64/configs/defconfig
}

#Create a symbolic link to the dtb so uboot script is able to boot keeping more flexibility for differents dtbs.
do_install:append(){
    install -d ${D}/boot
    cd ${D}/boot
    ln -s imx8mp-owa5x.dtb devicetree.dtb
}


