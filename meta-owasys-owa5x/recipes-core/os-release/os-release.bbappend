# Other valid fields: BUILD_ID ID_LIKE ANSI_COLOR CPE_NAME
#                     HOME_URL SUPPORT_URL BUG_REPORT_URL
OS_RELEASE_FIELDS += "\
    MACHINE \
    HOME_URL \
    SUPPORT_URL \
"
OS_RELEASE_UNQUOTED_FIELDS += "\
    MACHINE \
"

ID = "yocto"
NAME = "kirkstone"
MACHINE = "owa5"
HOME_URL = "https://www.owasys.com"
SUPPORT_URL = "mailto:cs@owasys.com"
