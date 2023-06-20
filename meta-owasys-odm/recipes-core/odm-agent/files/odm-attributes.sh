#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  odm-attributes.sh
#
#         USAGE:  ./odm-attributes.sh {"keys": ["namespacePrefix"] "values": ["owasysR&D"]}
#         DEBUG:  TRACE=1 ./odm-attributes.sh {"keys": ["namespacePrefix"] "values": ["owasysR&D"]}
#
#   DESCRIPTION: Executes functions after received attribute updates from the ODM. It is called by the odm-agent.
#
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#        AUTHOR:  owzgra
#       COMPANY:  Owasys SL
#       VERSION:  0.0.1
#       CREATED:  2023-05-25
#===============================================================================

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: ./odm-attributes.sh {"keys": ["namespacePrefix"] "values": ["owasysR&D"]}

Executes functions after received attribute updates from the ODM. It is called by the odm-agent.

'
    exit
fi

cd "$(dirname "$0")"

################################# configuration vars #############################

##### PLATFORM

PLATFORM='unknown'
MACHINE_TYPE=$(uname -m)
if [ "${MACHINE_TYPE}" = "armv5tejl" ]; then
  PLATFORM='owa3x'
elif [ "${MACHINE_TYPE}" = "armv7l" ]; then
  PLATFORM='owa4x'
elif [ "${MACHINE_TYPE}" = "x86_64" ]; then
  PLATFORM='x86_64'
fi

printf "Running on %s platform\n" $PLATFORM >&2

##### LOGGER

LOGGER="$(which logger)"
LOG_LABEL="odm-attributes"

##### PLATFORM-SPECIFIC VARIABLES

JQ="/usr/bin/jq"

################################# attribute functions #############################

namespacePrefix(){
    $LOGGER -t "$LOG_LABEL" "namespacePrefix attribute received"
    json_file="/device/odm/odm.json"
    temp_json_file="/tmp/odm.json"
    if [ -f "$json_file" ]; then
        nsp=$(jq -r '.namespacePrefix' $json_file)
        if [ "$nsp" != "$1" ]; then
            jq --arg nsp  "$1"  '.namespacePrefix=$nsp' "$json_file" > "$temp_json_file" && mv "$temp_json_file" "$json_file" && sync "$json_file"
            $LOGGER -t "$LOG_LABEL" "namespacePrefix set successfully in $json_file"
        else
            $LOGGER -t "$LOG_LABEL" "namespacePrefix has not changed in $json_file"
        fi
  else
    $LOGGER -t "$LOG_LABEL" "Failed setting namespacePrefix, file $json_file does not exist"
  fi
}

################################# aux functions #############################

parse()
{
    ret=0
    shared_key=$(echo "$1" | $JQ  -r 'keys[]')
    shared_values=$(echo "$1" | $JQ  -r 'values[]')
    $LOGGER -t "$LOG_LABEL" "Parsing shared key: $shared_key"
    case $shared_key in
        "fw_"*)
            if [ -x "/home/scripts/tb_functions/ota_fw_sw_functions.sh" ]; then
                /home/scripts/tb_functions/ota_fw_sw_functions.sh "$1" "$LOG_LABEL"
            else
                $LOGGER -t "$LOG_LABEL" "ERROR: script ota_fw_sw_functions.sh does not exits"
            fi
            ;;
        "sw_"*)
            if [ -x "/home/scripts/tb_functions/ota_fw_sw_functions.sh" ]; then
                /home/scripts/tb_functions/ota_fw_sw_functions.sh "$1" "$LOG_LABEL"
            else
                $LOGGER -t "$LOG_LABEL" "ERROR: script ota_fw_sw_functions.sh does not exits"
            fi
            ;;
        "namespacePrefix")
            namespacePrefix "$shared_values"
            ;;
        *)
            $LOGGER -t "$LOG_LABEL" "ERROR: unknown shared key \"$shared_key\""
            printf "Nothing to do here...\n" >&2
            ret=1
            ;;
    esac
    return $ret
}

################################# main function #############################

main() {
    JSON_ATTRIBUTE=$1
    parse "$JSON_ATTRIBUTE"
    printf "Attribute processed\n" >&2
}

main "$@"