#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

int main() {
    setlocale(0, "ru");
    // Создаем структуру для работы с процессами
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // Получаем снимок всех выполняющихся процессов
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Не удалось создать снимок процессов." << std::endl;
        return 1;
    }

    // Перебираем процессы и выводим их имена и идентификаторы
    if (Process32First(hSnapshot, &processEntry)) {
        do {
            std::wcout << L"Имя процесса: " << (WCHAR*)(processEntry.szExeFile) << std::endl;
            std::cout << "Идентификатор процесса: " << processEntry.th32ProcessID << std::endl;
            std::cout << std::endl;
        } while (Process32Next(hSnapshot, &processEntry));
    }

    // Закрываем снимок процессов
    CloseHandle(hSnapshot);

    return 0;
}
