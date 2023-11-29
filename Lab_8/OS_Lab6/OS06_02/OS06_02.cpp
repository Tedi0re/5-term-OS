#include <iostream>
#include <Windows.h>
using namespace std;

//wmic memorychip
//Get-CimInstance Win32_PhysicalMemory
//systeminfo
int main()
{
	for (int i = 1; i <= 1000000; ++i)
	{
		cout << i << ". OS06_02" << "\n";
		Sleep(1000);
	}
}
