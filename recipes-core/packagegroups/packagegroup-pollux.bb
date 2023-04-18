SUMMARY = "Recipes needed to add pollux on owa5X"

PACKAGE_ARCH = "${MACHINE_ARCH}"
inherit packagegroup

PROVIDES = "${PACKAGES}"
PACKAGES = " packagegroup-pollux \
"
RDEPENDS:${PN} = "\
    pollux-libs \
    pollux-net \
    pollux-gps \
    polluxc-tb \
"