#include "main.h"
 
void NewConsole() {
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}

void CloseConsole() {
    FreeConsole();
    fclose(stdout);
}

void print_keybox(const char* key, const char* feature,  HANDLE hConsole, bool onoff) {
    std::cout << "[";
    SetConsoleTextAttribute(hConsole, (onoff ? FOREGROUND_GREEN : FOREGROUND_RED));
    std::cout << key;
    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "]" << " " << feature << "\n";
}