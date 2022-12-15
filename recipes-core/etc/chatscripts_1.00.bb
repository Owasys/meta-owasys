LICENSE = "CLOSED"

DEPENDS += ""
RDEPENDS:${PN} += ""

SRC_URI = " file://gsm "

do_install() {
  install -m 0755 -d ${D}${sysconfdir}/chatscripts
  install ${WORKDIR}/gsm ${D}${sysconfdir}/chatscripts
}