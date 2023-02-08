DESCRIPTION = "Binary OwaStandby"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://OwaStandby \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/OwaStandby ${D}${bindir}
    # create alias for this tool
    install -d ${D}/${base_bindir}
    ln -s ${bindir}/OwaStandby    ${D}${base_bindir}/owasys_owastandby
}