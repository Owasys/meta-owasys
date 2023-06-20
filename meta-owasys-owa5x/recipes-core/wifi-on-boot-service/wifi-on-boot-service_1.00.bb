DESCRIPTION = "Systemd services used for powering up Wifi/BLE module on boot using Owasys tools."
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
inherit systemd

RDEPENDS:${PN} += "bash"
SYSTEMD_AUTO_ENABLE = "disable"
SYSTEMD_SERVICE:${PN} ="owasysd-wifi-on-boot.service"

SRC_URI:append = " file://owasysd-wifi-on-boot.service "

do_install () {
   install -d ${D}${sysconfdir}/systemd/system
   install -m 644 ${WORKDIR}/owasysd-wifi-on-boot.service ${D}${sysconfdir}/systemd/system
}

SYSTEMD_SERVICE:${PN} = "owasysd-wifi-on-boot.service"