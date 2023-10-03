#include <iostream>
#include <windows.h>
#include <thread>

void OS_04_04_T1()
{
    for (int i = 0; i < 50; ++i)
    {
        if(i == 25)
        {
            std::cout << "Theard 1 SLEEP" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(15));
            std::cout << "Theard 1 RUN" << std::endl;
        }
        DWORD processId = GetCurrentProcessId();
        DWORD threadId = GetCurrentThreadId();
        std::cout << i << ". PID(OS_04_04_T1): " << processId << std::endl;
        std::cout << i << ". TID(OS_04_04_T1): " << threadId << std::endl;
        Sleep(1000);
    }
}

void OS_04_04_T2()
{
    for (int i = 0; i < 125; ++i)
    {
        if (i == 80)
        {
            std::cout << "Theard 2 SLEEP" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::cout << "Theard 2 RUN" << std::endl;
        }
        DWORD processId = GetCurrentProcessId();
        DWORD threadId = GetCurrentThreadId();
        std::cout << i << ". PID(OS_04_04_T2): " << processId << std::endl;
        std::cout << i << ". TID(OS_04_04_T2): " << threadId << std::endl;
        Sleep(1000);
    }
}

int main()
{
    std::thread thread1(OS_04_04_T1);
    std::thread thread2(OS_04_04_T2);
    for (int i = 0; i < 100; i++)
    {
        DWORD processId = GetCurrentProcessId();
        std::cout << i << ". PID(OS_04_04): " << processId << std::endl;
        Sleep(1000);
    }
    thread1.join();
    thread2.join();
    return 0;
}
//Get-Process OS_04_04 | Select-Object -ExpandProperty Threads