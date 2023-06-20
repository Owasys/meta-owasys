DEPENDS = "zlib-native openssl-native"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"


SRC_URI = " git://github.com/nxp-imx/imx-mkimage.git;protocol=https;branch=${SRCBRANCH} \
            file://0001-Changed-dtb-name-in-soc.mak.patch \
            file://lpddr4_pmu_train_1d_dmem_202006.bin \
            file://lpddr4_pmu_train_1d_imem_202006.bin \
            file://lpddr4_pmu_train_2d_dmem_202006.bin \
            file://lpddr4_pmu_train_2d_imem_202006.bin \            
"
SRCBRANCH = "imx_5.4.70_2.3.0"
SRCREV = "8947fea369ab3932259630232cfb9f87b8f9dda1"
S = "${WORKDIR}/git"

BOOT_TOOLS = "imx-boot-tools"
SYSROOT_DIRS += "/boot"
