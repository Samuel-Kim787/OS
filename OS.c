#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *arg[]) {
    // We'll try to run the parameters just so it does not provide warnings.
    (void)argc;
    (void)arg;

    int pid; pid = fork(); // This function creates a new "process" that provides a number.

    if(pid < 0) // if the number is negative or less than 0 then print we simply print "fork failed"
    {
        printf("fork failed");
        exit(1);
    }

    else if(pid == 0)
    {
        execlp("whoami", "ls", NULL);
        exit(0);
    }

    else // now if the process number is not less than or equal to 0 then it will simply print the process ID.
    {
        printf("\nProcess ID is: %d\n", getpid());
        wait(NULL);
        exit(0);
    }
}









