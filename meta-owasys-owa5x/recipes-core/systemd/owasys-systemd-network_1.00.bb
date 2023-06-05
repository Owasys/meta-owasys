LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

SRC_URI = " file://eth0.network \
            file://eth1.network \
"
do_install() {

  #install eth*
  install -m 0755 -d ${D}${sysconfdir}
  install -d ${D}${sysconfdir}/systemd/network
  
  install ${WORKDIR}/eth0.network ${D}${sysconfdir}/systemd/network/
  install ${WORKDIR}/eth1.network ${D}${sysconfdir}/systemd/network/
  
}


FILES_${PN} += "  ${sysconfdir}/systemd/network/eth0.network \
                  ${sysconfdir}/systemd/network/eth1.network \
"