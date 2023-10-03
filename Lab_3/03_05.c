#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t childPid = fork();

    if (childPid == -1) {
        perror("Error!!!");
        return 1;
    }

    if (childPid == 0)
    {
 
         for (int i = 0; i < 50; ++i)
         {
     
         pid_t processId = getpid();
         printf("PID (OS03_05_1): %d\n", processId);

         sleep(1);
         }
          

     } 
     else
     {
        for (int i = 0; i < 100; ++i) {
            pid_t processId = getpid();
            printf("PID (OS03_05): %d\n", processId);
            sleep(1);
        }
        wait(NULL);
    }

    return 0;
}

