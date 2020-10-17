#include <stdio.h>
#include <windows.h>

WORD ChangeTextColour(HANDLE hcon, WORD colour) {
    CONSOLE_SCREEN_BUFFER_INFO conInfo;             // Screen buffer info.
    WORD resetAtt;                                  // Reset value.

    GetConsoleScreenBufferInfo(hcon, &conInfo);     // Fill the buffer.
    resetAtt = conInfo.wAttributes;                 // Assign reset value.

    SetConsoleTextAttribute(hcon, colour);          // Change the colour
    return resetAtt;                                
}

int main() {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);                              // Get handle to the console window.
    WORD reset = ChangeTextColour(hcon, FOREGROUND_RED | FOREGROUND_GREEN);     // Set the colour using and get value to reset text to white.
    printf("Printing so much text\n");
    printf("Dis is all a test\n");
    SetConsoleTextAttribute(hcon, reset);                                       // Reset colour.
    printf("Print me\n");
}