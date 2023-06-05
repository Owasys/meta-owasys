FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI += " \
            file://tpm.cfg \
            file://owa5x_tpm_u_boot_variables.env \
"    
do_compile:prepend() {

    cp ${WORKDIR}/owa5x_tpm_u_boot_variables.env ${B}/${UBOOT_CONFIG}_defconfig/

}