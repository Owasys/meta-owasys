DESCRIPTION = "Binary Start_BT_WiFi"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://Start_BT_WiFi \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/Start_BT_WiFi ${D}${bindir}
    # create alias for this tool
    install -d ${D}/${base_bindir}
    ln -s ${bindir}/Start_BT_WiFi    ${D}${base_bindir}/owasys_start_bt_wifi
    
}