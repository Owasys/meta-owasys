SUMMARY = "First Owasys owa5x YOCTO image"

IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL} kernel-devicetree"

IMAGE_LINGUAS = "en-us"

LICENSE = "MIT"

inherit core-image image_types


# Set rootfs to 460MiB by default
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "460000"
IMAGE_FSTYPES += " tar.gz "
hostname:pn-base-files = "Cetus"

IMAGE_INSTALL += "  iw mtd-utils mtd-utils-ubifs can-utils openssh sudo \
                    rsync ppp alsa-utils iproute2 net-tools e2fsprogs \
                    bluez5 imx-kobs inetutils redis libev  e2fsprogs-resize2fs \
                    hiredis tpm2-abrmd tpm2-tools tpm2-tss  \
                    tpm2-tss-engine tpm2-openssl u-boot-fw-utils lrzsz \
"

IMAGE_INSTALL:append = " \
                        pmsrv-service \
                        u-boot-owasys \
                        imx-boot-owasys \
                        alsa-lib \
                        owasys-libs \
                        kernel-modules\
                        owaturnoff \
                        owastandby \
                        start-can \
                        start-bt-wifi \
                        test-owa5x \
                        turn-gsm-off \
                        linux-firmware-owasys \
                        wpa-supplicant \
                        udev-rules-owasys \
                        system-maintenance-service \
                        rtc-tools \
                        quectel-cm \
                        switch-gsm \
                        st32-firmware \
                        chatscripts \
                        issue-owa \
                        fw-env-config \
                        ppp-owasys \
                        pollux-net \
                        pollux-gps \
                        data-folder \
                        device-folder \
                        fstab \
                        resizefs-service \
                        mlanutl \
"

do_image[depends] += " \
    mtd-utils-native:do_populate_sysroot \
"

make_custom_ubifs() {

# UBI VOLS PARAMETERS
# DEVICE VOL
    UBI_DEVICE_VOL_SIZE_IN_MB="15"
    UBI_DEVICE_VOL_NAME="device"

# ROOTFS VOL
    UBI_ROOTFS_VOL_SIZE_IN_MB="451"
    UBI_ROOTFS_VOL_NAME="rootfs"

    MKUBIFS_ARGS="-F -q -m 4096 -e 253952 -c 7876"
    UBINIZE_ARGS="-m 4096 -p 256KiB"

# UBI IMAGE GENERATION
# Added prompt error message for ubi and ubifs image creation.
if [ -z "$MKUBIFS_ARGS" ] || [ -z "$UBINIZE_ARGS" ]; then
    bbfatal "MKUBIFS_ARGS and UBINIZE_ARGS have to be set, see http://www.linux-mtd.infradead.org/faq/ubifs.html for details"
fi

# Adding rootfs partition

	echo \[ubifs\] > ubinize${IMAGE_NAME}.cfg
	echo mode=ubi >> ubinize${IMAGE_NAME}.cfg
	echo image=${IMGDEPLOYDIR}/${IMAGE_NAME}${vname}-${UBI_ROOTFS_VOL_NAME}.${UBI_IMGTYPE} >> ubinize${IMAGE_NAME}.cfg
	echo vol_id=0 >> ubinize${IMAGE_NAME}.cfg
	echo vol_size=${UBI_ROOTFS_VOL_SIZE_IN_MB}MiB >> ubinize${IMAGE_NAME}.cfg
	echo vol_type=${UBI_VOLTYPE} >> ubinize${IMAGE_NAME}.cfg
	echo vol_name=${UBI_ROOTFS_VOL_NAME} >> ubinize${IMAGE_NAME}.cfg
	echo vol_flags=autoresize >> ubinize${IMAGE_NAME}.cfg
	echo vol_alignment=1 >> ubinize${IMAGE_NAME}.cfg

# Adding device partition

	echo \[device\] >> ubinize${IMAGE_NAME}.cfg
	echo mode=ubi >> ubinize${IMAGE_NAME}.cfg
	echo image=${IMGDEPLOYDIR}/${IMAGE_NAME}${vname}-${UBI_DEVICE_VOL_NAME}.${UBI_IMGTYPE} >> ubinize${IMAGE_NAME}.cfg
	echo vol_id=1 >> ubinize${IMAGE_NAME}.cfg
	echo vol_size=${UBI_DEVICE_VOL_SIZE_IN_MB}MiB >> ubinize${IMAGE_NAME}.cfg
	echo vol_type=${UBI_VOLTYPE} >> ubinize${IMAGE_NAME}.cfg
	echo vol_name=${UBI_DEVICE_VOL_NAME} >> ubinize${IMAGE_NAME}.cfg
	echo vol_alignment=1 >> ubinize${IMAGE_NAME}.cfg

   	mkfs.ubifs -r ${IMAGE_ROOTFS} -o ${IMGDEPLOYDIR}/${IMAGE_NAME}${vname}-${UBI_ROOTFS_VOL_NAME}.ubifs ${MKUBIFS_ARGS}
	mkfs.ubifs -r ${IMAGE_ROOTFS}/device -o ${IMGDEPLOYDIR}/${IMAGE_NAME}${vname}-${UBI_DEVICE_VOL_NAME}.ubifs ${MKUBIFS_ARGS}
	ubinize -o ${IMGDEPLOYDIR}/${IMAGE_NAME}.ubi ${UBINIZE_ARGS} ubinize${IMAGE_NAME}.cfg

	# Cleanup cfg file
	mv ubinize${IMAGE_NAME}.cfg ${IMGDEPLOYDIR}/

    cd ${DEPLOY_DIR_IMAGE}/
    ln -sf ${IMAGE_NAME}.ubi ${IMAGE_LINK_NAME}.ubi
}

make_custom_ext4_partition () {

	# Create a sparse image block
	#dd if=/dev/zero of=${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.$fstype count=26 bs=1024
	#mkfs.ext4 -F ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.$fstype -d ${IMAGE_ROOTFS}/data
}


IMAGE_POSTPROCESS_COMMAND += " make_custom_ubifs; "
