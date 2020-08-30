#!/bin/bash

VERSION=1.2.1
CODENAME=buster
ARCH=armhf
GITHUB=https://github.com/OpenRTM/RasPiMouse_with_MRPT

# installing MRPT
echo "Installing MRPT"
/usr/bin/sudo apt-get install mrpt

# installing OpenRTM-aist
echo "Installing OpenRTM-aist"
wget https://github.com/OpenRTM/OpenRTM-aist/raw/v${VERSION}/build/pkg_install_ubuntu.sh
/bin/bash pkg_install_ubuntu.sh -l all --yes

# installing RTCs
echo "Installing RTCs"
/usr/bin/wget ${GITHUB}/release/download/${VERSION}/debs_${VERSION}-${CODENAME}-${ARCH}.tgz
/usr/bin/sudo /bin/tar xzvf debs_${VERSION}-${CODENAME}-${ARCH}.tgz -C /tmp
/usr/bin/sudo /usr/bin/dpkg -i /tmp/debs_${VERSION}-${CODENAME}-${ARCH}/*.deb

# installing scripts
echo "Installing launch script and config files"
/usr/bin/wget ${GITHUB}/release/download/${VERSION}/usr_local.tgz
/usr/bin/sudo /bin/tar xzvf usr_local.tgz -C /usr/local

# installing web tools
echo "Installing Web tools"
/usr/bin/wget ${GITHUB}/release/download/${VERSION}/var_www.tgz
/usr/bin/sudo /bin/tar xzvf var_www.tgz -C /var
