#include "..\Common\WindowsErrors.h"

HWND createWindow();

void msgLoop();

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);