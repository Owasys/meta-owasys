DESCRIPTION = "Binary Start_CAN"
SECTION = "Binaries"
DEPENDS = " owasys-libs "
RDEPENDS:${PN} += " owasys-libs "
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"
SRC_URI = "file://Start_CAN \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    
    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/Start_CAN ${D}${bindir}
    # create alias for this tool
    install -d ${D}/${base_bindir}
    ln -s ${bindir}/Start_CAN    ${D}${base_bindir}/owasys-can
}