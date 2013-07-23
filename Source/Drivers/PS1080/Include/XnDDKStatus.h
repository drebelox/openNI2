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
#ifndef _XN_DDK_STATUS_H_
#define _XN_DDK_STATUS_H_

#include <XnStatus.h>
#include <XnCommon.h>
#include <XnLib.h>

XN_PS_STATUS_MESSAGE_MAP_START(XN_ERROR_GROUP_DDK)
XN_STATUS_MESSAGE(XN_STATUS_DDK_NOT_INIT, "Xiron DDK library was not initialized!")
XN_STATUS_MESSAGE(XN_STATUS_DDK_ALREADY_INIT, "Xiron DDK library was already initialized!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_DEPTH_RESOLUTION, "Invalid Xiron I/O stream depth resolution!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_IMAGE_RESOLUTION, "Invalid Xiron I/O stream image resolution!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_FPS, "Invalid Xiron I/O stream frame per second!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_ZP_DISTANCE, "Invalid Xiron I/O stream zero plane distance!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_ZP_PIXEL_SIZE, "Invalid Xiron I/O stream zero pixel size!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_AUDIO_SAMPLE_RATE, "Invalid Xiron I/O stream audio sample rate!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_AUDIO_NUMBER_OF_CHANNELS, "Invalid number of audio channels!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEPTH_BUFFER_TOO_SMALL, "The stream frame depth buffer is too small to contain the requested data!")
XN_STATUS_MESSAGE(XN_STATUS_IO_IMAGE_BUFFER_TOO_SMALL, "The stream frame image buffer is too small to contain the requested data!")
XN_STATUS_MESSAGE(XN_STATUS_IO_MISC_BUFFER_TOO_SMALL, "The stream frame misc buffer is too small to contain the requested data!")
XN_STATUS_MESSAGE(XN_STATUS_IO_AUDIO_BUFFER_TOO_SMALL, "The stream frame audio buffer is too small to contain the requested data!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_MODE, "Invalid Xiron I/O device mode!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_MODE_NOT_SUPPORTED, "The requested Xiron I/O device mode is not supported!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_FUNCTION, "Invalid Xiron I/O device function!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_FUNCTION_NOT_SUPPORTED, "This function is not supported by this Xiron I/O device.")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_AUDIO_READ_MODE, "Invalid Xiron I/O stream audio read mode!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_AUDIO_CHUNK_SIZE, "Invalid Xiron I/O stream audio read chunk size!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRONG_VERSION, "This device version is not supported!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRONG_SERIAL, "The device serial number is incorrect!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_CONNECTION_STRING, "The connection string is invalid!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_NOT_RESPONDING, "The device is not responding!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_BAD_PARAM_NAME, "The device parameter name is invalid!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_FRAME_HEADER, "Invalid Xiron I/O stream frame header!")
XN_STATUS_MESSAGE(XN_STATUS_IO_STREAM_NOT_SEQUENTIAL, "This stream is not sequential!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_SERVER_CONNECT_FAILED, "Failed to connect to the server!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_RESPONSE_MAGIC, "Got and invalid response magic from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_RESPONSE_TYPE, "Got and invalid response type from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_RESPONSE_SIZE, "Got and invalid response size from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_RESPONSE_ORDER, "Got and invalid response order from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_MAGIC, "Invalid Xiron I/O stream magic!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_OPEN_BY_ANOTHER_APPLICATION, "A device is already used by another application!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_BAD_PARAM, "Bad Parameter sent to the device!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_USB_DISCONNECTED, "USB is disconnected!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_USB_ERROR, "USB operation error!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_BAD_MAGIC, "Device Protocol: Bad Magic Received!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_WRONG_OPCODE, "Device Protocol: Unexpected opcode!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_UNSUPPORTED_OPCODE, "Device Protocol: Unsupported opcode!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_WRONG_ID, "Device Protocol: Unexpected ID!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_UNKNOWN_ERROR, "Device Protocol: Unknown Error!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_INVALID_COMMAND, "Device Protocol: Command Invalid!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_BAD_PACKET_CRC, "Device Protocol: CRC Error!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_BAD_PACKET_SIZE, "Device Protocol: Wrong packet size!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_BAD_PARAMS, "Device Protocol: Bad Parameter sent!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_BAD_COMMAND_SIZE, "Device Protocol: Bad command size!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROTOCOL_NOT_READY, "Device Protocol: Device is not ready!")
XN_STATUS_MESSAGE(XN_STATUS_WRONG_AUDIO_READ_MODE, "Device Protocol: Audio read mode is wrong!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_UNSUPPORTED_MODE, "Unsupported Mode!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_UNSUPPORTED_PARAMETER, "Unsupported Parameter!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_NOT_ENOUGH_INFORMATION, "Not enough information!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_INVALID_MAX_SHIFT, "Max shift value is too big!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_INVALID_MAX_DEPTH, "Max depth value is too big!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_FRAMES_NOT_SYNCHED, "Didn't get any synched frame!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROJECTOR_FAULT, "A projector fault is in progress!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_SAFE_MODE, "Device is in safe mode. Cannot start any stream!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_OVERHEAT, "The device has overheat!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_ALREADY_EXISTS, "Property already exists!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_DONT_EXIST, "No such property!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_BAD_TYPE, "The property is of the wrong type!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_READ_ONLY, "The property is read only and cannot be set!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_WRITE_ONLY, "The property is write only and cannot be get!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_OUT_OF_RANGE, "Value is out of range and cannot be set!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_PROPERTY_SIZE_DONT_MATCH, "General buffer passed to property has the wrong size!")
XN_STATUS_MESSAGE(XN_STATUS_STREAM_OUTPUT_BUFFER_TOO_SMALL, "The stream output buffer is too small to contain the requested data!")
XN_STATUS_MESSAGE(XN_STATUS_STREAM_OUTPUT_SET_ALREADY_IN_SET, "The set already contains an object of that stream!")
XN_STATUS_MESSAGE(XN_STATUS_MODULE_IS_NOT_STREAM, "This module is not a stream!")
XN_STATUS_MESSAGE(XN_STATUS_UNSUPPORTED_STREAM, "This stream is not supported by the device!")
XN_STATUS_MESSAGE(XN_STATUS_STREAM_ALREADY_EXISTS, "This stream already exists!")
XN_STATUS_MESSAGE(XN_STATUS_STREAM_NOT_OPEN, "This stream is not open!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_STREAM_IS_ON, "This change can only be made while stream is Off!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_FILE_CORRUPTED, "The file is corrupted!")
XN_STATUS_MESSAGE(XN_STATUS_IO_NO_DEVICES, "No Xiron I/O devices found!")
XN_STATUS_MESSAGE(XN_STATUS_IO_FAILED_FREE_DEVICES, "Failed to free all Xiron I/O devices!")
XN_STATUS_MESSAGE(XN_STATUS_IO_FAILED_CLOSE_DEVICES, "Failed to close all Xiron I/O devices!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_NOT_FOUND, "Xiron I/O device not found!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_NOT_LOADED, "Xiron I/O device is not loaded!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_NOT_OPENED, "Xiron I/O device is not opened!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_DESCRIPTION_FAILED, "Xiron I/O failed to get a valid device description!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_ALREADY_EXISTS, "Xiron I/O device already exists!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_ILLEGAL_NAME, "Xiron I/O device name is illegal!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_VERSION_MISMATCH, "Xiron I/O device version mismatch!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_STRING_TOO_LONG, "Xiron I/O device string is too long!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INIT_FAILED, "Device failed to initialize properly!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_READ_FAILED, "Device read error!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_SET_CLOCK_FAILED, "Failed to set the device clock speed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_GET_CLOCK_FAILED, "Failed to get the device clock speed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_SET_TIMEOUT_FAILED, "Failed to set the device timeout!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRITE_FAILED, "Device write error!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRONG_STATE, "The device is in the wrong operation state to perform this function!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRONG_MODE, "The device is in the wrong mode to perform this function!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_DRIVER_ERROR, "The device low-level driver returned an error!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_WRONG_HARDWARE, "The device is incompatible with this hardware!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_OPEN_FAILED, "Failed to open the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_HARDWARE_OPEN_FAILED, "Failed to open the device hardware!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_GET_TYPE_FAILED, "Failed to get the device hardware type!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_CLOSE_FAILED, "Failed to close the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_IOCONTROL_FAILED, "Device I/O control failed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_IOOVERLAP_FAILED, "Device overlapped I/O failed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_MISSING_INIT_FILE, "The device initialization file is missing!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_INIT_FILE, "The device initialization file is invalid!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_DEPTH_BUFFER, "Got and invalid depth buffer from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_IMAGE_BUFFER, "Got and invalid image buffer from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_MISC_BUFFER, "Got and invalid misc buffer from the device!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_FAILED_SANITY_CHECK, "The device failed the startup sanity check!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_MISSING_FIRMWARE, "The device firmware file is missing!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_CLEAR_FIRMWARE_FAILED, "Failed to clear the device firmware!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_UPDATE_FIRMWARE_FAILED, "Failed to update the device firmware!")
XN_STATUS_MESSAGE(XN_STATUS_IO_NO_FREE_HANDLE, "Xiron I/O couldn't find a free device handle!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INVALID_STREAM_FLAG, "Invalid stream flag!")
XN_STATUS_MESSAGE(XN_STATUS_IO_INIT_FAILED, "Xiron I/O init failed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_SEEK_FAILED, "Xiron I/O seek failed!")
XN_STATUS_MESSAGE(XN_STATUS_IO_CALLBACK_FAILED, "The callback function failed!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_MODULE_NOT_FOUND, "The module (or stream) does not exist!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_MODULE_ALREADY_EXISTS, "The module (or stream) already exists!")
XN_STATUS_MESSAGE(XN_STATUS_IO_DEVICE_INVALID_SHARING, "Invalid Xiron I/O device sharing mode!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_SERVER_DISCONNECTED, "The server has disconnected!")
XN_STATUS_MESSAGE(XN_STATUS_DEVICE_SERVER_ALREADY_RUNNING, "The server is already running!")

XN_PS_STATUS_MESSAGE_MAP_END(XN_ERROR_GROUP_DDK)

#endif //_XN_DDK_STATUS_H_
