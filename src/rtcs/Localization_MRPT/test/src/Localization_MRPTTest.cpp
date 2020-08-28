// -*- C++ -*-
/*!
 * @file  Localization_MRPTTest.cpp
 * @brief Localization MRPT Component
 * @date $Date$
 *
 * $Id$
 */

#include "Localization_MRPTTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* localization_mrpt_spec[] =
  {
    "implementation_id", "Localization_MRPTTest",
    "type_name",         "Localization_MRPTTest",
    "description",       "Localization MRPT Component",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.min_x", "-0.01",
    "conf.default.max_x", "0.01",
    "conf.default.min_y", "-0.01",
    "conf.default.max_y", "0.01",
    "conf.default.min_phi", "-0.01",
    "conf.default.max_phi", "0.01",
    "conf.default.range_min", "0.3",
    "conf.default.range_max", "10",
    "conf.default.gausianModel_minStdXY", "0.01",
    "conf.default.gausianModel_minStdPHI", "0.01",
    "conf.default.KLD_binSize_PHI", "0.01",
    "conf.default.KLD_binSize_XY", "0.01",
    "conf.default.KLD_delta", "0.02",
    "conf.default.KLD_epsilon", "0.02",
    "conf.default.KLD_maxSampleSize", "1000",
    "conf.default.KLD_minSampleSize", "150",
    "conf.default.KLD_minSamplesPerBin", "0",
    "conf.default.adaptiveSampleSize", "1",
    "conf.default.pfAuxFilterOptimal_MaximumSearchSamples", "10",
    "conf.default.BETA", "0.5",
    "conf.default.sampleSize", "1",
    "conf.default.poseTimeOut", "3.0",
    "conf.default.PF_algorithm", "pfSatndardProposal",
    "conf.default.resampleingMethod", "prMultinomials",
    "conf.default.particles_count", "1000",
    "conf.default.occupancyGrid_count", "1",
    "conf.default.mapAltitude", "0",
    "conf.default.useMapaltitude", "1",
    "conf.default.maxDistanceInsertion", "15",
    "conf.default.maxOccupancyUpdateCertainty", "0.55",
    "conf.default.consiiderInvalidRangesAsFreeSpace", "1",
    "conf.default.decimation", "1",
    "conf.default.hrizontalTolerance", "0.000873",
    "conf.default.CFD_features_gaussian_size", "1.0",
    "conf.default.CFD_features_median_size", "3.0",
    "conf.default.wideningBeamsWithDistance", "0",
    "conf.default.likelihoodMethod", "4",
    "conf.default.enableLikelihoodCache", "1",
    "conf.default.LF_decimation", "20",
    "conf.default.LF_stdHit", "20",
    "conf.default.LF_maxCorrsDistance", "0.30",
    "conf.default.LF_zHit", "0.95",
    "conf.default.LF_zRandom", "0.05",
    "conf.default.LF_maxRange", "80",
    "conf.default.LF_alternateAverageMethod", "0",
    "conf.default.MI_exponent", "10",
    "conf.default.MI_skip_rasys", "10",
    "conf.default.MI_ratio_max_distance", "2",
    "conf.default.rayTracing_useDistanceFilter", "0",
    "conf.default.rayTracing_decimation", "10",
    "conf.default.rayTracing_stdHit", "0.30",
    "conf.default.consensus_takeEachRange", "30",
    "conf.default.consensus_pow", "1",

    // Widget
    "conf.__widget__.min_x", "text",
    "conf.__widget__.max_x", "text",
    "conf.__widget__.min_y", "text",
    "conf.__widget__.max_y", "text",
    "conf.__widget__.min_phi", "text",
    "conf.__widget__.max_phi", "text",
    "conf.__widget__.range_min", "text",
    "conf.__widget__.range_max", "text",
    "conf.__widget__.gausianModel_minStdXY", "text",
    "conf.__widget__.gausianModel_minStdPHI", "text",
    "conf.__widget__.KLD_binSize_PHI", "text",
    "conf.__widget__.KLD_binSize_XY", "text",
    "conf.__widget__.KLD_delta", "text",
    "conf.__widget__.KLD_epsilon", "text",
    "conf.__widget__.KLD_maxSampleSize", "text",
    "conf.__widget__.KLD_minSampleSize", "text",
    "conf.__widget__.KLD_minSamplesPerBin", "text",
    "conf.__widget__.adaptiveSampleSize", "text",
    "conf.__widget__.pfAuxFilterOptimal_MaximumSearchSamples", "text",
    "conf.__widget__.BETA", "text",
    "conf.__widget__.sampleSize", "text",
    "conf.__widget__.poseTimeOut", "text",
    "conf.__widget__.PF_algorithm", "text",
    "conf.__widget__.resampleingMethod", "text",
    "conf.__widget__.particles_count", "text",
    "conf.__widget__.occupancyGrid_count", "text",
    "conf.__widget__.mapAltitude", "text",
    "conf.__widget__.useMapaltitude", "text",
    "conf.__widget__.maxDistanceInsertion", "text",
    "conf.__widget__.maxOccupancyUpdateCertainty", "text",
    "conf.__widget__.consiiderInvalidRangesAsFreeSpace", "text",
    "conf.__widget__.decimation", "text",
    "conf.__widget__.hrizontalTolerance", "text",
    "conf.__widget__.CFD_features_gaussian_size", "text",
    "conf.__widget__.CFD_features_median_size", "text",
    "conf.__widget__.wideningBeamsWithDistance", "text",
    "conf.__widget__.likelihoodMethod", "text",
    "conf.__widget__.enableLikelihoodCache", "text",
    "conf.__widget__.LF_decimation", "text",
    "conf.__widget__.LF_stdHit", "text",
    "conf.__widget__.LF_maxCorrsDistance", "text",
    "conf.__widget__.LF_zHit", "text",
    "conf.__widget__.LF_zRandom", "text",
    "conf.__widget__.LF_maxRange", "text",
    "conf.__widget__.LF_alternateAverageMethod", "text",
    "conf.__widget__.MI_exponent", "text",
    "conf.__widget__.MI_skip_rasys", "text",
    "conf.__widget__.MI_ratio_max_distance", "text",
    "conf.__widget__.rayTracing_useDistanceFilter", "text",
    "conf.__widget__.rayTracing_decimation", "text",
    "conf.__widget__.rayTracing_stdHit", "text",
    "conf.__widget__.consensus_takeEachRange", "text",
    "conf.__widget__.consensus_pow", "text",
    // Constraints

    "conf.__type__.min_x", "float",
    "conf.__type__.max_x", "float",
    "conf.__type__.min_y", "float",
    "conf.__type__.max_y", "float",
    "conf.__type__.min_phi", "float",
    "conf.__type__.max_phi", "float",
    "conf.__type__.range_min", "float",
    "conf.__type__.range_max", "float",
    "conf.__type__.gausianModel_minStdXY", "float",
    "conf.__type__.gausianModel_minStdPHI", "float",
    "conf.__type__.KLD_binSize_PHI", "float",
    "conf.__type__.KLD_binSize_XY", "float",
    "conf.__type__.KLD_delta", "float",
    "conf.__type__.KLD_epsilon", "float",
    "conf.__type__.KLD_maxSampleSize", "int",
    "conf.__type__.KLD_minSampleSize", "int",
    "conf.__type__.KLD_minSamplesPerBin", "double",
    "conf.__type__.adaptiveSampleSize", "bool",
    "conf.__type__.pfAuxFilterOptimal_MaximumSearchSamples", "int",
    "conf.__type__.BETA", "double",
    "conf.__type__.sampleSize", "int",
    "conf.__type__.poseTimeOut", "float",
    "conf.__type__.PF_algorithm", "string",
    "conf.__type__.resampleingMethod", "int",
    "conf.__type__.particles_count", "int",
    "conf.__type__.occupancyGrid_count", "int",
    "conf.__type__.mapAltitude", "int",
    "conf.__type__.useMapaltitude", "int",
    "conf.__type__.maxDistanceInsertion", "int",
    "conf.__type__.maxOccupancyUpdateCertainty", "double",
    "conf.__type__.consiiderInvalidRangesAsFreeSpace", "int",
    "conf.__type__.decimation", "int",
    "conf.__type__.hrizontalTolerance", "double",
    "conf.__type__.CFD_features_gaussian_size", "double",
    "conf.__type__.CFD_features_median_size", "double",
    "conf.__type__.wideningBeamsWithDistance", "int",
    "conf.__type__.likelihoodMethod", "int",
    "conf.__type__.enableLikelihoodCache", "int",
    "conf.__type__.LF_decimation", "int",
    "conf.__type__.LF_stdHit", "double",
    "conf.__type__.LF_maxCorrsDistance", "double",
    "conf.__type__.LF_zHit", "double",
    "conf.__type__.LF_zRandom", "double",
    "conf.__type__.LF_maxRange", "double",
    "conf.__type__.LF_alternateAverageMethod", "int",
    "conf.__type__.MI_exponent", "int",
    "conf.__type__.MI_skip_rasys", "int",
    "conf.__type__.MI_ratio_max_distance", "int",
    "conf.__type__.rayTracing_useDistanceFilter", "int",
    "conf.__type__.rayTracing_decimation", "int",
    "conf.__type__.rayTracing_stdHit", "double",
    "conf.__type__.consensus_takeEachRange", "int",
    "conf.__type__.consensus_pow", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Localization_MRPTTest::Localization_MRPTTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rangeIn("range", m_range),
    m_odometryIn("odometry", m_odometry),
    m_estimatedPoseOut("estimatedPose", m_estimatedPose),
    m_mapServerPort("mapServer")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Localization_MRPTTest::~Localization_MRPTTest()
{
}



RTC::ReturnCode_t Localization_MRPTTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("estimatedPose", m_estimatedPoseIn);
  
  // Set OutPort buffer
  addOutPort("range", m_rangeOut);
  addOutPort("odometry", m_odometryOut);
  
  // Set service provider to Ports
  m_mapServerPort.registerProvider("OGMapServer", "RTC::OGMapServer", m_mapServer);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_mapServerPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("min_x", m_min_x, "-0.01");
  bindParameter("max_x", m_max_x, "0.01");
  bindParameter("min_y", m_min_y, "-0.01");
  bindParameter("max_y", m_max_y, "0.01");
  bindParameter("min_phi", m_min_phi, "-0.01");
  bindParameter("max_phi", m_max_phi, "0.01");
  bindParameter("range_min", m_range_min, "0.3");
  bindParameter("range_max", m_range_max, "10");
  bindParameter("gausianModel_minStdXY", m_minStdXY, "0.01");
  bindParameter("gausianModel_minStdPHI", m_minStdPHI, "0.01");
  bindParameter("KLD_binSize_PHI", m_KLD_binSize_PHI, "0.01");
  bindParameter("KLD_binSize_XY", m_KLD_binSize_XY, "0.01");
  bindParameter("KLD_delta", m_KLD_delta, "0.02");
  bindParameter("KLD_epsilon", m_KLD_epsilon, "0.02");
  bindParameter("KLD_maxSampleSize", m_KLD_maxSampleSize, "1000");
  bindParameter("KLD_minSampleSize", m_KLD_minSampleSize, "150");
  bindParameter("KLD_minSamplesPerBin", m_KLD_minSamplesPerBin, "0");
  bindParameter("adaptiveSampleSize", m_adaptiveSampleSize, "1");
  bindParameter("pfAuxFilterOptimal_MaximumSearchSamples", m_pfAuxFilterOptimal_MaximumSearchSamples, "10");
  bindParameter("BETA", m_BETA, "0.5");
  bindParameter("sampleSize", m_sampleSize, "1");
  bindParameter("poseTimeOut", m_poseTimeOut, "3.0");
  bindParameter("PF_algorithm", m_PF_algorithm, "pfSatndardProposal");
  bindParameter("resampleingMethod", m_resampleingMethod, "prMultinomials");
  bindParameter("particles_count", m_particles_count, "1000");
  bindParameter("occupancyGrid_count", m_occupancyGrid_count, "1");
  bindParameter("mapAltitude", m_mapAltitude, "0");
  bindParameter("useMapaltitude", m_useMapaltitude, "1");
  bindParameter("maxDistanceInsertion", m_maxDistanceInsertion, "15");
  bindParameter("maxOccupancyUpdateCertainty", m_maxOccupancyUpdateCertainty, "0.55");
  bindParameter("consiiderInvalidRangesAsFreeSpace", m_consiiderInvalidRangesAsFreeSpace, "1");
  bindParameter("decimation", m_decimation, "1");
  bindParameter("hrizontalTolerance", m_hrizontalTolerance, "0.000873");
  bindParameter("CFD_features_gaussian_size", m_CFD_features_gaussian_size, "1.0");
  bindParameter("CFD_features_median_size", m_CFD_features_median_size, "3.0");
  bindParameter("wideningBeamsWithDistance", m_wideningBeamsWithDistance, "0");
  bindParameter("likelihoodMethod", m_likelihoodMethod, "4");
  bindParameter("enableLikelihoodCache", m_enableLikelihoodCache, "1");
  bindParameter("LF_decimation", m_LF_decimation, "20");
  bindParameter("LF_stdHit", m_LF_stdHit, "20");
  bindParameter("LF_maxCorrsDistance", m_LF_maxCorrsDistance, "0.30");
  bindParameter("LF_zHit", m_LF_zHit, "0.95");
  bindParameter("LF_zRandom", m_LF_zRandom, "0.05");
  bindParameter("LF_maxRange", m_LF_maxRange, "80");
  bindParameter("LF_alternateAverageMethod", m_LF_alternateAverageMethod, "0");
  bindParameter("MI_exponent", m_MI_exponent, "10");
  bindParameter("MI_skip_rasys", m_MI_skip_rasys, "10");
  bindParameter("MI_ratio_max_distance", m_MI_ratio_max_distance, "2");
  bindParameter("rayTracing_useDistanceFilter", m_rayTracing_useDistanceFilter, "0");
  bindParameter("rayTracing_decimation", m_rayTracing_decimation, "10");
  bindParameter("rayTracing_stdHit", m_rayTracing_stdHit, "0.30");
  bindParameter("consensus_takeEachRange", m_consensus_takeEachRange, "30");
  bindParameter("consensus_pow", m_consensus_pow, "1");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Localization_MRPTTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Localization_MRPTTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Localization_MRPTTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Localization_MRPTTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Localization_MRPTTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPTTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Localization_MRPTTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(localization_mrpt_spec);
    manager->registerFactory(profile,
                             RTC::Create<Localization_MRPTTest>,
                             RTC::Delete<Localization_MRPTTest>);
  }
  
};


