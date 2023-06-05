FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = "  file://system.conf \
                    file://root-ca.pem \
                    file://rauc-mark-good.service \
                    file://rauc-pre-install-5x.sh \
"

RAUC_KEYRING_FILE = "root-ca.pem"
SYSTEMD_AUTO_ENABLE = "disable"

do_install:append() {
    install -d ${D}${bindir}
    install -m 0755 -d ${D}${sysconfdir}/ssl/certs
    install -m 0755 -d ${D}${bindir}/odm
    install ${WORKDIR}/root-ca.pem ${D}${sysconfdir}/ssl/certs/
    install ${WORKDIR}/rauc-pre-install-5x.sh  ${D}${bindir}/odm
}
