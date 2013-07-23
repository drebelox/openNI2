/*****************************************************************************
*                                                                            *
*  OpenNI 2.x Alpha                                                          *
*  Copyright (C) 2012 PrimeSense Ltd.                                        *
*                                                                            *
*  This file is part of OpenNI.                                              *
*                                                                            *
*  Licensed under the Apache License, Version 2.0 (the "License");           *
*  you may not use this file except in compliance with the License.          *
*  You may obtain a copy of the License at                                   *
*                                                                            *
*      http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*****************************************************************************/
/// @file
/// Contains the definition of Device class that implements a virtual OpenNI
/// device, capable of reading data from a *.ONI file.

#include "PlayerStream.h"
#include "PlayerSource.h"
#include "XnMemory.h"
#include "OniProperties.h"
#include "XnPlatform.h"

namespace oni_file {

typedef struct  
{
	int refCount;
} PlayerStreamFrameCookie;

PlayerStream::PlayerStream(PlayerSource* pSource) :
	m_pSource(pSource), m_pLastFrame(NULL), m_newDataHandle(NULL), m_isStarted(false)
{
	m_videoMode.resolutionX = 0;
	m_videoMode.resolutionY = 0;
	m_stride = 0;
}

/// Destructor.
PlayerStream::~PlayerStream()
{
	// Destroy the stream (if it was not destroyed before).
	destroy();

	// Release last frame.
	m_cs.Lock();
	if (m_pLastFrame != NULL)
	{
		releaseFrame(m_pLastFrame);
		m_pLastFrame = NULL;
	}
	m_cs.Unlock();
}

OniStatus PlayerStream::Initialize()
{
	// Register events in the source.
	OniStatus rc = m_pSource->RegisterNewDataEvent(OnNewDataCallback, this, m_newDataHandle);
	if (rc != ONI_STATUS_OK)
	{
		destroy();
		return rc;
	}

	return ONI_STATUS_OK;
}

void PlayerStream::destroy()
{
	stop();

	if (m_newDataHandle != NULL)
	{
		// Send the destroy event.
		DestroyEventArgs destroyEventArgs;
		destroyEventArgs.pStream = this;
		m_destroyEvent.Raise(destroyEventArgs);

		// Unregister from events.
		m_pSource->UnregisterNewDataEvent(m_newDataHandle);
		m_newDataHandle = NULL;
	}
}

OniStatus PlayerStream::start()
{
	m_isStarted = true;
	return ONI_STATUS_OK;
}

void PlayerStream::stop()
{
	m_isStarted = false;
}

OniBool PlayerStream::IsReadyForData()
{
	return (m_pLastFrame == NULL) ? TRUE : FALSE;
}

PlayerSource* PlayerStream::GetSource()
{
	return m_pSource;
}

OniStatus PlayerStream::getProperty(int propertyId, void* pData, int* pDataSize)
{
	// Check if the property exists.
	m_cs.Lock();
	OniStatus rc = m_properties.GetProperty(propertyId, pData, pDataSize);
	if (rc != ONI_STATUS_OK)
	{
		rc = m_pSource->GetProperty(propertyId, pData, pDataSize);
	}
	m_cs.Unlock();

	return rc;
}

OniStatus PlayerStream::setProperty(int /*propertyId*/, const void* /*pData*/, int /*dataSize*/)
{
	return ONI_STATUS_ERROR;
}

OniStatus PlayerStream::RegisterReadyForDataEvent(ReadyForDataCallback callback, void* pCookie, OniCallbackHandle& handle)
{
	XnStatus rc = m_readyForDataEvent.Register(callback, pCookie, (XnCallbackHandle&)handle);
	if (rc != XN_STATUS_OK)
	{
		return ONI_STATUS_ERROR;
	}
	return ONI_STATUS_OK;
}

void PlayerStream::UnregisterReadyForDataEvent(OniCallbackHandle handle)
{
	m_readyForDataEvent.Unregister((XnCallbackHandle)handle);
}

OniStatus PlayerStream::RegisterDestroyEvent(DestroyCallback callback, void* pCookie, OniCallbackHandle& handle)
{
	XnStatus rc = m_destroyEvent.Register(callback, pCookie, (XnCallbackHandle&)handle);
	if (rc != XN_STATUS_OK)
	{
		return ONI_STATUS_ERROR;
	}
	return ONI_STATUS_OK;
}

void PlayerStream::UnregisterDestroyEvent(OniCallbackHandle handle)
{
	m_destroyEvent.Unregister((XnCallbackHandle)handle);
}

void ONI_CALLBACK_TYPE PlayerStream::OnNewDataCallback(const PlayerSource::NewDataEventArgs& newDataEventArgs, void* pCookie)
{
	PlayerStream* pStream = (PlayerStream*)pCookie;

	// Don't process new frames until the stream is started.
	if(!pStream->m_isStarted)
	{
		return;
	}

	pStream->m_cs.Lock();

	// Release last frame (if exists).
	if (pStream->m_pLastFrame != NULL)
	{
		pStream->releaseFrame(pStream->m_pLastFrame);
	}

	// Allocate new frame and fill it.
	pStream->m_pLastFrame = pStream->AllocateFrame();
	if (pStream->m_pLastFrame == NULL)
	{
		return;
	}

	OniFrame* pFrame = &pStream->m_pLastFrame->frame;

	// Set the cropping property.
	OniCropping cropping;
	cropping.enabled = FALSE;
	int dataSize = sizeof(cropping);
	pStream->m_pSource->GetProperty(ONI_STREAM_PROPERTY_CROPPING, &cropping, &dataSize);

	// Fill the frame.
	pFrame->frameIndex = newDataEventArgs.nFrameId;

	pFrame->videoMode.pixelFormat = pStream->m_videoMode.pixelFormat;
	pFrame->videoMode.resolutionX = pStream->m_videoMode.resolutionX;
	pFrame->videoMode.resolutionY = pStream->m_videoMode.resolutionY;
	pFrame->videoMode.fps = pStream->m_videoMode.fps;
	if (!cropping.enabled)
	{
		// Set the full resolution, stride and origin.
		pFrame->width = pStream->m_videoMode.resolutionX;
		pFrame->height = pStream->m_videoMode.resolutionY;
		pFrame->stride = pStream->m_stride;
		pFrame->cropOriginX = 0;
		pFrame->cropOriginY = 0;
		pFrame->croppingEnabled = FALSE;
	}
	else
	{
		// Take resolution, and origin from cropping and calculate new stride.
		pFrame->width = cropping.width;
		pFrame->height = cropping.height;
		pFrame->stride = (pStream->m_stride / pFrame->videoMode.resolutionX) * cropping.width;
		pFrame->cropOriginX = cropping.originX;
		pFrame->cropOriginY = cropping.originY;
		pFrame->croppingEnabled = TRUE;
	}
	pFrame->sensorType = pStream->m_pSource->GetInfo()->sensorType;
	pFrame->timestamp = newDataEventArgs.nTimeStamp;
	pFrame->dataSize = newDataEventArgs.nSize;
	memcpy(pFrame->data, newDataEventArgs.pData, pFrame->dataSize);

	pStream->m_cs.Unlock();

	// Process the new frame.
	pStream->raiseNewFrame(pStream->m_pLastFrame);
	pStream->m_pLastFrame = NULL;
}

OniDriverFrame* PlayerStream::AllocateFrame()
{
	// Get the video mode.
	int valueSize = sizeof(m_videoMode);
	OniStatus rc = m_pSource->GetProperty(ONI_STREAM_PROPERTY_VIDEO_MODE, &m_videoMode, &valueSize);
	if (rc != ONI_STATUS_OK)
	{
		XN_ASSERT(FALSE);
		return NULL;
	}

	// Get stride.
	valueSize = sizeof(m_stride);
	rc = m_pSource->GetProperty(ONI_STREAM_PROPERTY_STRIDE, &m_stride, &valueSize);
	if (rc != ONI_STATUS_OK)
	{
		XN_ASSERT(FALSE);
		return NULL;
	}

	int dataSize = m_videoMode.resolutionY * m_stride;
	OniDriverFrame* pFrame = (OniDriverFrame*)xnOSCalloc(1, sizeof(OniDriverFrame));
	if (pFrame == NULL)
	{
		XN_ASSERT(FALSE);
		return NULL;
	}

	pFrame->frame.data = xnOSMallocAligned(dataSize, XN_DEFAULT_MEM_ALIGN);
	if (pFrame->frame.data == NULL)
	{
		XN_ASSERT(FALSE);
		return NULL;
	}

	pFrame->pDriverCookie = xnOSMalloc(sizeof(PlayerStreamFrameCookie));
	((PlayerStreamFrameCookie*)pFrame->pDriverCookie)->refCount = 1;

	pFrame->frame.dataSize = dataSize;
	return pFrame;
}

void PlayerStream::addRefToFrame(OniDriverFrame* pFrame)
{
	++((PlayerStreamFrameCookie*)pFrame->pDriverCookie)->refCount;
}

void PlayerStream::releaseFrame(OniDriverFrame* pFrame)
{
	if (0 == --((PlayerStreamFrameCookie*)pFrame->pDriverCookie)->refCount)
	{
		xnOSFree(pFrame->pDriverCookie);
		xnOSFreeAligned(pFrame->frame.data);
		xnOSFree(pFrame);
	}
}

} // namespace oni_files_player
