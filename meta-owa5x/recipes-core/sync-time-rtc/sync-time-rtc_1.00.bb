DESCRIPTION = "Recipe to let system get date out from the RTC"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

inherit systemd

SRC_URI = " file://sync-time-rtc.sh \
            file://sync-time-rtc.service \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="sync-time-rtc.service"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/sync-time-rtc.sh  ${D}${bindir}

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/sync-time-rtc.service ${D}/${systemd_unitdir}/system

}

RDEPENDS:system-maintenace ?= "bash"
