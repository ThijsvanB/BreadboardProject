#include "SerialPort.h"
#include "GUI/Window.h"

int main() {
	HWND hwnd = createWindow();

	if (hwnd == NULL) {
		std::cout << "Failed to create window " << std::endl;

		return -1;
	}

	msgLoop();
}