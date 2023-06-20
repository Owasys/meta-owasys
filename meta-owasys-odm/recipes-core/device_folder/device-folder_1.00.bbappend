do_install:append () {

    if ![ -d "${D}/device/odm" ]; then
        bbnote " /device/odm directory doesn't exist, creating it..."
        mkdir ${D}/device/odm
    fi

  install -d ${D}/device/odm


}

FILES:${PN} += "/device/odm"