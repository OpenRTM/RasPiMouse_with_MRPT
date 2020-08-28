#!/bin/bash
#

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

export DISPLAY=$2:0.0

RTM_PKG_ROOT=/usr/share/openrtm-1.2/components
HOSTNAME=`hostname`
NS_TOP=/localhost/${HOSTNAME}.host_cxt

case "$1" in
  start)
    cd `dirname $0`

    `dirname $0`/rtm-naming.sh
    start_rtc RaspberryPiMouseRTC
    start_rtc RPLidarRTC
    start_rtc Mapper_MRPT
    start_rtc NavigationManager
  ;;
  connect)
    rtcon ${NS_TOP}/NavigationManager0.rtc:range ${NS_TOP}/RPLidarRTC0.rtc:range
    rtcon ${NS_TOP}/Mapper_MRPT0.rtc:range ${NS_TOP}/RPLidarRTC0.rtc:range
    rtcon ${NS_TOP}/Mapper_MRPT0.rtc:odometry ${NS_TOP}/RaspberryPiMouseRTC0.rtc:current_pose_out
    rtcon ${NS_TOP}/Mapper_MRPT0.rtc:estimatedPose ${NS_TOP}/NavigationManager0.rtc:currentPose
    rtcon ${NS_TOP}/Mapper_MRPT0.rtc:gridMapper ${NS_TOP}/NavigationManager0.rtc:mapperService
  ;;
  disconnect)
    rtdis ${NS_TOP}/NavigationManager0.rtc:range ${NS_TOP}/RPLidarRTC0.rtc:range
    rtdis ${NS_TOP}/Mapper_MRPT0.rtc:range ${NS_TOP}/RPLidarRTC0.rtc:range
    rtdis ${NS_TOP}/Mapper_MRPT0.rtc:odometry ${NS_TOP}/RaspberryPiMouseRTC0.rtc:current_pose_out
    rtdis ${NS_TOP}/Mapper_MRPT0.rtc:estimatedPose ${NS_TOP}/NavigationManager0.rtc:currentPose
    rtdis ${NS_TOP}/Mapper_MRPT0.rtc:gridMapper ${NS_TOP}/NavigationManager0.rtc:mapperService
  ;;
  activate)
    rtact ${NS_TOP}/NavigationManager0.rtc
    rtact ${NS_TOP}/Mapper_MRPT0.rtc
    rtact ${NS_TOP}/RaspberryPiMouseRTC0.rtc
    rtact ${NS_TOP}/RPLidarRTC0.rtc
  ;;
  deactivate)
    rtdeact ${NS_TOP}/NavigationManager0.rtc
    rtdeact ${NS_TOP}/Mapper_MRPT0.rtc
    rtdeact ${NS_TOP}/RaspberryPiMouseRTC0.rtc
    rtdeact ${NS_TOP}/RPLidarRTC0.rtc
  ;;
  stop)
    rtexit ${NS_TOP}/NavigationManager0.rtc
    rtexit ${NS_TOP}/Mapper_MRPT0.rtc
    rtexit ${NS_TOP}/RaspberryPiMouseRTC0.rtc
    rtexit ${NS_TOP}/RPLidarRTC0.rtc
  ;;
  status)
    rtls -l ${NS_TOP}
  ;;
  *)
    echo "Usage: $0 {start|connect|disconnect|activate|deactivate|stop}" >&2
    exit 3
esac

exit 0
