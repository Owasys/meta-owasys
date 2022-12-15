DESCRIPTION = "Binary Quectel connection manager"
SECTION = "Binaries"
DEPENDS = " owasys-libs "
RDEPENDS:${PN} += " owasys-libs "
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"
SRC_URI = "file://quectel-CM \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    
    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/quectel-CM ${D}${bindir}
}