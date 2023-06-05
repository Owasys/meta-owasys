LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

inherit systemd

RDEPENDS:${PN} += " pollux-libs "

SRC_URI = " file://odm-edge \
            file://odm-edge.json \
            file://odm-edge.service \
"

INSANE_SKIP:${PN} += "already-stripped dev-so"
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="odm-edge.service"

do_install() {

  if ![ -d "${D}${sysconfdir}/odm-edge" ]; then
    bbnote " /etc/odm-edge directory doesn't exist, creating it..."
    install -m 0755 -d ${D}${sysconfdir}/odm-edge
    mkdir ${D}${sysconfdir}/odm-edge
  fi

  install -d ${D}${bindir}
  install -d ${D}${sysconfdir}/odm-edge
  install -d ${D}${sysconfdir}/systemd/system

  install -m 0755 ${WORKDIR}/odm-edge           ${D}${bindir}
  install ${WORKDIR}/odm-edge.service           ${D}${sysconfdir}/systemd/system
  install ${WORKDIR}/odm-edge.json              ${D}${sysconfdir}/odm-edge

}

FILES:${PN} += " \
  ${bindir}/odm-edge \
  ${bindir}/odm-edge.json \
  ${sysconfdir}/systemd/system/odm-edge.service \
"

RPROVIDES:${PN} += " \
                    libz.so.1()(64bit) \
"
