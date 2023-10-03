#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int main() 
{
    setlocale(0, "ru");
    STARTUPINFO si1;
    PROCESS_INFORMATION pi1;

    ZeroMemory(&si1, sizeof(si1));
    si1.cb = sizeof(si1);
    ZeroMemory(&pi1, sizeof(pi1));

    if (CreateProcess(L"D:\\5 семестр\\ОС\\Lab_3\\OS_03\\x64\\Debug\\OS_03_02_1.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
    {
        STARTUPINFO si2 = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION pi2;
        if (CreateProcess(L"D:\\5 семестр\\ОС\\Lab_3\\OS_03\\x64\\Debug\\OS_03_02_2.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2)) 
        {
            for (int i = 0; i < 100; ++i)
            {
                DWORD processId = GetCurrentProcessId();
                std::cout <<i<< ". PID (OS_03_02): " << processId << std::endl;
                Sleep(500);
            }
            WaitForSingleObject(pi1.hProcess, INFINITE);
            WaitForSingleObject(pi2.hProcess, INFINITE);

            CloseHandle(pi1.hProcess);
            CloseHandle(pi1.hThread);
            CloseHandle(pi2.hProcess);
            CloseHandle(pi2.hThread);
        }
        else 
        {
            std::cerr <<"03_02_2: " << GetLastError() << std::endl;
        }
    }
    else 
    {
        std::cerr << "03_02_1: " << GetLastError() << std::endl;
    }
    std::cout << "----------------END OS_03_02---------------" << std::endl;

    return 0;
}
