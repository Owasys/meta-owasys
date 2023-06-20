DESCRIPTION = "Recipe to handle hw.json file"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

inherit systemd

SRC_URI = " file://hwfile_create.sh \
            file://hwvar_create.sh \
            file://uboot_check.sh \
            file://manage-hw-file.service \
            file://manage-hw-file.sh \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="manage-hw-file.service"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/manage-hw-file.sh ${D}${bindir}
    install ${WORKDIR}/hwfile_create.sh ${D}${bindir}
    install ${WORKDIR}/hwvar_create.sh ${D}${bindir}
    install ${WORKDIR}/uboot_check.sh ${D}${bindir}

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/manage-hw-file.service ${D}/${systemd_unitdir}/system
}

RDEPENDS:system-maintenace ?= "bash"
