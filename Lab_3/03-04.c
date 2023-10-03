
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    while (1) {
        pid_t processId = getpid();
        printf("PID: %d\n", processId);
        sleep(1);
    }

    return 0;
}
