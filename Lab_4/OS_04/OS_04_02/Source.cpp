#include <iostream>
#include <windows.h>
#include <thread>

void OS_04_02_T1() 
{
    for (int i = 0; i < 50; ++i) 
    {
        DWORD processId = GetCurrentProcessId();
        DWORD threadId = GetCurrentThreadId();
        std::cout << "PID(OS_04_02_T1): " << processId << std::endl;
        std::cout << "TID(OS_04_02_T1): " << threadId << std::endl;
        Sleep(1000);
    }
}

void OS_04_02_T2()
{
    for (int i = 0; i < 125; ++i)
    {
        DWORD processId = GetCurrentProcessId();
        DWORD threadId = GetCurrentThreadId();
        std::cout << "PID(OS_04_02_T2): " << processId << std::endl;
        std::cout << "TID(OS_04_02_T2): " << threadId << std::endl;
        Sleep(1000);
    }
}

int main() 
{
    std::thread thread1(OS_04_02_T1);
    std::thread thread2(OS_04_02_T2);
    for (int i = 0; i < 100; i++)
    {
        DWORD processId = GetCurrentProcessId();
        std::cout << "PID(OS_04_02): " << processId << std::endl;
        Sleep(1000);
    }
    thread1.join();
    thread2.join();
    return 0;
}
//Get-Process OS_04_02 | Select-Object -ExpandProperty Threads