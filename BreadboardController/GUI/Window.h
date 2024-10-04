#include "..\Common\WindowsErrors.h"

#define BUTTON1 100

HWND createWindow();

void msgLoop();

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void createButton(HWND parent, POINT position, POINT size, void (*func)());