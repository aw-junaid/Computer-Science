#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int result = MessageBox(NULL, "Do you want to continue?", "Message Box", MB_YESNOCANCEL | MB_ICONQUESTION);
    switch (result) {
        case IDYES:
            MessageBox(NULL, "You clicked 'Yes'", "Message Box", MB_OK | MB_ICONINFORMATION);
            break;
        case IDNO:
            MessageBox(NULL, "You clicked 'No'", "Message Box", MB_OK | MB_ICONINFORMATION);
            break;
        case IDCANCEL:
            MessageBox(NULL, "You clicked 'Cancel'", "Message Box", MB_OK | MB_ICONINFORMATION);
            break;
    }
    return 0;
}
