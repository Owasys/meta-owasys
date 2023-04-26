DESCRIPTION = "Binary for system_maintenance.sh"
SECTION = "Binaries"
DEPENDS = ""
LICENSE = "CLOSED"
FILESEXTRAPATHS:prepend := "${THISDIR}/src:"

SRC_URI = " file://system_maintenance.sh \
            file://hwfile_create.sh \
            file://hwvar_create.sh \
            file://uboot_check.sh \
"

S = "${WORKDIR}"
RDEPENDS:${PN} += "bash"

INSANE_SKIP:${PN} += "already-stripped"

do_install() {
    # create the /usr/bin folder in the rootfs with default permissions
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}

    # install the application into the /usr/bin folder with default permissions
    install ${WORKDIR}/system_maintenance.sh ${D}${bindir}
    install ${WORKDIR}/hwfile_create.sh ${D}${bindir}
    install ${WORKDIR}/hwvar_create.sh ${D}${bindir}
    install ${WORKDIR}/uboot_check.sh ${D}${bindir}
}

RDEPENDS:system-maintenace ?= "bash"
