#include <iostream>
#include <windows.h>

int main() {
    for (int i = 0; i < 125; ++i)
    {
        DWORD processId = GetCurrentProcessId();
        std::cout <<i<< ". PID (OS_03_02_2): " << processId << std::endl;
        Sleep(500);
    }
    std::cout << "----------------END OS_03_02_2---------------" << std::endl;
    return 0;
}