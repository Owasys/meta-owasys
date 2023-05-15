DESCRIPTION = "Binaries to flash the ST32 which controls peripherals such as GSM module, WIFI module, etc"
SECTION = "Binaries"
DEPENDS = " owasys-libs "
RDEPENDS:${PN} += " owasys-libs "
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"
SRC_URI = " file://owa5x.bin \
            file://owa5x_l.bin \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    
    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/owa5x.bin ${D}${bindir}
    install ${WORKDIR}/owa5x_l.bin ${D}${bindir}
}
