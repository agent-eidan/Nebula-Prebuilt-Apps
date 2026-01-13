// written by eidan on 12/01/2026.
//clock

#include <iostream>
#include <ctime>
#include <unistd.h>

//only supports PowerShell using ANSI
#ifdef _WIN32
#include <windows.h>
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
}
#else
void enableANSI() {}
#endif

void move_cursor(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H";
}

int main() {
    enableANSI();

    std::cout << "\033[2J";

    // Marco estático
    move_cursor(1, 1);
    std::cout << "|------------------------------|";
    move_cursor(2, 1);
    std::cout << "|-------------Clock-----------|";
    move_cursor(3, 1);
    std::cout << "|------------------------------|";
    move_cursor(4, 1);
    std::cout << "|------------------------------|";
    move_cursor(5, 1);
    std::cout << "|------------------------------|";

    while (true) {
        std::time_t t = std::time(nullptr);
        std::tm* tm = std::localtime(&t);

        char timebuf[9];
        std::strftime(timebuf, sizeof(timebuf), "%H:%M:%S", tm);

        char datebuf[11];
        std::strftime(datebuf, sizeof(datebuf), "%d/%m/%y", tm);

        move_cursor(3, 1);
        std::cout << "|------------" << timebuf << "---------|";

        move_cursor(4, 1);
        std::cout << "|------------" << datebuf << "---------|";

        std::cout.flush();
        Sleep(1000);
    }
}
