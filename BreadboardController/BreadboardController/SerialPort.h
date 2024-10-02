#pragma once
#include "WindowsErrors.h"

/**
* Open the serial port device
*/
HANDLE openDevice();

/**
* Close the serial port device
*/
void closeDevice(HANDLE device);

/**
* Send a byte to the serial port device
*/
BOOL sendByte(HANDLE device, byte value);