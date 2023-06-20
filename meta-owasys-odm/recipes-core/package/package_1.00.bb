SUMMARY = "ODM packet identification file"
DESCRIPTION = "The /etc/odm/pakcage.json file contains packet identification data."
INHIBIT_DEFAULT_DEPS = "1"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM ="file://${COMPANY_CUSTOM_LICENSES}/OWASYS_Propietary_SW_License_Agreement.md;md5=203a753c44e11367199c31c2168fa959"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += " \
        file://package.json \
"

PACKAGE_FIELDS = "\
    __PACKAGE_NAME__ __PACKAGE_VERSION__ __PACKAGE_TIMESTAMP__ __PACKAGE_TITLE__ __INSTALL_TIMESTAMP__ __PACKAGE_TARGET_UBOOT_VERSION__ __PACKAGE_TARGET_KERNEL_VERSION__ \
    __PACKAGE_TARGET_FS_VERSION__ __PACKAGE_TARGET_DISTRO_NAME__ \
"
PACKAGE_UNQUOTED_FIELDS = "ID VERSION_ID VARIANT_ID"

__PACKAGE_TARGET_DISTRO_NAME__ = "${DISTRO}"
NAME = "${DISTRO_NAME}"
VERSION = "${DISTRO_VERSION}${@' (%s)' % DISTRO_CODENAME if 'DISTRO_CODENAME' in d else ''}"
VERSION_ID = "${DISTRO_VERSION}"
PRETTY_NAME = "${DISTRO_NAME} ${VERSION}"
__PACKAGE_TIMESTAMP__ ?= "${DATETIME}"
BUILD_ID[vardepsexclude] = "DATETIME"


do_install () {

  if ![ -d "${D}${sysconfdir}/odm" ]; then
    bbnote " /etc/odm directory doesn't exist, creating it..."
    mkdir ${D}${sysconfdir}/odm
  fi

    # Create the folder device in the rootfs
    install -m 0755 -d ${D}${sysconfdir}/odm
    install -m 0644 ${WORKDIR}/package.json ${D}${sysconfdir}/odm/

}

FILES:${PN} += " \
    ${sysconfdir}/odm/package.json \
"