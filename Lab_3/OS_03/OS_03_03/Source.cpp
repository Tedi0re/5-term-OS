#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

int main() {
    setlocale(0, "ru");
    // ������� ��������� ��� ������ � ����������
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // �������� ������ ���� ������������� ���������
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "�� ������� ������� ������ ���������." << std::endl;
        return 1;
    }

    // ���������� �������� � ������� �� ����� � ��������������
    if (Process32First(hSnapshot, &processEntry)) {
        do {
            std::wcout << L"��� ��������: " << (WCHAR*)(processEntry.szExeFile) << std::endl;
            std::cout << "������������� ��������: " << processEntry.th32ProcessID << std::endl;
            std::cout << std::endl;
        } while (Process32Next(hSnapshot, &processEntry));
    }

    // ��������� ������ ���������
    CloseHandle(hSnapshot);

    return 0;
}
