#!/bin/bash
CURDIR=`dirname $0`
RTM_DIR="/usr/share/openrtm-1.2/components"

cd ${CURDIR}/..
${RTM_DIR}/c++/Navigation/SimplePathFollower/SimplePathFollowerComp -f rtc.conf $*
