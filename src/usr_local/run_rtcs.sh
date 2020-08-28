#!/bin/bash

function start_rtc(){
  HOSTNAME=`hostname`
  RTLS_OUT=`rtls /localhost/${HOSTNAME}.host_cxt`
  ARG1=$1
  TARGET=${ARG1}0.rtc
  START=0
  CURDIR=`dirname $0`

  for x in ${RTLS_OUT}
  do
   if [ ${x} = ${TARGET} ]; then
     echo ${x} is already running.
     START=1
   fi
  done

  if [ ${START} = 0 ];then
     echo call bin/${ARG1}.sh
     ${CURDIR}/bin/${ARG1}.sh &
  fi  
}

cd `dirname $0`
`dirname $0`/rtm-naming.sh

NAVIGATION_RTCS="RPLidarRTC RaspberryPiMouseRTC Mapper_MRPT MapServer PathPlanner_MRPT Localization_MRPT SimplePathFollower"

for x in ${NAVIGATION_RTCS}
do
  start_rtc ${x}
done
