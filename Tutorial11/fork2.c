#include "stdio.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int status;
    char *param[4];
    param[0] = "morphed";
    param[1] = "55";
    param[2] = "Second Command Parameter";
    param[3] = "Third Command Parameter";
    param[4] = NULL;
    int pid = fork();
    
    if (pid == 0)
    {
        // child process instructions
        int rc;
        rc = execv("./morphed", param);
        printf("This should not be printed \n"); // this should not be executed because
        // the child is executing a new program
    }
    else
    {
        // parent process instructions
        printf("Parent program \n");
        do {
            pid_t wpid = wait(&status);
            if(wpid == pid)
            {
                 printf("Child has returned the value %d \n", WEXITSTATUS(status));
            }
        } while(!WIFEXITED(status));
    }
}
