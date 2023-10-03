#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
       for (int i = 0; i < 50; ++i)
       {
           pid_t processId = getpid();
           printf("PID (OS03_05_1): %d\n", processId);
           sleep(1);
       }
   return 0;
}
