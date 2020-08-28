#!/bin/sh
get_classpath()
{
  FILE1=`ls ${RTM_JAVA_ROOT}/jar/OpenRTM*`
  FILE2=`ls ${RTM_JAVA_ROOT}/jar/commons-cli*`
  FILE3=`ls ${RTM_JAVA_ROOT}/jar/jna-?.?.?.jar`
  FILE4=`ls ${RTM_JAVA_ROOT}/jar/jna-platform-*.jar`
  FILE5=`ls ${NAVI_HOME}/jar/*.jar`
  #CLASSPATH=.:$FILE1:$FILE2:$FILE3:$FILE4:$FILE5:${RTM_JAVA_ROOT}/bin:`dirname $0`/bin:`dirname $0`
  export CLASSPATH=.:$FILE1:$FILE2:$FILE3:$FILE4:$FILE5:${RTM_JAVA_ROOT}/bin:${MAPSERVER_ROOT}
  #echo ${CLASSPATH}
}

export MAPSERVER_ROOT=/usr/share/openrtm-1.2/components/java/Navigation/MapServer
export RTM_JAVA_ROOT=/usr/lib/arm-linux-gnueabihf/openrtm-1.2
export RTM_IDL_DIR=/usr/share/openrtm-1.2/idl
export NAVI_HOME=`dirname $0`/..
export CLASSPATH=`get_classpath`

if test "x$RTM_JAVA_ROOT" = "x" ; then
    echo "Environment variable RTM_JAVA_ROOT is not set."
    echo "Please specify the OpenRTM-aist installation directory."
    echo "Abort."
    exit 1
fi


get_classpath

cd ${NAVI_HOME}
java MapServerComp -f rtc.conf $*
