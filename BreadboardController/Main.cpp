#include "SerialPort.h"
#include "GUI/Window.h"

HANDLE serialDevice;

void Button1Handler() {
	std::cout << "FunctionPointerWorking" << std::endl;

	sendByte(serialDevice, 0b01010010);
}

int main() {
	HWND hwnd = createWindow();

	if (hwnd == NULL) {
		std::cout << "Failed to create window " << std::endl;

		return -1;
	}

	createButton(hwnd, { 10, 10 }, { 100, 20 }, &Button1Handler);

	serialDevice = openDevice(L"COM6", CBR_110);

	msgLoop();

	closeDevice(serialDevice);
}