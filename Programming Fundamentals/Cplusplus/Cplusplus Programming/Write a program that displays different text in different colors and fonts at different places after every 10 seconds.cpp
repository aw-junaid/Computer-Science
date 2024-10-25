#include <windows.h>
#include <time.h>

#define TIMER_ID 1
#define TIMER_INTERVAL 10000 // 10 seconds
#define MAX_TEXT_LENGTH 50
#define MAX_FONT_SIZE 36

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Register window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszClassName = TEXT("RandomTextClass");
    RegisterClass(&wc);

    // Create window
    HWND hwnd = CreateWindowEx(0, TEXT("RandomTextClass"), TEXT("Random Text"),
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                               CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    // Show window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Set timer to call update function every 10 seconds
    SetTimer(hwnd, TIMER_ID, TIMER_INTERVAL, NULL);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Clean up
    KillTimer(hwnd, TIMER_ID);
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_TIMER:
        // Generate random text, color, font, and position
        TCHAR text[MAX_TEXT_LENGTH];
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        COLORREF color = RGB(r, g, b);
        int font_size = rand() % MAX_FONT_SIZE + 12; // Minimum font size of 12
        HFONT font = CreateFont(font_size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                                ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, NULL);
        int x = rand() % (GetSystemMetrics(SM_CXSCREEN) - 100); // Leave some margin on the sides
        int y = rand() % (GetSystemMetrics(SM_CYSCREEN) / 2);  // Only show upper half of the screen
        wsprintf(text, TEXT("Random Text %d"), rand());

        // Draw text on screen
        HDC hdc = GetDC(hwnd);
        HBRUSH brush = CreateSolidBrush(color);
        SelectObject(hdc, brush);
        SelectObject(hdc, font);
        TextOut(hdc, x, y, text, lstrlen(text));
        DeleteObject(brush);
        DeleteObject(font);
        ReleaseDC(hwnd, hdc);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}
