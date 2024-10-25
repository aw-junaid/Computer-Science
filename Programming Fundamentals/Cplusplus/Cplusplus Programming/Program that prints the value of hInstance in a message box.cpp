#include <windows.h>
#include <cstdio>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    char buffer[256];
    sprintf(buffer, "hInstance: 0x%p", hInstance);
    MessageBox(NULL, buffer, "Instance Handle", MB_OK);
    return 0;
}
