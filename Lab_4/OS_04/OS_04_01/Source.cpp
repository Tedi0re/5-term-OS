#include <iostream>
#include <windows.h>

int main() {
    while (true) {
        DWORD processId = GetCurrentProcessId();
        DWORD threadId = GetCurrentThreadId();
        std::cout << "PID: " << processId << std::endl;
        std::cout << "TID: " << threadId << std::endl;
        Sleep(1000);
    }

    return 0;
}
//Get-Process OS_04_01 | Select-Object -ExpandProperty Threads
//