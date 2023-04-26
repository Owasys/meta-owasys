DESCRIPTION = " This service can be used to wait for the pmsrv service in charge of IOs and Power Management \
                to be ready in the system, \
                which is detected with the existence of owaapi.lck. "
SECTION = "Binaries"
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

inherit systemd

SRC_URI = " file://owasys-checklock.sh \
            file://owasysd-pmsrv-ready.service \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="owasysd-pmsrv-ready.service"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/owasys-checklock.sh ${D}${bindir}

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/owasysd-pmsrv-ready.service ${D}/${systemd_unitdir}/system

}

RDEPENDS:system-maintenace ?= "bash"
