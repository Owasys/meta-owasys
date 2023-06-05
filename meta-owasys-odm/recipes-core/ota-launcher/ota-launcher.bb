LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

inherit systemd

RDEPENDS:${PN} += " pollux-libs "

SRC_URI = " file://ota-launcher \
            file://ota-launcher.service \
"

INSANE_SKIP:${PN} += "already-stripped dev-so"
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="ota-launcher.service"

do_install() {

  install -d ${D}${bindir}
  install -d ${D}${sysconfdir}/ota-launcher
  install -d ${D}${sysconfdir}/systemd/system

  install -m 0755 ${WORKDIR}/ota-launcher           ${D}${bindir}
  install ${WORKDIR}/ota-launcher.service           ${D}${sysconfdir}/systemd/system

}

FILES:${PN} += " \
  ${bindir}/ota-launcher \
  ${sysconfdir}/systemd/system/ota-launcher.service \
"

RPROVIDES:${PN} += " \
                    libz.so.1()(64bit) \
"