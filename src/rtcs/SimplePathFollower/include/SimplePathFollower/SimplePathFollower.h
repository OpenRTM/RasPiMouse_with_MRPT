// -*- C++ -*-
/*!
 * @file  SimplePathFollower.h
 * @brief Simple Algorithm Path Follower
 * @date  $Date$
 *
 * $Id$
 */

#ifndef SIMPLEPATHFOLLOWER_H
#define SIMPLEPATHFOLLOWER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "MobileRobotSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "ExtendedDataTypesStub.h"
#include "InterfaceDataTypesStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

#include "SimpleFollower.h"


enum SIMPLE_PATH_FOLLOWER_MODE {
  MODE_NORMAL,
  MODE_TIMEOUT,
  MODE_OUTOFRANGE,
  MODE_GOALED,
};

/*!
 * @class SimplePathFollower
 * @brief Simple Algorithm Path Follower
 *
 */
class SimplePathFollower
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  SimplePathFollower(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~SimplePathFollower();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  debug
   * - DefaultValue: 0
   */
  int m_debug;
  /*!
   * 
   * - Name:  poseTimeout
   * - DefaultValue: 3.0
   */
  float m_poseTimeout;
  /*!
   * 
   * - Name:  approachDirectionGain
   * - DefaultValue: 1.0
   */
  float m_approachDirectionGain;
  /*!
   * 
   * - Name:  directionToTranslationGain
   * - DefaultValue: 0.0
   */
  float m_directionToTranslationGain;
  /*!
   * 
   * - Name:  directionToRotationGain
   * - DefaultValue: 0.0
   */
  float m_directionToRotationGain;
  /*!
   * 
   * - Name:  minVelocity
   * - DefaultValue: 0.2
   */
  float m_minVelocity;
  /*!
   * 
   * - Name:  distanceToTranslationGain
   * - DefaultValue: 0.0
   */
  float m_distanceToTranslationGain;
  /*!
   * 
   * - Name:  approachDistanceGain
   * - DefaultValue: 0.5
   */
  float m_approachDistanceGain;
  /*!
   * 
   * - Name:  maxVelocity
   * - DefaultValue: 0.8
   */
  float m_maxVelocity;
  /*!
   * 
   * - Name:  distanceToRotationGain
   * - DefaultValue: 2.0
   */
  float m_distanceToRotationGain;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedPose2D m_currentPose;
  /*!
   */
  RTC::InPort<RTC::TimedPose2D> m_currentPoseIn;
  RTC::Path2D m_path;
  /*!
   */
  RTC::InPort<RTC::Path2D> m_pathIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedVelocity2D m_velocity;
  /*!
   */
  RTC::OutPort<RTC::TimedVelocity2D> m_velocityOut;
  
  // </rtc-template>

  enum __path_follower_state {
    STATE_HALT,
    STATE_FOLLOWING,
    STATE_OUTOFRANGE,
    STATE_ERROR,
  };
  
  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_PathFollowerPort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  /*!
   */
  RTC_PathFollowerSVC_impl m_pathFollower;
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>
  bool m_poseUpdated;
  SimpleFollower m_pathFollowerObj;

public:

  void startFollow() {
    m_pathFollowerObj.startFollow(m_path);
  }

  void stopFollow() {
	  m_pathFollowerObj.stopFollow();
  }

  void setPath(const RTC::Path2D& path) {
    this->m_path = path;
  }

  coil::TimeValue m_lastReceivedTime;

  SIMPLE_PATH_FOLLOWER_MODE m_Mode;

public:
  SIMPLE_PATH_FOLLOWER_MODE getMode() {return m_Mode;}

  bool isGoal() {
    return m_pathFollowerObj.isGoal();
  }

};


extern "C"
{
  DLL_EXPORT void SimplePathFollowerInit(RTC::Manager* manager);
};

#endif // SIMPLEPATHFOLLOWER_H
