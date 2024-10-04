#pragma once
#include <bitset>

#include "Common/WindowsErrors.h"

/**
* Open the serial port device
*/
HANDLE openDevice(LPCWSTR comNumber, DWORD baudRate);

/**
* Close the serial port device
*/
void closeDevice(HANDLE device);

/**
* Send a byte to the serial port device
*/
BOOL sendByte(HANDLE device, byte value);

BOOL readByte(HANDLE device, byte* value);