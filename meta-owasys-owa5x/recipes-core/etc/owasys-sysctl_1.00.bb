LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

SRC_URI = " file://sysctl.conf \
"
do_install() {

  #install fstab
  install -m 0755 -d ${D}${sysconfdir}
  install ${WORKDIR}/sysctl.conf ${D}${sysconfdir}/
  
}


FILES_${PN} += "${sysconfdir}/sysctl.conf"