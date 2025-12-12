#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>   // Needed for wait()

int main(int argc, char *argv[])   // main should return int
{
    int pid = fork();

    if (pid < 0) {
        printf("fork failed\n");   // fixed quotes and added newline
        exit(1);
    }
    else if (pid == 0) {
        // execlp arguments: first is program, second is argv[0] (usually same as program name)
        execlp("whoami", "whoami", NULL);
        perror("execlp failed");   // good practice to show error if execlp fails
        exit(1);
    }
    else {
        printf("\nProcess ID is: %d\n", getpid());
        wait(NULL);   // wait for child process
        exit(0);
    }
}
