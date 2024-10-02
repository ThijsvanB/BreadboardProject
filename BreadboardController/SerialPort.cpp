#include "SerialPort.h"

HANDLE openDevice() {
	std::cout << "initializing handle\n";

	HANDLE hSerial;

	hSerial = CreateFile(L"COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hSerial == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			std::cout << "file not found\n";
		}
		else {
			std::cout << "other error\n";

			printLastError();
		}

		return NULL;
	}

	std::cout << "Setting dcb params\n";

	DCB dcbSerialParams = { 0 };

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams)) {
		std::cout << "Failed get comm state\n";

		printLastError();

		CloseHandle(hSerial);
		return NULL;
	}

	dcbSerialParams.BaudRate = CBR_115200;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;

	if (!SetCommState(hSerial, &dcbSerialParams)) {
		std::cout << "Failed set comm state\n";

		printLastError();

		CloseHandle(hSerial);
		return NULL;
	}

	std::cout << "Setting timeouts\n";

	COMMTIMEOUTS timeouts = { 0 };

	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(hSerial, &timeouts)) {
		std::cout << "Failed set comm timeouts";

		printLastError();

		CloseHandle(hSerial);
		return NULL;
	}

	return hSerial;
}

void closeDevice(HANDLE device) {
	CloseHandle(device);
}

BOOL sendByte(HANDLE device, byte value) {
	DWORD bytesWritten;

	BOOL success = WriteFile(device, &value, 1, &bytesWritten, NULL);

	//std::cout << success << " Written " << bytesWritten << std::endl;

	if (!success) {
		printLastError();
	}

	return success;
}