#!/bin/bash
#===============================================================================
#
#          FILE:  measured-boot.sh
#
#         USAGE:  ./measured-boot.sh
#         DEBUG:  TRACE=1 ./measured-boot.sh
#
#   DESCRIPTION: Script to determine if a boot was correct. It should return 0,
#                returning 1 ( exit 1 ) means an error and it will reboot the system.
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzagj
#       COMPANY:  Owasys SL
#       VERSION:  0.0.0
#       CREATED:  2023-05-10
#===============================================================================

main() {

TPM_FILES="/device/tpm/"
mkdir -p $TPM_FILES

create_policy
create_keys
#create_csr

}

create_policy()
{
   # create the pcr policy
   tpm2_createprimary -C o -g sha256 -G ecc -c $TPM_FILES/primary_sh.ctx
   tpm2_pcrread "sha256:0,1,2,3,4" -o $TPM_FILES/pcr.bin
   tpm2_startauthsession -S $TPM_FILES/session.ctx
   # -L : the file where the policy digest is saved
   # -f: the expected pcr values 
   tpm2_policypcr -S $TPM_FILES/session.ctx -l "sha256:0,1,2,3,4" -f $TPM_FILES/pcr.bin -L $TPM_FILES/pcr.policy
   tpm2_flushcontext $TPM_FILES/session.ctx

}

create_keys()
{
   # create a key safeguarded by the policy in the owner hierarchy
   tpm2_evictcontrol -C o -c $TPM_FILES/primary_sh.ctx 0x81000001
   tpm2_create -C $TPM_FILES/primary_sh.ctx -g sha256 -G rsa -u $TPM_FILES/rsakey.pub -r $TPM_FILES/rsakey.priv -L $TPM_FILES/pcr.policy -a "fixedtpm|fixedparent|sensitivedataorigin|userwithauth|decrypt|sign|noda" -p pass123   
   tpm2_load -C $TPM_FILES/primary_sh.ctx -u $TPM_FILES/rsakey.pub -r $TPM_FILES/rsakey.priv -c $TPM_FILES/rsakey.ctx
}

#create_csr()
#{
#}

main "$@"
