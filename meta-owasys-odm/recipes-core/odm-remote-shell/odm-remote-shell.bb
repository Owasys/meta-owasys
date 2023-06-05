LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

inherit systemd

RDEPENDS:${PN} += " pollux-libs "

SRC_URI = " file://odm-remote-shell \
            file://odm-remote-shell.service \
"

INSANE_SKIP:${PN} += "already-stripped dev-so"
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="odm-remote-shell.service"

do_install() {

  install -d ${D}${bindir}
  install -d ${D}${sysconfdir}/odm-remote-shell
  install -d ${D}${sysconfdir}/systemd/system

  install -m 0755 ${WORKDIR}/odm-remote-shell           ${D}${bindir}
  install ${WORKDIR}/odm-remote-shell.service           ${D}${sysconfdir}/systemd/system
}

FILES:${PN} += " \
  ${bindir}/odm-remote-shell \
  ${sysconfdir}/systemd/system/odm-remote-shell.service \
"

RPROVIDES:${PN} += " \
                    libz.so.1()(64bit) \
"