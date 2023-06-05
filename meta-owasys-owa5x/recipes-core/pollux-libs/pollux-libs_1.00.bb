LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"

RDEPENDS:${PN} += " dbus libev "
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = " file://libpollux.so \
            file://pollux-dbus.json \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped dev-so"

SOLIBS = ".so"
FILES_SOLIBSDEV = ""

do_install() {

  if ![ -d "${D}${sysconfdir}/pollux" ]; then
    bbnote " /etc/pollux directory doesn't exist, creating it..."
    install -m 0755 -d ${D}${sysconfdir}/pollux
    mkdir ${D}${sysconfdir}/pollux
  fi

  install -d ${D}${libdir}
  install -d ${D}${sysconfdir}/pollux
  install -d ${D}${sysconfdir}/dbus-1/system.d
  install -d ${D}${sysconfdir}/systemd/system
  
  install ${WORKDIR}/pollux-dbus.json ${D}${sysconfdir}/pollux/
  install ${WORKDIR}/libpollux.so     ${D}${libdir}

}



FILES:${PN} += " \
  ${sysconfdir}/pollux/pollux-dbus.json \
  ${libdir}/libpollux.so \
  ${nonarch_base_libdir}/* \
"

RPROVIDES:${PN} += " \
                    libpollux.so()(64bit) \
                    libhiredis.so.0.14()(64bit) \
                    libdbus-1.so.3()(64bit) \
                    libdbus-1.so.3(LIBDBUS_1_3)(64bit) \
"
