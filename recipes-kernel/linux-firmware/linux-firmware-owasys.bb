SUMMARY = "Linux fimware for the Bluetooth/wifi module Ublox Jody-W263"

LICENSE = "CLOSED"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# Firmware for Ublox Jody-W263A Wifi/BLE module
SRC_URI = " file://sdsd8987_combo.bin \
            file://sd8xxx.conf \
            "

S = "${WORKDIR}"

do_install() {

    install -d ${D}${sysconfdir}/firmware
 
    # Install Ublox JODY-W263A firmware binary in /lib/firmware/nxp/
    install -d ${D}${nonarch_base_libdir}/firmware/nxp
    install ${WORKDIR}/sdsd8987_combo.bin    ${D}${nonarch_base_libdir}/firmware/nxp/

    # Install Ublox JODY-W263A driver configuration file in /etc/modprobe.d/
    install -m 0755 -d ${D}${sysconfdir}/modprobe.d
    install -m 0644 ${WORKDIR}/sd8xxx.conf  ${D}${sysconfdir}/modprobe.d/

}

FILES:${PN} += " \
                ${nonarch_base_libdir}/firmware/nxp/sdsd8987_combo.bin \
                ${sysconfdir}/modprobe.d/sd8xxx.conf \
"