DESCRIPTION = "Add the folder /device in the root folder directory to be used as the mounting point for the eMMC memory"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
COMPATIBLE_MACHINE = "(owa5x)"

SRC_URI = " \
        file://package.json \
"

do_install() {


    if ![ -d "${D}/device/odm" ]; then
        bbnote " /device/odm directory doesn't exist, creating it..."
        mkdir ${D}/device/odm
    fi

    # Create the folder device in the rootfs
    install -m 0755 -d ${D}/device/odm
    install -m 0644 ${WORKDIR}/package.json ${D}/device/odm/

}

FILES:${PN} += "/device"