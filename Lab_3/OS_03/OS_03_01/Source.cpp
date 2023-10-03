#include <iostream>
#include <windows.h>

int main() {
    while (true) {
        DWORD processId = GetCurrentProcessId();
        std::cout << "PID (OS_03_01:" << processId << std::endl;
        Sleep(1000);
    }

    return 0;
}
