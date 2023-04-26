FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI += " \
            file://rauc.cfg \
            file://owa5x_rauc_u_boot_variables.env \
"    
do_compile:prepend() {

    cp ${WORKDIR}/owa5x_rauc_u_boot_variables.env ${B}/${UBOOT_CONFIG}_defconfig/

}