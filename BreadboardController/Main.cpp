#include "SerialPort.h"
#include "GUI/Window.h"

void Button1Handler() {
	std::cout << "FunctionPointerWorking" << std::endl;
}

void Button2Handler() {
	std::cout << "2" << std::endl;
}

int main() {
	HWND hwnd = createWindow();

	if (hwnd == NULL) {
		std::cout << "Failed to create window " << std::endl;

		return -1;
	}

	createButton(hwnd, { 10, 10 }, { 100, 20 }, &Button1Handler);
	createButton(hwnd, { 10, 40 }, { 100, 20 }, &Button2Handler);

	msgLoop();
}