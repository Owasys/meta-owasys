LICENSE = "CLOSED"

SRC_URI = " file://issue.owa "

do_install() {
  install -m 0755 -d ${D}${sysconfdir}
  install ${WORKDIR}/issue.owa ${D}${sysconfdir}
}