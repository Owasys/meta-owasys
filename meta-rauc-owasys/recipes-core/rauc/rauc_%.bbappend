FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = "  file://system.conf \
                    file://root-ca.pem \
"

RAUC_KEYRING_FILE = "root-ca.pem"