LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

RDEPENDS:${PN} += "bash"

SRC_URI:append = " \
  file://generic-startup.sh \
"

do_install:append() {
  install -d ${D}${bindir}
    
  install -m 0755 ${WORKDIR}/generic-startup.sh ${D}${bindir}
}

FILES:${PN} += "${bindir}/generic-startup.sh"
