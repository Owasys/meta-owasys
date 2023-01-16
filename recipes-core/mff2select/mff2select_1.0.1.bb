DESCRIPTION = "Binary Mff2_select which is a tool for choosing between SIM and eSIM."
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://Mff2_Select \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/Mff2_Select ${D}${bindir}
}

RPROVIDES:${PN} += " \
                    libRTU_Module.so()(64bit) \
                    libIOs_Module.so()(64bit) "