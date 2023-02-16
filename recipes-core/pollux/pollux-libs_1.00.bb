LICENSE = "CLOSED"
RDEPENDS:${PN} += " dbus libev "
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = " file://libpollux.so \
            file://owa5x_an12 \
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

  install -d ${D}${bindir}
  install -d ${D}${libdir}
  install -d ${D}${sysconfdir}/pollux
  install -d ${D}${sysconfdir}/dbus-1/system.d
  install -d ${D}${sysconfdir}/systemd/system
  
  install ${WORKDIR}/pollux-dbus.json ${D}${sysconfdir}/pollux/
  install -m 0755 ${WORKDIR}/owa5x_an12       ${D}${bindir}
  # create alias for this tool
  ln -s ${bindir}/owa5x_an12    ${D}${bindir}/owasys-an12
  install ${WORKDIR}/libpollux.so     ${D}${libdir}

  # create symbolic links from /usr/lib/libhiredis.0.14 to /usr/lib/libhiredis.1.0.0

    install -d ${D}/${nonarch_base_libdir}
    ln -s ${libdir}/libhiredis.so.1.0.0    ${D}/${nonarch_base_libdir}/libhiredis.so.0.14
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
