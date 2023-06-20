#!/usr/bin/env bash
#===============================================================================
#
#          FILE:  odm-commands.sh
#
#         USAGE:  ./odm-commands.sh {"method": "pollux_reboot" "id": 5}
#         DEBUG:  TRACE=1 ./odm-commands.sh {"method": "pollux_reboot", params: {}, "id": 5}
#
#   DESCRIPTION: Executes commands sent by the ODM. It is called by the odm-agent.
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
    echo 'Usage: ./odm-commands.sh {"method": "pollux_reboot", params: {}, "id": 5}

Executes commands sent by the ODM. It is called by the odm-agent.

'
    exit
fi

cd "$(dirname "$0")"

################################# configuration vars #############################

##### LOGGER

LOGGER="$(which logger)"
LOG_LABEL="odm-commands"

##### PLATFORM-SPECIFIC VARIABLES

REDIS_CLI="redis-cli"
JQ="/usr/bin/jq"

##### REDIS

SOCK_PATH="/tmp/redis.sock"

##### TUNNEL

SSH_TUNNEL_WRAPPER="start_tunnel.sh"
SSH_TUNNEL_WRAPPER_PATH="/home/scripts/$SSH_TUNNEL_WRAPPER"
SSH_TUNNEL_CLIENT="dbclient"
SSH_TUNNEL_BEGIN="/bin/dbclient -f -N -y -i /root/.ssh/id_rsa -R "
SSH_TUNNEL_END=":localhost:22 -T owa3x@"
SSH_TUNNEL_HOST="owasys.com"
SSH_TUNNEL_PORT="5000"
REMOVE_BACKSLASH="sed 's/^.//;s/.$//' | sed 's/\\//g'"

##### UPDATE

UPDATE_FILE="/home/update/update"

##### DIAGNOSE

DIAGNOSE_FILE="/home/scripts/owa_info.sh"
BOOTSTRAP=1

################################# commands #############################

reboot()
{
  $LOGGER -t "$LOG_LABEL" "pollux_reboot command received"
  # SIGTERM, SIGINT, SIGKILL This is more than enough. The process will very probably terminate before SIGKILL.

  if [ -x "/home/scripts/shutdown.sh" ]; then
    /home/scripts/shutdown.sh &
  else
    /sbin/shutdown -r &
  fi

}

update()
{
    $LOGGER -t "$LOG_LABEL" "update received"
    # UPDATE_VERSION=$(echo $result | $JQ '.params' | $JQ '.version' | tr -d '"')
    UPDATE_VERSION=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.version')
    # UPDATE_URL=$(echo $result | $JQ '.params' | $JQ '.url' | tr -d '"')
    UPDATE_URL=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.url')
    #printf "Version: %s - URL: %s\n" $UPDATE_VERSION $UPDATE_URL
    $LOGGER -t "$LOG_LABEL" "Version: $UPDATE_VERSION - URL: $UPDATE_URL"
    echo $UPDATE_URL > $UPDATE_FILE
    printf "$(date)\t [$(basename $0)] OTA received '$UPDATE_URL'\n" >> "/home/log/remote-updates.log"
}

diagnose()
{
    $LOGGER -t "$LOG_LABEL" "diagnose received"
    $DIAGNOSE_FILE start dm > /dev/null 2>&1 &
}

cli()
{
    $LOGGER -t "$LOG_LABEL" "cli command received"
    CLI_COMMAND=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.command')
    CLI_DELAY=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' |$JQ -r '.delay')
    if test "$CLI_DELAY" == "null"
    then
        CLI_DELAY=0
    fi
    printf "$(date)\t [$(basename $0)] remote CLI command '$CLI_COMMAND' (with delay ${CLI_DELAY}s)\n" >> "/home/log/remote-cli.log"
    $LOGGER -t "$LOG_LABEL" "Command: $CLI_COMMAND - Delay: $CLI_DELAY"
    ( sleep "$CLI_DELAY" ; $CLI_COMMAND ) &
}

#For example,
#tunnel
tunnel()
{
    $LOGGER -t "$LOG_LABEL" "tunnel received"
    SSH_TUNNEL_ON=$(echo "$result" | $JQ '.params')
    if [ "$SSH_TUNNEL_ON" = "true" ]; then
        $LOGGER -t "$LOG_LABEL" "Executing $SSH_TUNNEL_WRAPPER_PATH"
        nohup "$SSH_TUNNEL_WRAPPER_PATH" > /dev/null 2>&1 &
        # $SSH_TUNNEL_WRAPPER_PATH & WRONG! stdout...
    elif [ "$SSH_TUNNEL_ON" = "false" ]; then
        TUNNEL_PID=$(pgrep "$SSH_TUNNEL_CLIENT")
        if [ -n "$TUNNEL_PID" ]; then
            if ! kill "$TUNNEL_PID" && pkill "$SSH_TUNNEL_WRAPPER"; then
                $LOGGER -t "$LOG_LABEL" "Tunnel NOT killed"
            else
                $LOGGER -t "$LOG_LABEL" "Tunnel killed OK"
            fi
        else
            $LOGGER -t "$LOG_LABEL Could not get Tunnel PID, tunnel NOT killed"
        fi
  else
      SSH_TUNNEL_HOST=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.host')
    #  SSH_TUNNEL_HOST=$(echo $result | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.host')
    #  SSH_TUNNEL_PORT=$(echo $result | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ '.port')
      SSH_TUNNEL_PORT=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ '.tunnel_port')
      SSH_REMOTE_HOST_PORT=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ '.remote_host_port')
      SSH_REMOTE_HOST_USER=$(echo "$result" | $JQ '.params' | sed 's/^.//;s/.$//' | sed 's/\\//g' | $JQ -r '.remote_host_user')
      $LOGGER -t "$LOG_LABEL  Host: $SSH_TUNNEL_HOST - Tunnel port: $SSH_TUNNEL_PORT - Remote host port: $SSH_REMOTE_HOST_PORT - Remote host user: $SSH_REMOTE_HOST_USER"
      nohup "$SSH_TUNNEL_WRAPPER_PATH $SSH_TUNNEL_HOST $SSH_TUNNEL_PORT $SSH_REMOTE_HOST_PORT $SSH_REMOTE_HOST_USER" > /dev/null 2>&1 &
  fi
}

