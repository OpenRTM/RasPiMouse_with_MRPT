#!/bin/sh

if ! test "x$1" = "x" ; then
  export DISPLAY=$1:0.0
fi

export NAVI_HOME=`dirname $0`/..
export RTM_JAVA_ROOT=/usr/lib/arm-linux-gnueabihf/openrtm-1.2
export RTM_IDL_DIR=/usr/share/openrtm-1.2/idl
export RTC_DIR=/usr/share/openrtm-1.2/components/java/Navigation/NavigationManager

get_classpath()
{
  FILE1=`ls ${RTM_JAVA_ROOT}/jar/OpenRTM*`
  FILE2=`ls ${RTM_JAVA_ROOT}/jar/commons-cli*`
  FILE3=`ls ${RTM_JAVA_ROOT}/jar/jna-?.?.?.jar`
  FILE4=`ls ${RTM_JAVA_ROOT}/jar/jna-platform-*.jar`
  FILE5=`ls ${NAVI_HOME}/jar/*.jar`
  export CLASSPATH=.:$FILE1:$FILE2:$FILE3:$FILE4:$FILE5:${RTM_JAVA_ROOT}/bin:${RTC_DIR}/bin:${RTC_DIR}
  #echo ${CLASSPATH}
}

if test "x$RTM_JAVA_ROOT" = "x" ; then
    echo "Environment variable RTM_JAVA_ROOT is not set."
    echo "Please specify the OpenRTM-aist installation directory."
    echo "Abort."
    exit 1
fi

get_classpath

cd ${NAVI_HOME}
java NavigationManagerComp -f rtc.conf $* > /dev/null
#java NavigationManagerComp -f rtc.conf $*
