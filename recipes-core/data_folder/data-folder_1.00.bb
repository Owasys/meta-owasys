DESCRIPTION = "Add the folder /data in the root folder directory to be used as the mounting point for the eMMC memory"
LICENSE = "CLOSED"
COMPATIBLE_MACHINE = "(owa5x)"

do_install() {

# Create the folder data in the rootfs
    install -d ${D}/data

}

FILES:${PN} += "/data"