#include <iostream>
#include <windows.h>

int main()
{
    // Get handle to the console window
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set console background color to dark blue
    SetConsoleTextAttribute(consoleHandle, BACKGROUND_BLUE);

    // Loop to fill entire console window with shades of blue
    for (int i = 1; i <= 16; i++)
    {
        // Set console background color to the next shade of blue
        SetConsoleTextAttribute(consoleHandle, BACKGROUND_BLUE | i);

        // Fill entire line with spaces to create a solid color
        for (int j = 0; j < 80; j++)
        {
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
