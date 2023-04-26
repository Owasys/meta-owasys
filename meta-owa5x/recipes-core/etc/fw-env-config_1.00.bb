LICENSE = "CLOSED"

SRC_URI = " file://fw_env.config "

do_install() {
  install -m 0755 -d ${D}${sysconfdir}
  install ${WORKDIR}/fw_env.config ${D}${sysconfdir}
}