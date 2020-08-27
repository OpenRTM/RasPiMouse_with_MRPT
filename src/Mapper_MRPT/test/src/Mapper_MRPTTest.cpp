// -*- C++ -*-
/*!
 * @file  Mapper_MRPTTest.cpp
 * @brief Mapper RTC using MRPT (Mobile Robot Programming Toolkit)
 * @date $Date$
 *
 * GPL
 *
 * $Id$
 */

#include "Mapper_MRPTTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* mapper_mrpt_spec[] =
  {
    "implementation_id", "Mapper_MRPTTest",
    "type_name",         "Mapper_MRPTTest",
    "description",       "Mapper RTC using MRPT (Mobile Robot Programming Toolkit)",
    "version",           "1.0.3",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    "conf.default.start_map_update_in_activated", "false",
    "conf.default.ICP_algorithm", "icpClassic",
    "conf.default.ICP_onlyClosestCorrespondences", "true",
    "conf.default.ICP_onlyUniqueRobust", "false",
    "conf.default.ICP_maxIterations", "80",
    "conf.default.ICP_minAbsStep_trans", "0.000001",
    "conf.default.ICP_minAbsStep_rot", "0.000001",
    "conf.default.ICP_thresholdDist", "0.2",
    "conf.default.ICP_thresholdAng", "0.1745",
    "conf.default.ICP_ALFA", "0.8",
    "conf.default.ICP_smallestThresholdDist", "0.05",
    "conf.default.ICP_covariance_varPoints", "0.0004",
    "conf.default.ICP_doRANSAC", "false",
    "conf.default.ICP_ransac_nSimulations", "100",
    "conf.default.ICP_ransac_minSetSize", "5",
    "conf.default.ICP_ransac_maxSetSize", "20",
    "conf.default.ICP_ransac_mahalanobisDistanceThreshold", "3.0",
    "conf.default.ICP_ransac_normalizationStd", "0.2",
    "conf.default.ICP_ransac_fuseByCorrsMatch", "false",
    "conf.default.ICP_ransac_fuseMaxDiffXY", "0.01",
    "conf.default.ICP_ransac_fuseMaxDiffPhi", "0.001745",
    "conf.default.ICP_kernel_rho", "0.07",
    "conf.default.ICP_use_kernel", "true",
    "conf.default.ICP_Axy_aprox_derivatives", "0.05",
    "conf.default.ICP_LM_initial_lambda", "0.0001",
    "conf.default.ICP_skip_cov_calculation", "false",
    "conf.default.ICP_skip_quality_calculation", "true",
    "conf.default.ICP_corresponding_points_decimation", "5",
    "conf.default.ICP_matchAgainstTheGrid", "0",
    "conf.default.ICP_insertionLinDistance", "0.5",
    "conf.default.ICP_insertionAngDistance", "0.8",
    "conf.default.ICP_localizationLinDistance", "0.5",
    "conf.default.ICP_localizationAngDistance", "0.8",
    "conf.default.ICP_minICPgoodnessToAccept", "0.40",
    "conf.default.MAP_min_x", "-10.0",
    "conf.default.MAP_max_x", "10.0",
    "conf.default.MAP_min_y", "-10.0",
    "conf.default.MAP_max_y", "10.0",
    "conf.default.MAP_resolution", "0.05",
    "conf.default.MAP_insertion_mapAltitude", "0.0",
    "conf.default.MAP_insertion_useMapAltitude", "false",
    "conf.default.MAP_insertion_maxDistanceInsertion", "15",
    "conf.default.MAP_insertion_maxOccupancyUpdateCertainty", "0.55",
    "conf.default.MAP_insertion_considerInvalidRangesAsFreeSpace", "true",
    "conf.default.MAP_insertion_decimation", "1",
    "conf.default.MAP_insertion_horizontalTolerance", "0",
    "conf.default.MAP_insertion_CFD_features_gaussian_size", "1",
    "conf.default.MAP_insertion_CFD_features_median_size", "3",
    "conf.default.MAP_insertion_wideningBeamsWithDistance", "false",
    "conf.default.initial_pose_x", "0.0",
    "conf.default.initial_pose_y", "0.0",
    "conf.default.initial_pose_phi", "0.0",

    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.start_map_update_in_activated", "radio",
    "conf.__widget__.ICP_algorithm", "radio",
    "conf.__widget__.ICP_onlyClosestCorrespondences", "radio",
    "conf.__widget__.ICP_onlyUniqueRobust", "radio",
    "conf.__widget__.ICP_maxIterations", "text",
    "conf.__widget__.ICP_minAbsStep_trans", "text",
    "conf.__widget__.ICP_minAbsStep_rot", "text",
    "conf.__widget__.ICP_thresholdDist", "text",
    "conf.__widget__.ICP_thresholdAng", "text",
    "conf.__widget__.ICP_ALFA", "text",
    "conf.__widget__.ICP_smallestThresholdDist", "text",
    "conf.__widget__.ICP_covariance_varPoints", "text",
    "conf.__widget__.ICP_doRANSAC", "radio",
    "conf.__widget__.ICP_ransac_nSimulations", "text",
    "conf.__widget__.ICP_ransac_minSetSize", "text",
    "conf.__widget__.ICP_ransac_maxSetSize", "text",
    "conf.__widget__.ICP_ransac_mahalanobisDistanceThreshold", "text",
    "conf.__widget__.ICP_ransac_normalizationStd", "text",
    "conf.__widget__.ICP_ransac_fuseByCorrsMatch", "radio",
    "conf.__widget__.ICP_ransac_fuseMaxDiffXY", "text",
    "conf.__widget__.ICP_ransac_fuseMaxDiffPhi", "text",
    "conf.__widget__.ICP_kernel_rho", "text",
    "conf.__widget__.ICP_use_kernel", "radio",
    "conf.__widget__.ICP_Axy_aprox_derivatives", "text",
    "conf.__widget__.ICP_LM_initial_lambda", "text",
    "conf.__widget__.ICP_skip_cov_calculation", "radio",
    "conf.__widget__.ICP_skip_quality_calculation", "radio",
    "conf.__widget__.ICP_corresponding_points_decimation", "text",
    "conf.__widget__.ICP_matchAgainstTheGrid", "radio",
    "conf.__widget__.ICP_insertionLinDistance", "text",
    "conf.__widget__.ICP_insertionAngDistance", "text",
    "conf.__widget__.ICP_localizationLinDistance", "text",
    "conf.__widget__.ICP_localizationAngDistance", "text",
    "conf.__widget__.ICP_minICPgoodnessToAccept", "text",
    "conf.__widget__.MAP_min_x", "text",
    "conf.__widget__.MAP_max_x", "text",
    "conf.__widget__.MAP_min_y", "text",
    "conf.__widget__.MAP_max_y", "text",
    "conf.__widget__.MAP_resolution", "text",
    "conf.__widget__.MAP_insertion_mapAltitude", "text",
    "conf.__widget__.MAP_insertion_useMapAltitude", "radio",
    "conf.__widget__.MAP_insertion_maxDistanceInsertion", "text",
    "conf.__widget__.MAP_insertion_maxOccupancyUpdateCertainty", "text",
    "conf.__widget__.MAP_insertion_considerInvalidRangesAsFreeSpace", "radio",
    "conf.__widget__.MAP_insertion_decimation", "text",
    "conf.__widget__.MAP_insertion_horizontalTolerance", "text",
    "conf.__widget__.MAP_insertion_CFD_features_gaussian_size", "text",
    "conf.__widget__.MAP_insertion_CFD_features_median_size", "text",
    "conf.__widget__.MAP_insertion_wideningBeamsWithDistance", "radio",
    "conf.__widget__.initial_pose_x", "text",
    "conf.__widget__.initial_pose_y", "text",
    "conf.__widget__.initial_pose_phi", "text",
    // Constraints
    "conf.__constraints__.start_map_update_in_activated", "(true,false)",
    "conf.__constraints__.ICP_algorithm", "(icpClassic,icpLevenbergMarquardt,icpIKF)",
    "conf.__constraints__.ICP_onlyClosestCorrespondences", "(true,false)",
    "conf.__constraints__.ICP_onlyUniqueRobust", "(true,false)",
    "conf.__constraints__.ICP_doRANSAC", "(true,false)",
    "conf.__constraints__.ICP_ransac_fuseByCorrsMatch", "(true,false)",
    "conf.__constraints__.ICP_use_kernel", "(true,false)",
    "conf.__constraints__.ICP_skip_cov_calculation", "(true,false)",
    "conf.__constraints__.ICP_skip_quality_calculation", "(true,false)",
    "conf.__constraints__.ICP_matchAgainstTheGrid", "(true,false)",
    "conf.__constraints__.MAP_insertion_useMapAltitude", "(true,false)",
    "conf.__constraints__.MAP_insertion_considerInvalidRangesAsFreeSpace", "(true,false)",
    "conf.__constraints__.MAP_insertion_wideningBeamsWithDistance", "(true,false)",

    "conf.__type__.debug", "int",
    "conf.__type__.start_map_update_in_activated", "string",
    "conf.__type__.ICP_algorithm", "string",
    "conf.__type__.ICP_onlyClosestCorrespondences", "string",
    "conf.__type__.ICP_onlyUniqueRobust", "string",
    "conf.__type__.ICP_maxIterations", "unsigned int",
    "conf.__type__.ICP_minAbsStep_trans", "float",
    "conf.__type__.ICP_minAbsStep_rot", "float",
    "conf.__type__.ICP_thresholdDist", "float",
    "conf.__type__.ICP_thresholdAng", "float",
    "conf.__type__.ICP_ALFA", "float",
    "conf.__type__.ICP_smallestThresholdDist", "float",
    "conf.__type__.ICP_covariance_varPoints", "float",
    "conf.__type__.ICP_doRANSAC", "string",
    "conf.__type__.ICP_ransac_nSimulations", "unsigned int",
    "conf.__type__.ICP_ransac_minSetSize", "unsigned int",
    "conf.__type__.ICP_ransac_maxSetSize", "unsigned int ",
    "conf.__type__.ICP_ransac_mahalanobisDistanceThreshold", "float",
    "conf.__type__.ICP_ransac_normalizationStd", "float",
    "conf.__type__.ICP_ransac_fuseByCorrsMatch", "string",
    "conf.__type__.ICP_ransac_fuseMaxDiffXY", "float",
    "conf.__type__.ICP_ransac_fuseMaxDiffPhi", "float",
    "conf.__type__.ICP_kernel_rho", "float",
    "conf.__type__.ICP_use_kernel", "string",
    "conf.__type__.ICP_Axy_aprox_derivatives", "float",
    "conf.__type__.ICP_LM_initial_lambda", "float",
    "conf.__type__.ICP_skip_cov_calculation", "string",
    "conf.__type__.ICP_skip_quality_calculation", "string",
    "conf.__type__.ICP_corresponding_points_decimation", "unsigned int",
    "conf.__type__.ICP_matchAgainstTheGrid", "string",
    "conf.__type__.ICP_insertionLinDistance", "double",
    "conf.__type__.ICP_insertionAngDistance", "double",
    "conf.__type__.ICP_localizationLinDistance", "double",
    "conf.__type__.ICP_localizationAngDistance", "double",
    "conf.__type__.ICP_minICPgoodnessToAccept", "float",
    "conf.__type__.MAP_min_x", "float",
    "conf.__type__.MAP_max_x", "float",
    "conf.__type__.MAP_min_y", "float",
    "conf.__type__.MAP_max_y", "float",
    "conf.__type__.MAP_resolution", "float",
    "conf.__type__.MAP_insertion_mapAltitude", "float",
    "conf.__type__.MAP_insertion_useMapAltitude", "string",
    "conf.__type__.MAP_insertion_maxDistanceInsertion", "float",
    "conf.__type__.MAP_insertion_maxOccupancyUpdateCertainty", "float",
    "conf.__type__.MAP_insertion_considerInvalidRangesAsFreeSpace", "string",
    "conf.__type__.MAP_insertion_decimation", "unsigned short int",
    "conf.__type__.MAP_insertion_horizontalTolerance", "float",
    "conf.__type__.MAP_insertion_CFD_features_gaussian_size", "float",
    "conf.__type__.MAP_insertion_CFD_features_median_size", "float",
    "conf.__type__.MAP_insertion_wideningBeamsWithDistance", "string",
    "conf.__type__.initial_pose_x", "double",
    "conf.__type__.initial_pose_y", "double",
    "conf.__type__.initial_pose_phi", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Mapper_MRPTTest::Mapper_MRPTTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rangeIn("range", m_range),
    m_odometryIn("odometry", m_odometry),
    m_estimatedPoseOut("estimatedPose", m_estimatedPose),
    m_gridMapperPort("gridMapper")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Mapper_MRPTTest::~Mapper_MRPTTest()
{
}



RTC::ReturnCode_t Mapper_MRPTTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("estimatedPose", m_estimatedPoseIn);
  
  // Set OutPort buffer
  addOutPort("range", m_rangeOut);
  addOutPort("odometry", m_odometryOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_gridMapperPort.registerConsumer("OGMapper", "RTC::OGMapper", m_mapper);
  
  // Set CORBA Service Ports
  addPort(m_gridMapperPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  bindParameter("start_map_update_in_activated", m_start_map_update_in_activated, "false");
  bindParameter("ICP_algorithm", m_ICP_algorithm, "icpClassic");
  bindParameter("ICP_onlyClosestCorrespondences", m_ICP_onlyClosestCorrespondences, "true");
  bindParameter("ICP_onlyUniqueRobust", m_ICP_onlyUniqueRobust, "false");
  bindParameter("ICP_maxIterations", m_ICP_maxIterations, "80");
  bindParameter("ICP_minAbsStep_trans", m_ICP_minAbsStep_trans, "0.000001");
  bindParameter("ICP_minAbsStep_rot", m_ICP_minAbsStep_rot, "0.000001");
  bindParameter("ICP_thresholdDist", m_ICP_thresholdDist, "0.2");
  bindParameter("ICP_thresholdAng", m_ICP_thresholdAng, "0.1745");
  bindParameter("ICP_ALFA", m_ICP_ALFA, "0.8");
  bindParameter("ICP_smallestThresholdDist", m_ICP_smallestThresholdDist, "0.05");
  bindParameter("ICP_covariance_varPoints", m_ICP_covariance_varPoints, "0.0004");
  bindParameter("ICP_doRANSAC", m_ICP_doRANSAC, "false");
  bindParameter("ICP_ransac_nSimulations", m_ICP_ransac_nSimulations, "100");
  bindParameter("ICP_ransac_minSetSize", m_ICP_ransac_minSetSize, "5");
  bindParameter("ICP_ransac_maxSetSize", m_ICP_ransac_maxSetSize, "20");
  bindParameter("ICP_ransac_mahalanobisDistanceThreshold", m_ICP_ransac_mahalanobisDistanceThreshold, "3.0");
  bindParameter("ICP_ransac_normalizationStd", m_ICP_ransac_normalizationStd, "0.2");
  bindParameter("ICP_ransac_fuseByCorrsMatch", m_ICP_ransac_fuseByCorrsMatch, "false");
  bindParameter("ICP_ransac_fuseMaxDiffXY", m_ICP_ransac_fuseMaxDiffXY, "0.01");
  bindParameter("ICP_ransac_fuseMaxDiffPhi", m_ICP_ransac_fuseMaxDiffPhi, "0.001745");
  bindParameter("ICP_kernel_rho", m_ICP_kernel_rho, "0.07");
  bindParameter("ICP_use_kernel", m_ICP_use_kernel, "true");
  bindParameter("ICP_Axy_aprox_derivatives", m_ICP_Axy_aprox_derivatives, "0.05");
  bindParameter("ICP_LM_initial_lambda", m_ICP_LM_initial_lambda, "0.0001");
  bindParameter("ICP_skip_cov_calculation", m_ICP_skip_cov_calculation, "false");
  bindParameter("ICP_skip_quality_calculation", m_ICP_skip_quality_calculation, "true");
  bindParameter("ICP_corresponding_points_decimation", m_ICP_corresponding_points_decimation, "5");
  bindParameter("ICP_matchAgainstTheGrid", m_ICP_matchAgainstTheGrid, "0");
  bindParameter("ICP_insertionLinDistance", m_ICP_insertionLinDistance, "0.5");
  bindParameter("ICP_insertionAngDistance", m_ICP_insertionAngDistance, "0.8");
  bindParameter("ICP_localizationLinDistance", m_ICP_localizationLinDistance, "0.5");
  bindParameter("ICP_localizationAngDistance", m_ICP_localizationAngDistance, "0.8");
  bindParameter("ICP_minICPgoodnessToAccept", m_ICP_minICPgoodnessToAccept, "0.40");
  bindParameter("MAP_min_x", m_MAP_min_x, "-10.0");
  bindParameter("MAP_max_x", m_MAP_max_x, "10.0");
  bindParameter("MAP_min_y", m_MAP_min_y, "-10.0");
  bindParameter("MAP_max_y", m_MAP_max_y, "10.0");
  bindParameter("MAP_resolution", m_MAP_resolution, "0.05");
  bindParameter("MAP_insertion_mapAltitude", m_MAP_insertion_mapAltitude, "0.0");
  bindParameter("MAP_insertion_useMapAltitude", m_MAP_insertion_useMapAltitude, "false");
  bindParameter("MAP_insertion_maxDistanceInsertion", m_MAP_insertion_maxDistanceInsertion, "15");
  bindParameter("MAP_insertion_maxOccupancyUpdateCertainty", m_MAP_insertion_maxOccupancyUpdateCertainty, "0.55");
  bindParameter("MAP_insertion_considerInvalidRangesAsFreeSpace", m_MAP_insertion_considerInvalidRangesAsFreeSpace, "true");
  bindParameter("MAP_insertion_decimation", m_MAP_insertion_decimation, "1");
  bindParameter("MAP_insertion_horizontalTolerance", m_MAP_insertion_horizontalTolerance, "0");
  bindParameter("MAP_insertion_CFD_features_gaussian_size", m_MAP_insertion_CFD_features_gaussian_size, "1");
  bindParameter("MAP_insertion_CFD_features_median_size", m_MAP_insertion_CFD_features_median_size, "3");
  bindParameter("MAP_insertion_wideningBeamsWithDistance", m_MAP_insertion_wideningBeamsWithDistance, "false");
  bindParameter("initial_pose_x", m_initial_pose_x, "0.0");
  bindParameter("initial_pose_y", m_initial_pose_y, "0.0");
  bindParameter("initial_pose_phi", m_initial_pose_phi, "0.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Mapper_MRPTTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Mapper_MRPTTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Mapper_MRPTTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Mapper_MRPTTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Mapper_MRPTTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Mapper_MRPTTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Mapper_MRPTTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(mapper_mrpt_spec);
    manager->registerFactory(profile,
                             RTC::Create<Mapper_MRPTTest>,
                             RTC::Delete<Mapper_MRPTTest>);
  }
  
};


