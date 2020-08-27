// -*-C++-*-
/*!
 * @file  MobileRobotSVC_impl.cpp
 * @brief Service implementation code of MobileRobot.idl
 *
 * GPL
 *
 */

#include "MobileRobotSVC_impl.h"
#include "Mapper_MRPT.h"

/*
 * Example implementational code for IDL interface RTC::OGMapper
 */
RTC_OGMapperSVC_impl::RTC_OGMapperSVC_impl()
{
  // Please add extra constructor code here.
}


RTC_OGMapperSVC_impl::~RTC_OGMapperSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
RTC::RETURN_VALUE RTC_OGMapperSVC_impl::initializeMap(const RTC::OGMapConfig& config, const RTC::Pose2D& initialPose)
{
  return RTC::RETVAL_OK;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::startMapping()
{
  RTC::RETURN_VALUE result = RTC::RETVAL_OK;
  if(m_pRTC->startMapping() < 0) {
	return RTC::RETVAL_INVALID_PRECONDITION;
  }
  return result;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::stopMapping()
{
  RTC::RETURN_VALUE result = RTC::RETVAL_OK;;
  if(m_pRTC->stopMapping() < 0) {
	return RTC::RETVAL_INVALID_PRECONDITION;
  }
  return result;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::suspendMapping()
{
  return RTC::RETVAL_OK;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::resumeMapping()
{
  return RTC::RETVAL_OK;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::getState(RTC::MAPPER_STATE& state)
{
  RTC::RETURN_VALUE result = RTC::RETVAL_OK;
  state = m_pRTC->getState();
  return result;
}

RTC::RETURN_VALUE RTC_OGMapperSVC_impl::requestCurrentBuiltMap(RTC::OGMap_out map)
{
  RTC::RETURN_VALUE result;
  m_pRTC->getCurrentMap(map);
  result = RTC::RETVAL_OK;
  return result;
}



// End of example implementational code

/*
 * Example implementational code for IDL interface RTC::OGMapServer
 */
RTC_OGMapServerSVC_impl::RTC_OGMapServerSVC_impl()
{
  // Please add extra constructor code here.
}


RTC_OGMapServerSVC_impl::~RTC_OGMapServerSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
RTC::RETURN_VALUE RTC_OGMapServerSVC_impl::requestCurrentBuiltMap(RTC::OGMap_out map)
{
  return RTC::RETVAL_OK;
}



// End of example implementational code



