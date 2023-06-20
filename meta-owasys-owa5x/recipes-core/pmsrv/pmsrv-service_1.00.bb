LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
inherit systemd

DEPENDS += " \
            pmsrv \
"
RDEPENDS:${PN} += "\
			      pmsrv \
"

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="pmsrv.service"

SRC_URI:append = " file://pmsrv.service "
FILES:${PN} += "${sysconfdir}/systemd/pmsrv.service"

do_install:append() {
  install -d ${D}${sysconfdir}/systemd/system
  install -m 0644 ${WORKDIR}/pmsrv.service ${D}${sysconfdir}/systemd/system
}