DESCRIPTION = "Systemd services used for powering up Wifi/BLE module on boot using Owasys tools."
LICENSE = "CLOSED"
inherit systemd

RDEPENDS:${PN} += "bash"
SYSTEMD_AUTO_ENABLE = "disable"
SYSTEMD_SERVICE:${PN} ="owasysd-wifi-on-boot.service"

SRC_URI:append = " file://owasysd-wifi-on-boot.service "

do_install () {
   install -d ${D}/${systemd_unitdir}/system
   install -m 644 ${WORKDIR}/owasysd-wifi-on-boot.service ${D}/${systemd_unitdir}/system
}

SYSTEMD_SERVICE:${PN} = "owasysd-wifi-on-boot.service"