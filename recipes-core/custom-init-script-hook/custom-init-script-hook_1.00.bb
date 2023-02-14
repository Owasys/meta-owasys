DESCRIPTION = "Recipe to handle hw.json file"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

inherit systemd

SRC_URI = ""

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {

}

RDEPENDS:system-maintenace ?= "bash"
