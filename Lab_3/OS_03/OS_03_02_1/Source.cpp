#include <iostream>
#include <windows.h>

int main() {
    for (int i = 0; i < 50; ++i)
    {
        DWORD processId = GetCurrentProcessId();
        std::cout <<i<< ". PID (OS_03_02_1): " << processId << std::endl;
        Sleep(500);
    }
    std::cout << "----------------END OS_03_02_1---------------" << std::endl;

    return 0;
}