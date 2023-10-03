#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t childPid = fork();
    if (childPid == -1) 
    {
        perror("Ошибка при создании дочернего процесса");
        return 1;
    }
    if (childPid == 0) 
    {
        system("./03_05_1");
    }
    else 
    {
        for (int i = 0; i < 100; ++i) {
            pid_t processId = getpid();
            printf("PID (OS03_06): %d\n", processId);
            sleep(1);
        }
        wait(NULL);
    }
    return 0;
}

