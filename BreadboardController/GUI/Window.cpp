#include "Window.h"

HWND createWindow() {
    HINSTANCE hInst = GetModuleHandleW(NULL);

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = L"Main class";

    RegisterClassW(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                                                      // Optional window styles.
        L"Main class",                                          // Window class
        L"Breadboard Project",                                  // Window text
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_MAXIMIZE,         // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,               // Parent window    
        NULL,               // Menu
        hInst,              // Instance handle
        NULL                // Additional application data
    );

    return hwnd;
}

void msgLoop() {
    MSG msg = { };
    while (GetMessageW(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}