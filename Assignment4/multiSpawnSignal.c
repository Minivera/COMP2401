#include <stdio.h>
#include "helpers.h"
#include "morph.h"
#include "unistd.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sighandler(int);

int totalProcesses = 0;
int processFinished = 0;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Filename missing, usage %s filename \n", argv[0]);
        return 2;
    }

    // check if file exists
    if(!fexists(argv[1]))
    {
        printf("File %s does not exists \n", argv[1]);
        return 3;
    }
    printf("File %s exists, opening \n", argv[1]);
    
    FILE* file = fopen(argv[1], "rb+");
    //Check the file's size and divide by the size of an unsigned int
    int numberCount = fsize(file) / sizeof(unsigned int);
    totalProcesses = numberCount;
    unsigned int num[numberCount];
    // Read all the elements in the file
    fread(&num, sizeof(unsigned int) * numberCount, 1, file);
    fclose(file);
    
    // Starts a signal handle on the special SIGUSR1, will show the number of process finished and running when called
    // To test, change the sleep time of isPrime to 1000 and execute `kill -10 <process>` while this program runs
    signal(SIGUSR1, sighandler);
    
    int childProcessIds[numberCount];
    // Loop for each number.
    for (int i = 0; i < numberCount; i++)
    {
        pid_t pid = fork();
        
        if (pid == 0)
        {
            // For the child process, we need to use process safe memory with a static
            // size buffer. Otherwise, the copied stacks will smash each other.
            char number[64] = {0};
            snprintf(number, 63, "%d", num[i]);
            morph(number);
        }
        else
        {
            // For the parent process, save the id.
            childProcessIds[i] = pid;
        }
    }
    
    int numberChildren = numberCount - 1;
    int status = 0;
    // Still on the parent, loop on the number of childrens
    while (numberChildren > 0) 
    {
        // Wait on any children
        pid_t wpid = waitpid(-1, &status, 0);
        // Get the status code and print the result from the process id
        int statusCode = WEXITSTATUS(status);
        if (statusCode)
        {
             printf("Number %d is a prime number \n", num[findPid(childProcessIds, wpid, numberCount)]);
        }
        else
        {
             printf("Number %d is not a prime number \n", num[findPid(childProcessIds, wpid, numberCount)]);
        }
        // Reduce the number of children so we have an "end" clause.
        --numberChildren;
        processFinished++;
    }
    
    return 0;
}

void sighandler(int signum)
{
    printf("Signal %d received, %d processes have finished, %d remaining \n", signum, processFinished,
        totalProcesses - processFinished);
}