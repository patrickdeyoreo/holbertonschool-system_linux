#!/usr/bin/env sh
# signal_send.sh - send SIGQUIT to a process, given its PID
# Usage: signal_send.sh <pid>

if test "$#" -ne 1
then
  printf 'Usage: %s <pid>\n' "$0"
  exit 1
fi

kill -s QUIT -- "$1"
