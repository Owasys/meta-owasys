DESCRIPTION = "Binary Test_owa5x"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://Test_owa5x \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/Test_owa5x ${D}${bindir}
    # create alias for this tool
    install -d ${D}/${base_bindir}
    ln -s ${bindir}/Test_owa5x    ${D}${base_bindir}/owasys_test_owa5x
}