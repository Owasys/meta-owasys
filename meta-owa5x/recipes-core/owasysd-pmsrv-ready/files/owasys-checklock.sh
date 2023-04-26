#!/bin/sh
#===============================================================================
#
#          FILE:  check_lock.sh
#
#         USAGE:  ./check_lock.sh
#
#   DESCRIPTION: External script to be run by systemd to check for the owaapi.lck
#
#       OPTIONS:  ---
#  REQUIREMENTS:  systemd
#          BUGS:  ---
#        AUTHOR:  owziap
#       COMPANY:  Owasys AWD S.L.
#       VERSION:  0.0.2
#       CREATED:  04/06/2020
#===============================================================================

LOCKFILE="/var/lock/owaapi.lck"                                                            
LOGGER="/usr/bin/logger"
LOG_LABEL="$(/usr/bin/basename $0)"

"$LOGGER" -t "$LOG_LABEL" "Check if lock file has been removed"
while [ -f "$LOCKFILE" ]
do
    # "$LOGGER" -p local0.debug -t "$LOG_LABEL" "$LOCKFILE still exists.." 
    sleep 1
done
"$LOGGER" -t "$LOG_LABEL" "End of script"
exit 0