DESCRIPTION = "udev rules for owa5X device"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " file://50-hidraw.rules \
            file://50-spi.rules \
            file://70-persistent-net.rules \
            file://tisdk.rules \
			file://ubi.rules \
"

S = "${WORKDIR}"

do_install () {
	install -d ${D}${sysconfdir}/udev/rules.d
	install -m 0644 ${WORKDIR}/50-hidraw.rules ${D}${sysconfdir}/udev/rules.d/
   	install -m 0644 ${WORKDIR}/50-spi.rules ${D}${sysconfdir}/udev/rules.d/
	install -m 0644 ${WORKDIR}/70-persistent-net.rules ${D}${sysconfdir}/udev/rules.d/
	install -m 0644 ${WORKDIR}/tisdk.rules ${D}${sysconfdir}/udev/rules.d/
	install -m 0644 ${WORKDIR}/ubi.rules ${D}${sysconfdir}/udev/rules.d/
}
