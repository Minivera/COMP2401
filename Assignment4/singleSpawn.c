#include <stdio.h>
#include "helpers.h"
#include "morph.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>

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
    int num;
    char *number;
    fread(&num, sizeof(unsigned int), 1, file);
    fclose(file);
    sprintf(number, "%d", num);
    
    int pid = fork();
    int status = 0;
    
    if (pid == 0)
    {
        morph(number);
    }
    else
    {
        do {
            pid_t wpid = wait(&status);
            if(wpid == pid)
            {
                int statusCode = WEXITSTATUS(status);
                if (statusCode)
                {
                     printf("Number %s is a prime number \n", number);
                }
                else
                {
                     printf("Number %s is not a prime number \n", number);
                }
                return statusCode;
            }
        } while(!WIFEXITED(status));
    }
}