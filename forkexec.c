
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork(); // Create a new child process

    if (pid == -1) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This code is executed by the child process
        // Replace the child process with a new program
        execl("/bin/ls", "ls", "-l", NULL);
        // If execl returns, it means it failed
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // This code is executed by the parent process
        // Wait for the child process to finish
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new child process

    if (pid == -1) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This code is executed by the child process
        
        // Define the arguments for the new program
        char *args[] = {"/usr/bin/env", NULL};
        
        // Define the environment variables
        char *envp[] = {
            "MY_VARIABLE=Hello World",
            "PATH=/usr/bin:/bin",
            NULL // End of environment variables
        };
        
        // Execute the env command to print environment variables
        if (execve("/usr/bin/env", args, envp) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // This code is executed by the parent process
        // Wait for the child process to finish
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}
