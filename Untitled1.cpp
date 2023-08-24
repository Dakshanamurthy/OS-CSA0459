#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid();  // Get the PID of the current process

    pid_t child_pid = fork();     // Create a new process

    if (child_pid < 0) {
        // Error handling if fork fails
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("PID: %d\n", getpid());        // Get child PID
        printf("Parent PID: %d\n", getppid()); // Get parent PID of the child
    } else {
        // Parent process
        printf("Parent Process:\n");
        printf("PID: %d\n", getpid());        // Get parent PID
        printf("Parent PID: %d\n", getppid()); // Get parent PID of the parent
    }

    return 0;
}