DESCRIPTION = "Create file containing owasys SN at tmp"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

inherit systemd

SRC_URI = " file://owasys-hw-sn-file.sh \
            file://owasys-hw-sn-file.service \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="owasys-hw-sn-file.service"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/owasys-hw-sn-file.sh ${D}${bindir}

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/owasys-hw-sn-file.service ${D}/${systemd_unitdir}/system

}

RDEPENDS:system-maintenace ?= "bash"
