DESCRIPTION = "mlanutl - configure the additional parameters available for NXP mdriver"
SECTION = "Binaries"
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"
SRC_URI = "file://mlanutl \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    
    # install the application into the /usr/bin folder with default permissions
    install -m 0755 ${WORKDIR}/mlanutl ${D}${bindir}
}