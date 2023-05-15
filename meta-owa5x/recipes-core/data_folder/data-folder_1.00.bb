DESCRIPTION = "Add the folder /data in the root folder directory to be used as the mounting point for the eMMC memory"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
COMPATIBLE_MACHINE = "(owa5x)"

do_install() {

# Create the folder data in the rootfs
    install -d ${D}/data

}

FILES:${PN} += "/data"