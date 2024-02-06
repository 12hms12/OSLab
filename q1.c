#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t p;

    p = fork();

    if (p < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (p == 0) {
        printf("\nChild : PID = %d, PPID = %d\n", getpid(), getppid());

    } else {
        printf("\nParent : PID = %d, PPID = %d\n", getpid(), getppid());

    }

    return 0;
}
