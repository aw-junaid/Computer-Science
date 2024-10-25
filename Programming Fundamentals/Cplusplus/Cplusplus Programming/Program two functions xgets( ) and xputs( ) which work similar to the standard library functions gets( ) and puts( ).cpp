#include <iostream>
#include <cstring>

// xgets(): function to read a line of text from the console
// The function accepts a char pointer and the maximum number of characters to be read
void xgets(char *str, int size) {
    int i = 0;
    char ch;
    while (i < size - 1) {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
}

// xputs(): function to display the string on the console
void xputs(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
    }
}

int main() {
    char str[50];
    std::cout << "Enter a string: ";
    xgets(str, 50);
    std::cout << "The string entered is: ";
    xputs(str);
    return 0;
}
