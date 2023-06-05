
# Disables automatic setting of hostname. On owa5X pmsrv is handling this.
PACKAGECONFIG:remove = "hostnamed"
PACKAGECONFIG:remove = "myhostname"

# Disables system-auto-gpt-generator error
RRECOMMENDS:${PN}:remove = "systemd-extra-utils"

do_install:append() {
    install -d ${D}${systemd_unitdir}/system/
    rm -rf ${D}${sysconfdir}/systemd/system/network-online.target.wants/systemd-networkd-wait-online.service
}

