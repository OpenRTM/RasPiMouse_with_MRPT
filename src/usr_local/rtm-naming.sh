#!/bin/sh

PID=`pgrep omniNames`

if [ "x$PID" = "x" ]; then
  #cd /var/lib/omniorb
  cd /tmp
  /usr/bin/rtm-naming -f
  sleep 3
fi
