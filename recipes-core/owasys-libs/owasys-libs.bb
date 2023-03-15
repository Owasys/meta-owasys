DESCRIPTION = "Shared libraries needed to control GPS, GSM, etc"
SECTION = "Binaries"
DEPENDS = " alsa-lib"
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"
COMPATIBLE_MACHINE = "(owa5x)"

SRC_URI = " file://libFMS_Module.so.1.1.4 \
            file://libGPS2_Module.so.1.0.16 \
            file://libGSM_Module.so.1.0.19 \
            file://libINET_Module.so.1.0.5 \
            file://libIOs_Module.so.1.0.16 \
            file://libRTU_Module.so.1.0.18 \
            file://FMS_Defs.h \
            file://GPS2_ModuleDefs.h \
            file://GSM_ModuleDefs.h \
            file://INET_ModuleDefs.h \
            file://IOs_ModuleDefs.h \
            file://owa5x_gpio.h \
            file://owcomdefs.h \
            file://owerrors.h \
            file://pm_messages.h \
            file://RTUControlDefs.h \
"

S = "${WORKDIR}"

INSANE_SKIP:${PN} += "already-stripped dev-so"
FILES:${PN} += " \
        ${libdir}/* \
        ${nonarch_base_libdir}/* \
"
SOLIBS = ".so"
FILES_SOLIBSDEV = ""

do_install() {
    # create the /lib/ folder in the rootfs with default permissions
    install -d ${D}${libdir}/owasys

    # install the application into the /lib/ folder with default permissions
    install ${WORKDIR}/libFMS_Module.so.1.1.4 ${D}${libdir}/owasys
    install ${WORKDIR}/libGPS2_Module.so.1.0.16 ${D}${libdir}/owasys
    install ${WORKDIR}/libGSM_Module.so.1.0.19 ${D}${libdir}/owasys
    install ${WORKDIR}/libINET_Module.so.1.0.5 ${D}${libdir}/owasys
    install ${WORKDIR}/libIOs_Module.so.1.0.16 ${D}${libdir}/owasys
    install ${WORKDIR}/libRTU_Module.so.1.0.18 ${D}${libdir}/owasys

    # create symbolic links from /usr/lib/owasys to /lib/

    install -d ${D}/${nonarch_base_libdir}
    ln -s ${libdir}/owasys/libFMS_Module.so.1.1.4     ${D}/${nonarch_base_libdir}/libFMS_Module.so
    ln -s ${libdir}/owasys/libGPS2_Module.so.1.0.16   ${D}/${nonarch_base_libdir}/libGPS2_Module.so
    ln -s ${libdir}/owasys/libGSM_Module.so.1.0.19    ${D}/${nonarch_base_libdir}/libGSM_Module.so
    ln -s ${libdir}/owasys/libINET_Module.so.1.0.5    ${D}/${nonarch_base_libdir}/libINET_Module.so
    ln -s ${libdir}/owasys/libIOs_Module.so.1.0.16    ${D}/${nonarch_base_libdir}/libIOs_Module.so
    ln -s ${libdir}/owasys/libRTU_Module.so.1.0.18    ${D}/${nonarch_base_libdir}/libRTU_Module.so

#****************************** HEADERS SECTION**************************************

    install -d ${D}${includedir}/owa5x

    # create the /lib/ folder in the rootfs with default permissions
    mkdir -p ${D}${includedir}/owa5x
    install -m 0755 -d ${D}${includedir}/owa5x

    # install the application into the /lib/ folder with default permissions
    install ${WORKDIR}/*.h ${D}${includedir}/owa5x

}

RPROVIDES:${PN} += " \
                    libudev.so.1(LIBUDEV_183)(64bit) \
                    libudev.so.1()(64bit) \
                    libRTU_Module.so()(64bit) \
                    libIOs_Module.so()(64bit) "
