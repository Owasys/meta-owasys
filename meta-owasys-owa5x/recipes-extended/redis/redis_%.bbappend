# In order to get ready comms between polluxnet and redis, both must be using the same socker /tmp/redis.sock

do_install:append () {
    sed -i 's!# unixsocket /tmp/redis.sock!unixsocket /tmp/redis.sock!' ${D}/${sysconfdir}/redis/redis.conf
    sed -i 's!# unixsocketperm 700!unixsocketperm 700!' ${D}/${sysconfdir}/redis/redis.conf

}