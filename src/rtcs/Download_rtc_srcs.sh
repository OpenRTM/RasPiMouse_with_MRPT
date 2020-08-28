#!/bin/bash

REPO_ROOT=https://github.com/hara-jp

RTCS="NavigationManager MapServer Localization_MRPT Mapper_MRPT PathPlanner_MRPT SimplePathFollower RPLidarRTC RaspberryPiMouseRTC"

for x in ${RTCS}; do
  git clone ${REPO_ROOT}/${x}
done