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
#ifndef __XN_FRAME_STREAM_H__
#define __XN_FRAME_STREAM_H__

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "XnDeviceStream.h"
#include "XnFrameBufferManager.h"
#include "Driver/OniDriverTypes.h"

//---------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------

/** Represents a stream that is frame-based. */
class XnFrameStream : public XnDeviceStream
{
public:
	XnFrameStream(const XnChar* csType, const XnChar* csName);
	~XnFrameStream() { Free(); }

	//---------------------------------------------------------------------------
	// Getters
	//---------------------------------------------------------------------------
	inline XnUInt32 GetFPS() const { return (XnUInt32)m_FPS.GetValue(); }

	//---------------------------------------------------------------------------
	// Overridden Methods
	//---------------------------------------------------------------------------
	XnStatus Init();
	XnStatus Free();
	virtual void AddRefToFrame(OniFrame* pFrame);
	virtual void ReleaseFrame(OniFrame* pFrame);

protected:
	//---------------------------------------------------------------------------
	// Properties Getters
	//---------------------------------------------------------------------------
	inline XnActualIntProperty& FPSProperty() { return m_FPS; }

	//---------------------------------------------------------------------------
	// Getters
	//---------------------------------------------------------------------------
	XnStatus GetTripleBuffer(XnFrameBufferManager** pBufferManager);

	//---------------------------------------------------------------------------
	// Setters
	//---------------------------------------------------------------------------
	virtual XnStatus SetFPS(XnUInt32 nFPS);

	//---------------------------------------------------------------------------
	// Virtual Methods
	//---------------------------------------------------------------------------
	virtual XnStatus PostProcessFrame(OniFrame* /*pFrame*/) { return XN_STATUS_OK; }
	virtual XnStatus ReallocTripleFrameBuffer();

private:
	XnStatus OnRequiredSizeChanging();

	static XnStatus XN_CALLBACK_TYPE SetFPSCallback(XnActualIntProperty* pSenser, XnUInt64 nValue, void* pCookie);
	static XnStatus XN_CALLBACK_TYPE RequiredSizeChangedCallback(const XnProperty* pSenser, void* pCookie);
	static void XN_CALLBACK_TYPE OnTripleBufferNewData(const XnFrameBufferManager::NewFrameEventArgs& args, void* pCookie);

	//---------------------------------------------------------------------------
	// Members
	//---------------------------------------------------------------------------
	XnFrameBufferManager* m_pBufferManager;

	XnUInt32 m_nLastReadFrame; // the ID that was given

	XnActualIntProperty m_IsFrameStream;
	XnActualIntProperty m_FPS;
};

#endif //__XN_FRAME_STREAM_H__
