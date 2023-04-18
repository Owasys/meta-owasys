# A minimal demo bundle
#
# Note: The created bundle will not contain RAUC itself yet!
# To add this, properly configure it for your specific system and add it to
# your image recipe you intend to build a bundle from:
#
# IMAGE_INSTALL:append = " rauc"
#
# Also note that you need to configure RAUC_KEY_FILE and RAUC_CERT_FILE to
# point to contain the full path to your key and cert.
# Depending on you requirements you can either set them via global
# configuration or from a bundle recipe bbappend.
#
# For testing purpose, you may use the scripts/openssl-ca.sh to create some.

inherit bundle

RAUC_BUNDLE_COMPATIBLE ?= "owa5X"

RAUC_BUNDLE_SLOTS ?= "rootfs"

#   RAUC_SLOT_bootloader ?= "uboot"
#   RAUC_SLOT_bootloader[type] ?= "boot"
#   RAUC_SLOT_bootloader[file] ?= "owa5x-flash.bin"

RAUC_SLOT_rootfs ?= "cetus-image-nand"
RAUC_SLOT_rootfs[fstype] = "ubivol"

RAUC_KEY_FILE ?= "ca.key.pem"
RAUC_CERT_FILE ?= "root-ca.pem"
RAUC_KEYRING_FILE ?= "root-ca.pem"



#   RAUC_BUNDLE_COMPATIBLE ?= "My Super Product"
#   RAUC_BUNDLE_VERSION ?= "v2015-06-07-1"
#
#   SRC_URI += "hook.sh"
#
#   RAUC_BUNDLE_HOOKS[file] ?= "hook.sh"
#   RAUC_BUNDLE_HOOKS[hooks] ?= "install-check"
#
#   RAUC_BUNDLE_SLOTS ?= "rootfs kernel dtb bootloader"
#   
#   RAUC_SLOT_rootfs ?= "core-image-minimal"
#   RAUC_SLOT_rootfs[fstype] = "ext4"
#   RAUC_SLOT_rootfs[hooks] ?= "install;post-install"
#   RAUC_SLOT_rootfs[adaptive] ?= "block-hash-index"
#   
#   RAUC_SLOT_kernel ?= "linux-yocto"
#   RAUC_SLOT_kernel[type] ?= "kernel"
#   
#   RAUC_SLOT_bootloader ?= "barebox"
#   RAUC_SLOT_bootloader[type] ?= "boot"
#   RAUC_SLOT_bootloader[file] ?= "barebox.img"
#
#   RAUC_SLOT_dtb ?= linux-yocto
#   RAUC_SLOT_dtb[type] ?= "file"
#   RAUC_SLOT_dtb[file] ?= "${MACHINE}.dtb"
#
# To use a different image name, e.g. for variants
#   RAUC_SLOT_dtb ?= linux-yocto
#   RAUC_SLOT_dtb[name] ?= "dtb.my,compatible"
#   RAUC_SLOT_dtb[type] ?= "file"
#   RAUC_SLOT_dtb[file] ?= "${MACHINE}-variant1.dtb"
#
# To override the file name used in the bundle use 'rename'
#   RAUC_SLOT_rootfs ?= "core-image-minimal"
#   RAUC_SLOT_rootfs[rename] ?= "rootfs.ext4"
#
# To prepend an offset to a bootloader image, set the following parameter in bytes.
# Optionally you can use units allowed by 'dd' e.g. 'K','kB','MB'.
# If the offset is negative, bytes will not be added, but removed.
#   RAUC_SLOT_bootloader[offset] ?= "0"
#
# Enable building verity format bundles with
#
#   RAUC_BUNDLE_FORMAT = "verity"
#
# To add additional artifacts to the bundle you can use RAUC_BUNDLE_EXTRA_FILES
# and RAUC_BUNDLE_EXTRA_DEPENDS.
# For files from the WORKDIR (fetched using SRC_URI) you can write:
#
#   SRC_URI += "file://myfile"
#   RAUC_BUNDLE_EXTRA_FILES += "myfile"
#
# For files from the DEPLOY_DIR_IMAGE (generated by another recipe) you can write:
#
#   RAUC_BUNDLE_EXTRA_DEPENDS += "myfile-recipe-pn"
#   RAUC_BUNDLE_EXTRA_FILES += "myfile.img"
#
# Extra arguments may be passed to the bundle command with BUNDLE_ARGS eg:
#   BUNDLE_ARGS += ' --mksquashfs-args="-comp zstd -Xcompression-level 22" '
#
# Likewise, extra arguments can be passed to the convert command with
# CONVERT_ARGS.
#
# Additionally you need to provide a certificate and a key file
#
#   RAUC_KEY_FILE ?= "development-1.key.pem"
#   RAUC_CERT_FILE ?= "development-1.cert.pem"
#
# For bundle signature verification a keyring file must be provided
#
#   RAUC_KEYRING_FILE ?= "ca.cert.pem"
#
# Enable building casync bundles with
#
#   RAUC_CASYNC_BUNDLE = "1"
