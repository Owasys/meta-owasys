DESCRIPTION = "Binary owa5X application note 24"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = "file://owa5x_AN24 \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/owa5x_AN24 ${D}${bindir}
    # create alias for this tool
    install -d ${D}/${base_bindir}
    ln -s ${bindir}/owa5x_AN24    ${D}${base_bindir}/owasys-an24
}


RPROVIDES:${PN} += " \
                    libRTU_Module.so()(64bit) \
                    libIOs_Module.so()(64bit) \
                    libGSM_Module.so()(64bit) \
                    libINET_Module.so()(64bit) "                    