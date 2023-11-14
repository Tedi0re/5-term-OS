#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>


/*
	sudo cat /proc/pid/maps
	pmap -X pid
	objdump -f ./6.out
	size -Ax ./6.out
	.text - секция с кодом (+константы)
	.data - инициализированные данные
	.bss  - неинициализированные данные
*/
int main()
{
	pid_t pid = getpid();
	nice(0);

	for (int i = 0; i < 10000000; i++)
	{
		printf("[OS06_06] PID = %d\n", pid);
		sleep(1);
	}
	exit(0);
}