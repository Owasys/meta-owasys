LICENSE = "CLOSED"
inherit systemd

RDEPENDS:${PN} += " dbus libev "

SRC_URI = " file://gprs.net \
            file://libpollux.so \
            file://net.json \
            file://owa5x_an12 \
            file://pollux-dbus.json \
            file://pollux-net \
            file://pollux-net.conf \
            file://polluxnet.service \
            file://owa5x_an12 \
"
INSANE_SKIP:${PN} += "already-stripped dev-so"
SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} ="polluxnet.service"

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
#  install -d ${D}/var/log/pollux
  
  install -m 0644 ${WORKDIR}/polluxnet.service ${D}${sysconfdir}/systemd/system/
  install ${WORKDIR}/pollux-net.conf  ${D}${sysconfdir}/dbus-1/system.d/
  install ${WORKDIR}/pollux-dbus.json ${D}${sysconfdir}/pollux/
  install ${WORKDIR}/net.json         ${D}${sysconfdir}/pollux/
  install ${WORKDIR}/gprs.net         ${D}${sysconfdir}/pollux/
  install -m 0755 ${WORKDIR}/pollux-net       ${D}${bindir}
  install -m 0755 ${WORKDIR}/owa5x_an12       ${D}${bindir}
  install ${WORKDIR}/libpollux.so     ${D}${libdir}
}

FILES:${PN} += " \
  ${sysconfdir}/dbus-1/system.d/pollux-net.conf \
  ${sysconfdir}/pollux/pollux-dbus.json \
  ${sysconfdir}/pollux/net.json \
  ${sysconfdir}/pollux/gprs.net \
  ${bindir}/pollux-net \
  ${sysconfdir}/systemd/system/polluxnet.service \
  ${libdir}/libpollux.so \
"

RPROVIDES:${PN} += " \
                    libpollux.so()(64bit) \
                    libhiredis.so.0.14()(64bit) \
                    libdbus-1.so.3()(64bit) \
                    libdbus-1.so.3(LIBDBUS_1_3)(64bit) \
                    libmnl.so.0(LIBMNL_1.0)(64bit) \
                    libmnl.so.0()(64bit) \
"
