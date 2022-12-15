DESCRIPTION = "Binary Switch_GSM"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://Switch_GSM \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/Switch_GSM ${D}${bindir}
}


RPROVIDES:${PN} += " \
                    libudev.so.1(LIBUDEV_183)(64bit) \
                    libudev.so.1()(64bit) \
                    libRTU_Module.so()(64bit) \
                    libIOs_Module.so()(64bit) "