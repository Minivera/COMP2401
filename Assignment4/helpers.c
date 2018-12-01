#include <stdio.h>
#include "helpers.h"

/*
 * fexists checks if the file under the filename given as arguments exists.
 * @param fileName an array of char containing the filename
 * @returns Whether or not the file exists
 */
int fexists(char *fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return 0;
    }
    fclose(file);
    return 1;
}