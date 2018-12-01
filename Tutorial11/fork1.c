

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{ 
    int pid;
    int status;
    
    printf("Ready to fork...\n"); 
    pid = fork();
    if (pid == 0)
    {
        // child process instructions
        printf("Child process pid=%d parent process id=%d \n", getpid(), getppid());
        return(55);
    }
    else if (pid > 0)
    {
        // parent process instructions
        printf("\t Parent process pid=%d child process id=%d \n", getpid(), pid);
        int cpid = wait(&status);
        printf("\t Parent process pid=%d wait on child id=%d \n", getpid(), cpid);
        if (WIFEXITED(status))
        {
            printf("Child has returned the value %d \n", WEXITSTATUS(status)); 
        }
        return(0);
    }
    else
    {
        // pid < 0 – an error occurred during the form operation
        printf("\t ERROR - parent process pid=%d could not fork a child process \n", getpid());
        return(1);
    }
}

