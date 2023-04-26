
# Disables automatic setting of hostname. On owa5X pmsrv is handling this.
PACKAGECONFIG:remove = "hostnamed"
PACKAGECONFIG:remove = "myhostname"

# Disable systemd-networkd-wait-online
PACKAGECONFIG:remove = "networkd"

# Disables system-auto-gpt-generator error
RRECOMMENDS:${PN}:remove = "systemd-extra-utils"