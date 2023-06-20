FILESEXTRAPATHS:prepend := "${THISDIR}/${BPN}:"

# Disables automatic setting of hostname. On owa5X pmsrv is handling this.
PACKAGECONFIG:remove = "hostnamed"
PACKAGECONFIG:remove = "myhostname"

# Disables system-auto-gpt-generator error
RRECOMMENDS:${PN}:remove = "systemd-extra-utils"

SRC_URI += " file://00-eth0.network \
             file://01-eth1.network \
"

do_install:append () {

    install -d ${D}${sysconfdir}/systemd/network

    install ${WORKDIR}/00-eth0.network ${D}${sysconfdir}/systemd/network/
    install ${WORKDIR}/01-eth1.network ${D}${sysconfdir}/systemd/network/

    install -d ${D}${sysconfdir}/systemd/system/network-online.target.wants/
    #Mask the netword-wait-online
    ln -s -r ${D}/dev/null ${D}${sysconfdir}/systemd/system/network-online.target.wants/systemd-networkd-wait-online.service
}