getTermInfo(){
    $LOGGER -t "$LOG_LABEL" "getTermInfo command \"$1\" received"
    #JSON_STRING=$(echo "$1" | sed 's/"/\\\"/g' | tr -d "\n")
    #RETURN_JSON=$(odm-remote-shell -c "\"$JSON_STRING\"")
    #$LOGGER -t $LOG_LABEL "odm-remote-shell response: \"$RETURN_JSON\""
    #echo "$RETURN_JSON" | "$JQ" . | tr -d '\n' | $REDIS_CLI -s "$SOCK_PATH" -x RPUSH tb-rpc-out
    echo "$1" | "$JQ" . | tr -d '\n' | $REDIS_CLI -s "$SOCK_PATH" -x RPUSH odm-remote-shell
}

sendCommand(){
    $LOGGER -t "$LOG_LABEL" "sendCommand command \"$1\" received"
    echo "$1" | "$JQ" . | tr -d '\n' | $REDIS_CLI -s "$SOCK_PATH" -x RPUSH odm-remote-shell
}

getCommandStatus(){
    $LOGGER -t "$LOG_LABEL" "getCommandStatus command \"$1\" received"
    echo "$1" | "$JQ" . | tr -d '\n' | $REDIS_CLI -s "$SOCK_PATH" -x RPUSH odm-remote-shell
}

terminateCommand(){
    $LOGGER -t "$LOG_LABEL" "terminateCommand command \"$1\" received"
    echo "$1" | "$JQ" . | tr -d '\n' | $REDIS_CLI -s "$SOCK_PATH" -x RPUSH odm-remote-shell
}

find_my_owa()
{
    $LOGGER -t "$LOG_LABEL" "find_my_owa command received"
    # SIGTERM, SIGINT, SIGKILL This is more than enough. The process will very probably terminate before SIGKILL.

    polluxd -s "app.updating=1"
    sleep 1
    echo timer > /sys/class/leds/ledsw0\:yellow/trigger
    echo timer > /sys/class/leds/ledsw1\:green/trigger
    echo timer > /sys/class/leds/ledsw2\:red/trigger
    echo timer > /sys/class/leds/ppsgps\:orange/trigger
    sleep 60
    echo 0 > /sys/class/leds/ledsw0\:yellow/brightness
    echo 0 > /sys/class/leds/ledsw1\:green/brightness
    echo 0 > /sys/class/leds/ledsw2\:red/brightness
    echo 0 > /sys/class/leds/ppsgps\:orange/brightness
    sleep 1
    polluxd -s "app.updating=0"
}

################################# aux functions #############################

# Parsing function
parse()
{
    # $method is a local variable
    local method
    local ret
    ret=0
    method=$(echo ${1} | $JQ -r .method)
    params=$(echo ${1} | $JQ -r .params)
    # printf "Parsing method: %s\n" $method
    $LOGGER -t "$LOG_LABEL" "Parsing method: $method"

    # if test "$method" != "reboot"
    # then
    #   echo "reboot"
    # elif test "$method" != "tunnel"
    # then
    case $method in
        "pollux_reboot")
            reboot
            ;;
        "find_my_owa")
            find_my_owa
            ;;
        "update")
            update
            ;;
        "tunnel")
            tunnel
            ;;
        "diagnose")
            diagnose
            ;;
        "cli")
            cli
            ;;
        "status")
            $LOGGER -t "$LOG_LABEL" "status received"
            # exit
            # SOCK_PATH=$VALUE
            ;;
        "getTermInfo")
            sendCommand "$1"
            ;;
        "sendCommand")
            sendCommand "$1"
            ;;
        "getCommandStatus")
            sendCommand "$1"
            ;;
        "terminateCommand")
            sendCommand "$1"
            ;;
        *)
        #echo "ERROR: unknown method \"$method\""
        $LOGGER -t "$LOG_LABEL" "ERROR: unknown method \"$method\""
        printf "Nothing to do here...\n" >&2
        ret=1
        ;;
    esac
    return $ret
}


################################# main function #############################

main() {
    JSON_ATTRIBUTE="$1"
    parse "$JSON_ATTRIBUTE"
    printf "Command processed\n" >&2
}

main "$@"