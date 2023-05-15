FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = "  file://system.conf \
                    file://root-ca.pem \
                    file://rauc-mark-good.service \
"

RAUC_KEYRING_FILE = "root-ca.pem"
SYSTEMD_AUTO_ENABLE = "disable"
