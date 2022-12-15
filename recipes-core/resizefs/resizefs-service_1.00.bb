LICENSE = "CLOSED"
inherit systemd

RDEPENDS:${PN} += "bash"
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="resizefs.service"

SRC_URI:append = " \
  file://resizefs.service \
  file://expand_data_partitions.sh \
"

do_install:append() {
  install -d ${D}${bindir}
  install -d ${D}${sysconfdir}/systemd/system
  
  install -m 0644 ${WORKDIR}/resizefs.service ${D}${sysconfdir}/systemd/system
  install -m 0755 ${WORKDIR}/expand_data_partitions.sh ${D}${bindir}
}

FILES:${PN} += "${sysconfdir}/systemd/resizefs.service"
