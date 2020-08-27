// -*- C++ -*-
/*!
 * @file  Localization_MRPT.h
 * @brief Localization MRPT Component
 * @date  $Date$
 *
 * $Id$
 */

#ifndef LOCALIZATION_MRPT_H
#define LOCALIZATION_MRPT_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "MobileRobotStub.h"
#include "InterfaceDataTypesStub.h"
#include "ExtendedDataTypesStub.h"

// </rtc-template>
#include "MobileRobotStub.h"

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class Localization_MRPT
 * @brief Localization MRPT Component
 *
 */
class Localization_MRPT
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  Localization_MRPT(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~Localization_MRPT();

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
   * - Name:  min_x
   * - DefaultValue: -0.01
   */
  float m_min_x;
  /*!
   * 
   * - Name:  max_x
   * - DefaultValue: 0.01
   */
  float m_max_x;
  /*!
   * 
   * - Name:  min_y
   * - DefaultValue: -0.01
   */
  float m_min_y;
  /*!
   * 
   * - Name:  max_y
   * - DefaultValue: 0.01
   */
  float m_max_y;
  /*!
   * 
   * - Name:  min_phi
   * - DefaultValue: -0.01
   */
  float m_min_phi;
  /*!
   * 
   * - Name:  max_phi
   * - DefaultValue: 0.01
   */
  float m_max_phi;
  /*!
   * 
   * - Name:  range_min
   * - DefaultValue: 0.3
   */
  float m_range_min;
  /*!
   * 
   * - Name:  range_max
   * - DefaultValue: 10
   */
  float m_range_max;
  /*!
   * 
   * - Name:  minStdXY
   * - DefaultValue: 0.01
   */
  float m_minStdXY;
  /*!
   * 
   * - Name:  minStdPHI
   * - DefaultValue: 0.01
   */
  float m_minStdPHI;
  /*!
   * 
   * - Name:  KLD_binSize_PHI
   * - DefaultValue: 0.01
   */
  float m_KLD_binSize_PHI;
  /*!
   * 
   * - Name:  KLD_binSize_XY
   * - DefaultValue: 0.01
   */
  float m_KLD_binSize_XY;
  /*!
   * 
   * - Name:  KLD_delta
   * - DefaultValue: 0.02
   */
  float m_KLD_delta;
  /*!
   * 
   * - Name:  KLD_epsilon
   * - DefaultValue: 0.02
   */
  float m_KLD_epsilon;
  /*!
   * 
   * - Name:  KLD_maxSampleSize
   * - DefaultValue: 1000
   */
  int m_KLD_maxSampleSize;
  /*!
   * 
   * - Name:  KLD_minSampleSize
   * - DefaultValue: 150
   */
  int m_KLD_minSampleSize;
  /*!
   * 
   * - Name:  KLD_minSamplesPerBin
   * - DefaultValue: 0
   */
  double m_KLD_minSamplesPerBin;
  /*!
   * 
   * - Name:  adaptiveSampleSize
   * - DefaultValue: 1
   */
  bool m_adaptiveSampleSize;
  /*!
   * 
   * - Name:  pfAuxFilterOptimal_MaximumSearchSamples
   * - DefaultValue: 10
   */
  int m_pfAuxFilterOptimal_MaximumSearchSamples;
  /*!
   * 
   * - Name:  BETA
   * - DefaultValue: 0.5
   */
  double m_BETA;
  /*!
   * 
   * - Name:  sampleSize
   * - DefaultValue: 1
   */
  int m_sampleSize;
  /*!
   * 
   * - Name:  poseTimeOut
   * - DefaultValue: 3.0
   */
  float m_poseTimeOut;
  /*!
   * 
   * - Name:  PF_algorithm
   * - DefaultValue: pfSatndardProposal
   */
  int m_PF_algorithm;
  /*!
   * 
   * - Name:  resamplingMethod
   * - DefaultValue: prMultinomials
   */
  int m_resamplingMethod;
  /*!
   * 
   * - Name:  particles_count
   * - DefaultValue: 1000
   */
  int m_particles_count;
  /*!
   * 
   * - Name:  occupancyGrid_count
   * - DefaultValue: 1
   */
  int m_occupancyGrid_count;
  /*!
   * 
   * - Name:  mapAltitude
   * - DefaultValue: 0
   */
  int m_mapAltitude;
  /*!
   * 
   * - Name:  useMapAltitude
   * - DefaultValue: 1
   */
  int m_useMapAltitude;
  /*!
   * 
   * - Name:  maxDistanceInsertion
   * - DefaultValue: 15
   */
  int m_maxDistanceInsertion;
  /*!
   * 
   * - Name:  maxOccupancyUpdateCertainty
   * - DefaultValue: 0.55
   */
  double m_maxOccupancyUpdateCertainty;
  /*!
   * 
   * - Name:  considerInvalidRangesAsFreeSpace
   * - DefaultValue: 1
   */
  int m_considerInvalidRangesAsFreeSpace;
  /*!
   * 
   * - Name:  decimation
   * - DefaultValue: 1
   */
  int m_decimation;
  /*!
   * 
   * - Name:  horizontalTolerance
   * - DefaultValue: 0.000873
   */
  double m_horizontalTolerance;
  /*!
   * 
   * - Name:  CFD_features_gaussian_size
   * - DefaultValue: 1.0
   */
  double m_CFD_features_gaussian_size;
  /*!
   * 
   * - Name:  CFD_features_median_size
   * - DefaultValue: 3.0
   */
  double m_CFD_features_median_size;
  /*!
   * 
   * - Name:  wideningBeamsWithDistance
   * - DefaultValue: 0
   */
  int m_wideningBeamsWithDistance;
  /*!
   * 
   * - Name:  likelihoodMethod
   * - DefaultValue: 4
   */
  int m_likelihoodMethod;
  /*!
   * 
   * - Name:  enableLikelihoodCache
   * - DefaultValue: 1
   */
  int m_enableLikelihoodCache;
  /*!
   * 
   * - Name:  LF_decimation
   * - DefaultValue: 20
   */
  int m_LF_decimation;
  /*!
   * 
   * - Name:  LF_stdHit
   * - DefaultValue: 20
   */
  double m_LF_stdHit;
  /*!
   * 
   * - Name:  LF_maxCorrsDistance
   * - DefaultValue: 0.30
   */
  double m_LF_maxCorrsDistance;
  /*!
   * 
   * - Name:  LF_zHit
   * - DefaultValue: 0.95
   */
  double m_LF_zHit;
  /*!
   * 
   * - Name:  LF_zRandom
   * - DefaultValue: 0.05
   */
  double m_LF_zRandom;
  /*!
   * 
   * - Name:  LF_maxRange
   * - DefaultValue: 80
   */
  double m_LF_maxRange;
  /*!
   * 
   * - Name:  LF_alternateAverageMethod
   * - DefaultValue: 0
   */
  int m_LF_alternateAverageMethod;
  /*!
   * 
   * - Name:  MI_exponent
   * - DefaultValue: 10
   */
  int m_MI_exponent;
  /*!
   * 
   * - Name:  MI_skip_rays
   * - DefaultValue: 10
   */
  int m_MI_skip_rays;
  /*!
   * 
   * - Name:  MI_ratio_max_distance
   * - DefaultValue: 2
   */
  int m_MI_ratio_max_distance;
  /*!
   * 
   * - Name:  rayTracing_useDistanceFilter
   * - DefaultValue: 0
   */
  int m_rayTracing_useDistanceFilter;
  /*!
   * 
   * - Name:  rayTracing_decimation
   * - DefaultValue: 10
   */
  int m_rayTracing_decimation;
  /*!
   * 
   * - Name:  rayTracing_stdHit
   * - DefaultValue: 0.30
   */
  double m_rayTracing_stdHit;
  /*!
   * 
   * - Name:  consensus_takeEachRange
   * - DefaultValue: 30
   */
  int m_consensus_takeEachRange;
  /*!
   * 
   * - Name:  consensus_pow
   * - DefaultValue: 1
   */
  int m_consensus_pow;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::RangeData m_range;
  /*!
   */
  RTC::InPort<RTC::RangeData> m_rangeIn;
  RTC::TimedPose2D m_odometry;
  /*!
   */
  RTC::InPort<RTC::TimedPose2D> m_odometryIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedPose2D m_estimatedPose;
  /*!
   */
  RTC::OutPort<RTC::TimedPose2D> m_estimatedPoseOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_mapServerPort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<RTC::OGMapServer> m_mapServer;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

	 bool m_odomUpdated, m_rangeUpdated;

	 
	 coil::TimeValue m_lastReceivedTime;

	 enum LOCALIZATION_MODE{
		 MODE_NORMAL,
		 MODE_POSE_INVALID_VALUE,
		 MODE_POSE_TIME_OUT
	 };
	 LOCALIZATION_MODE m_MODE;
	 LOCALIZATION_MODE getMode(){return m_MODE;}
};


extern "C"
{
  DLL_EXPORT void Localization_MRPTInit(RTC::Manager* manager);
};

#endif // LOCALIZATION_MRPT_H
