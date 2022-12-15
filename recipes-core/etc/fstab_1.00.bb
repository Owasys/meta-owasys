LICENSE = "CLOSED"

SRC_URI = " file://fstab \
"
do_install() {

  #install fstab
  install -m 0755 -d ${D}${sysconfdir}
  install ${WORKDIR}/fstab ${D}${sysconfdir}/
  
}


FILES_${PN} += "${sysconfdir}/fstab"