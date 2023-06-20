LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

inherit systemd

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI = " file://owasysd-measured-boot.service \
            file://measured-boot-operations.sh \
            file://create-provision-keys.sh \
"
RDEPENDS:${PN} += "bash"
SYSTEMD_SERVICE:${PN} += "owasysd-measured-boot.service "
SYSTEMD_AUTO_ENABLE = "enable"

do_install () {

        install -d ${D}${systemd_unitdir}/system/
        install -m 0644 ${WORKDIR}/owasysd-measured-boot.service ${D}${systemd_unitdir}/system/

        install -d ${D}${bindir}
        install -m 0755 ${WORKDIR}/create-provision-keys.sh ${D}${bindir}
        install -m 0755 ${WORKDIR}/measured-boot-operations.sh ${D}${bindir}

}

FILES:${PN} += "\
  ${systemd_unitdir}/system/owasysd-measured-boot.service \
  ${bindir}/measured-boot-operations.sh \
"