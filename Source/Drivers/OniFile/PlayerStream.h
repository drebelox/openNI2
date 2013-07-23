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
/// Contains the declaration of Stream class that implements a stream from 
/// a virtual OpenNI device.

#ifndef __PLAYER_STREAM_H__
#define __PLAYER_STREAM_H__

#include "Driver/OniDriverAPI.h"
#include "PlayerProperties.h"
#include "PlayerSource.h"
#include "XnOSCpp.h"

namespace oni_file {

class Decoder;

/// Implements a stream from a virtual OpenNI device.
class PlayerStream : public oni::driver::StreamBase
{
public:

	// General stream event.
	typedef struct 
	{
		PlayerStream* pStream;
	} StreamEventArgs;
	typedef xnl::Event<StreamEventArgs> StreamEvent;
	typedef void (ONI_CALLBACK_TYPE* StreamCallback)(const StreamEventArgs& streamEventArgs, void* pCookie);

	// Ready for data event.
	typedef StreamEventArgs ReadyForDataEventArgs;
	typedef StreamEvent		ReadyForDataEvent;
	typedef StreamCallback  ReadyForDataCallback;

	// Destroy event.
	typedef StreamEventArgs DestroyEventArgs;
	typedef StreamEvent		DestroyEvent;
	typedef StreamCallback  DestroyCallback;

public:
	/// Constructor.
    PlayerStream(PlayerSource* pSource);

	/// Destructor.
	virtual ~PlayerStream();

    /// Initialize the stream object.
    OniStatus Initialize();

    /// @copydoc OniStreamBase::start()
    virtual OniStatus start();

	/// has start() been called on this stream already?
	bool isStreamStarted() { return m_isStarted; }

    /// @copydoc OniStreamBase::stop()
    virtual void stop();

	/// @copydoc OniStreamBase::addRefToFrame()
	virtual void addRefToFrame(OniDriverFrame* pFrame);

	/// @copydoc OniStreamBase::releaseFrame()
	virtual void releaseFrame(OniDriverFrame* pFrame);

	// Return whether the stream is ready to receive data.
	OniBool IsReadyForData();

	// Return the player source the stream was created on.
	PlayerSource* GetSource();

    /// @copydoc OniStreamBase::getProperty(int,void*,int*)
    virtual OniStatus getProperty(int propertyId, void* pData, int* pDataSize);

	/// @copydoc OniStreamBase::setProperty(int,void*,int*)
	virtual OniStatus setProperty(int propertyId, const void* pData, int dataSize);

	// Register for 'ready for data' event.
	OniStatus RegisterReadyForDataEvent(ReadyForDataCallback callback, void* pCookie, OniCallbackHandle& handle);

	// Unregister from 'ready for data' event.
	void UnregisterReadyForDataEvent(OniCallbackHandle handle);

	// Register for 'destroy' event.
	OniStatus RegisterDestroyEvent(DestroyCallback callback, void* pCookie, OniCallbackHandle& handle);

	// Unregister from 'destroy' event.
	void UnregisterDestroyEvent(OniCallbackHandle handle);

private:
	void destroy();

    void MainLoop();
	static XN_THREAD_PROC ThreadProc(XN_THREAD_PARAM pThreadParam);

	// Callback to be called when new data is available.
	static void ONI_CALLBACK_TYPE OnNewDataCallback(const PlayerSource::NewDataEventArgs& newDataEventArgs, void* pCookie);

	OniDriverFrame* AllocateFrame();

// Data members
private:

	// Source the stream was created on.
	PlayerSource* m_pSource;

	// Stream properties.
    PlayerProperties m_properties;

	// Pointer to last received frame.
	OniDriverFrame* m_pLastFrame;

	// Current video mode.
	OniVideoMode m_videoMode;

	// Current map stride.
	int m_stride;

	// Handle to new data callback.
	OniCallbackHandle m_newDataHandle;

	// Ready for data event.
	ReadyForDataEvent m_readyForDataEvent;

	// Destroy event.
	DestroyEvent m_destroyEvent;

	// Critical section.
	xnl::CriticalSection m_cs;

	// Are we streaming right now?
	bool m_isStarted;
};

} // namespace oni_files_player

#endif //__PLAYER_STREAM_H__
