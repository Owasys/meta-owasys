LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = " file://libcrypto.so.1.1 "

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped dev-so"

SOLIBS = ".so"
FILES_SOLIBSDEV = ""

do_install() {

  install -d ${D}${libdir}
  install ${WORKDIR}/libcrypto.so.1.1     ${D}${libdir}

}


FILES:${PN} += " \
  ${libdir}/libcrypto.so.1.1 \
"