#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
    int running = 1;
    const char *exit = "exit";
    const char *cd = "exit";

    while (running){
        /* String to hold the command to run. */
        char command[256];
        printf("Enter the command to run: ");
        scanf("%s", command);

        /* Variable that will store the fork result. */
        pid_t pid;

        if (!strcmp(command, exit)) {
           running = 0;
        }

        /* Perform the actual fork. */
        pid = fork();
        if (pid < 0) {
            /* Error condition. */
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            /* Child process. */
            printf("Running...\n");
            execlp(command, command, NULL);
        } else {
            /* Parent process. */
            int result;
            wait(&result);
            printf("All done; result = %d\n", result);
        }
            printf("running value: %d\n", running);

    }
}
