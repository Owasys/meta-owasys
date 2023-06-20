LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

DEPENDS += ""
RDEPENDS:${PN} += ""

SRC_URI = " file://gsm "

do_install() {
  install -m 0755 -d ${D}${sysconfdir}/chatscripts
  install ${WORKDIR}/gsm ${D}${sysconfdir}/chatscripts
}