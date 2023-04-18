SUMMARY = "Recipes needed to run RAUC on an owa5X"

PACKAGE_ARCH = "${MACHINE_ARCH}"
inherit packagegroup

PROVIDES = "${PACKAGES}"
PACKAGES = " packagegroup-rauc \
"
RDEPENDS:${PN} = "\
    paho-mqtt-c \
    rauc \
    casync \
"
