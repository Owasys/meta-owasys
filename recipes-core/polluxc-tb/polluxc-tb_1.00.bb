LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

inherit systemd

RDEPENDS:${PN} += " dbus libev pollux-libs "

SRC_URI = " file://pollux.target \
            file://polluxc-tb \
            file://polluxc-tb.conf \
            file://polluxc-tb.service \
            file://tb_attributes.conf \
            file://tb_attributes.service \
            file://tb_commands.conf \
            file://tb_commands.service \
            file://tb.json \
            file://wakeup-reason.service \
            file://owasys_chain.pem \
"
INSANE_SKIP:${PN} += "already-stripped dev-so"
SYSTEMD_AUTO_ENABLE = "disable"
SYSTEMD_SERVICE:${PN} ="polluxc-tb.service"

SOLIBS = ".so"
FILES_SOLIBSDEV = ""

do_install() {

  if ![ -d "${D}${sysconfdir}/pollux" ]; then
    bbnote " /etc/pollux directory doesn't exist, creating it..."
    install -m 0755 -d ${D}${sysconfdir}/pollux
    mkdir ${D}${sysconfdir}/pollux
  fi

  if ![ -d "${D}${sysconfdir}/systemd/system/pollux.target.wants" ]; then
    bbnote " pollux.target.wants directory doesn't exist, creating it..."
    install -m 0755 -d ${D}${sysconfdir}/systemd/system/pollux.target.wants
  fi

  install -d ${D}${bindir}
  install -d ${D}${sysconfdir}/pollux
  install -d ${D}${sysconfdir}/dbus-1/system.d
  install -d ${D}${sysconfdir}/ssl/certs
  install -d ${D}${sysconfdir}/systemd/system/pollux.target.wants

  install ${WORKDIR}/owasys_chain.pem             ${D}${sysconfdir}/ssl/certs
  install ${WORKDIR}/pollux.target                ${D}${sysconfdir}/systemd/system
  install ${WORKDIR}/polluxc-tb.service           ${D}${sysconfdir}/systemd/system
  install ${WORKDIR}/tb_attributes.service        ${D}${sysconfdir}/systemd/system
  install ${WORKDIR}/tb_commands.service          ${D}${sysconfdir}/systemd/system
  install ${WORKDIR}/polluxc-tb.conf              ${D}${sysconfdir}/dbus-1/system.d/
  install ${WORKDIR}/tb.json                      ${D}${sysconfdir}/pollux/
  install ${WORKDIR}/tb_attributes.conf           ${D}${sysconfdir}/pollux/
  install ${WORKDIR}/tb_commands.conf             ${D}${sysconfdir}/pollux/
  install -m 0755 ${WORKDIR}/polluxc-tb           ${D}${bindir}

  ln -s -r ${D}${sysconfdir}/systemd/system/polluxc-tb.service           ${D}${sysconfdir}/systemd/system/pollux.target.wants/polluxc-tb.service
  ln -s -r ${D}${sysconfdir}/systemd/system/tb_attributes.service        ${D}${sysconfdir}/systemd/system/pollux.target.wants/tb_attributes.service
  ln -s -r ${D}${sysconfdir}/systemd/system/tb_commands.service          ${D}${sysconfdir}/systemd/system/pollux.target.wants/tb_commands.service

}

FILES:${PN} += " \
  ${sysconfdir}/dbus-1/system.d/polluxc-tb.conf \
  ${sysconfdir}/pollux/tb.json   \
  ${sysconfdir}/pollux/tb_attributes.conf \
  ${sysconfdir}/pollux/tb_commands.conf \
  ${bindir}/polluxc-tb \
  ${sysconfdir}/systemd/system/polluxc-tb.service \
  ${sysconfdir}/systemd/system/pollux.target \
  ${sysconfdir}/systemd/system/tb_attributes.service  \
  ${sysconfdir}/systemd/system/tb_commands.service  \
"

RPROVIDES:${PN} += " \
                    libpollux.so()(64bit) \
                    libhiredis.so.0.14()(64bit) \
                    libdbus-1.so.3()(64bit) \
                    libdbus-1.so.3(LIBDBUS_1_3)(64bit) \
                    libmnl.so.0(LIBMNL_1.0)(64bit) \
                    libmnl.so.0()(64bit) \
                    libcrypto.so.1.1()(64bit) \
                    libpaho-mqtt3as.so.1()(64bit) \
                    libcrypto.so.1.1(OPENSSL_1_1_0)(64bit) \
"
