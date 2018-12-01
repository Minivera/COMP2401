#include <stdio.h>
#include "helpers.h"
#include "morph.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMBERS 10

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
    unsigned int num[MAX_NUMBERS];
    // Read the first 10 elements in the file, we consider that they all are unsigned int
    // and that, at least, 10 exists.
    fread(&num, sizeof(unsigned int) * MAX_NUMBERS, 1, file);
    fclose(file);
    
    int childProcessIds[MAX_NUMBERS];
    // Loop for each number.
    for (int i = 0; i < MAX_NUMBERS; i++)
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
    
    int numberChildren = MAX_NUMBERS - 1;
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
             printf("Number %d is a prime number \n", num[findPid(childProcessIds, wpid, MAX_NUMBERS)]);
        }
        else
        {
             printf("Number %d is not a prime number \n", num[findPid(childProcessIds, wpid, MAX_NUMBERS)]);
        }
        // Reduce the number of children so we have an "end" clause.
        --numberChildren;
    }
    
    return 0;
}