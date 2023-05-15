DESCRIPTION = "Create file containing owasys SN at tmp"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

inherit systemd

SRC_URI = " file://owasys-hw-sn-file.sh \
            file://owasysd-hw-sn-file.service \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="owasysd-hw-sn-file.service"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/owasys-hw-sn-file.sh ${D}${bindir}

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/owasysd-hw-sn-file.service ${D}/${systemd_unitdir}/system

}

RDEPENDS:system-maintenace ?= "bash"
