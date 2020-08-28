// -*- C++ -*-
/*!
 * @file  SimplePathFollowerTest.cpp
 * @brief Simple Algorithm Path Follower
 * @date $Date$
 *
 * $Id$
 */

#include "SimplePathFollowerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* simplepathfollower_spec[] =
  {
    "implementation_id", "SimplePathFollowerTest",
    "type_name",         "SimplePathFollowerTest",
    "description",       "Simple Algorithm Path Follower",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    "conf.default.poseTimeout", "3.0",
    "conf.default.approachDirectionGain", "1.0",
    "conf.default.directionToTranslationGain", "0.0",
    "conf.default.directionToRotationGain", "0.0",
    "conf.default.minVelocity", "0.2",
    "conf.default.distanceToTranslationGain", "0.0",
    "conf.default.approachDistanceGain", "0.5",
    "conf.default.maxVelocity", "0.8",
    "conf.default.distanceToRotationGain", "2.0",

    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.poseTimeout", "text",
    "conf.__widget__.approachDirectionGain", "text",
    "conf.__widget__.directionToTranslationGain", "text",
    "conf.__widget__.directionToRotationGain", "text",
    "conf.__widget__.minVelocity", "text",
    "conf.__widget__.distanceToTranslationGain", "text",
    "conf.__widget__.approachDistanceGain", "text",
    "conf.__widget__.maxVelocity", "text",
    "conf.__widget__.distanceToRotationGain", "text",
    // Constraints

    "conf.__type__.debug", "int",
    "conf.__type__.poseTimeout", "string",
    "conf.__type__.approachDirectionGain", "string",
    "conf.__type__.directionToTranslationGain", "string",
    "conf.__type__.directionToRotationGain", "string",
    "conf.__type__.minVelocity", "string",
    "conf.__type__.distanceToTranslationGain", "string",
    "conf.__type__.approachDistanceGain", "string",
    "conf.__type__.maxVelocity", "string",
    "conf.__type__.distanceToRotationGain", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SimplePathFollowerTest::SimplePathFollowerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_currentPoseIn("currentPose", m_currentPose),
    m_pathIn("path", m_path),
    m_velocityOut("velocity", m_velocity),
    m_PathFollowerPort("PathFollower")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SimplePathFollowerTest::~SimplePathFollowerTest()
{
}



RTC::ReturnCode_t SimplePathFollowerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("velocity", m_velocityIn);
  
  // Set OutPort buffer
  addOutPort("currentPose", m_currentPoseOut);
  addOutPort("path", m_pathOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_PathFollowerPort.registerConsumer("PathFollower", "RTC::PathFollower", m_pathFollower);
  
  // Set CORBA Service Ports
  addPort(m_PathFollowerPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  bindParameter("poseTimeout", m_poseTimeout, "3.0");
  bindParameter("approachDirectionGain", m_approachDirectionGain, "1.0");
  bindParameter("directionToTranslationGain", m_directionToTranslationGain, "0.0");
  bindParameter("directionToRotationGain", m_directionToRotationGain, "0.0");
  bindParameter("minVelocity", m_minVelocity, "0.2");
  bindParameter("distanceToTranslationGain", m_distanceToTranslationGain, "0.0");
  bindParameter("approachDistanceGain", m_approachDistanceGain, "0.5");
  bindParameter("maxVelocity", m_maxVelocity, "0.8");
  bindParameter("distanceToRotationGain", m_distanceToRotationGain, "2.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SimplePathFollowerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SimplePathFollowerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SimplePathFollowerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SimplePathFollowerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SimplePathFollowerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SimplePathFollowerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SimplePathFollowerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(simplepathfollower_spec);
    manager->registerFactory(profile,
                             RTC::Create<SimplePathFollowerTest>,
                             RTC::Delete<SimplePathFollowerTest>);
  }
  
};


