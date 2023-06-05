DESCRIPTION = "Systemd services used for powering up Wifi/BLE module on boot using Owasys tools."
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
inherit systemd

RDEPENDS:${PN} += "bash"
SYSTEMD_AUTO_ENABLE = "disable"
SYSTEMD_SERVICE:${PN} ="owasysd-timesync.service"

SRC_URI:append = " file://owasysd-timesync.service \ 
                   file://owasysd-timesync.timer \
                   file://owasys-timesync.sh \
"

do_install () {

   install -d ${D}${bindir}
   install -d ${D}${sysconfdir}/systemd/system
   
   install -m 644 ${WORKDIR}/owasysd-timesync.service ${D}${sysconfdir}/systemd/system
   install -m 644 ${WORKDIR}/owasysd-timesync.timer   ${D}${sysconfdir}/systemd/system
   install -m 755 ${WORKDIR}/owasys-timesync.sh      ${D}${bindir}

}

SYSTEMD_SERVICE:${PN} = "owasysd-timesync.service"