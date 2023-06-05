LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = " file://owasysd-boot-check.service \
                   file://owasysd-boot-check.timer \
                   file://check-boot-operations.sh \
"
RDEPENDS:${PN} += "bash"
SYSTEMD_SERVICE:${PN} += "owasysd-boot-check.service "
SYSTEMD_AUTO_ENABLE = "disable"

do_install:append () {

        install -d ${D}${systemd_unitdir}/system/
        install -m 0644 ${WORKDIR}/owasysd-boot-check.service ${D}${systemd_unitdir}/system/
        install -m 0644 ${WORKDIR}/owasysd-boot-check.timer ${D}${systemd_unitdir}/system/

        # Enables the timer
        install -d ${D}${sysconfdir}/systemd/system/timers.target.wants
        ln -s -r ${D}${systemd_unitdir}/system/owasysd-boot-check.timer ${D}${sysconfdir}/systemd/system/timers.target.wants/owasysd-boot-check.timer

        install -d ${D}${bindir}
        install -m 0755 ${WORKDIR}/check-boot-operations.sh ${D}${bindir}

}

FILES:${PN} += "\
  ${systemd_unitdir}/system/owasysd-boot-check.service \
  ${systemd_unitdir}/system/owasysd-boot-check.timer \
  ${bindir}/check-boot-operations.sh \
"