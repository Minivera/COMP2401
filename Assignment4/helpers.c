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

/*
 * fsize check the size of the given file pointer.
 * @param file The file pointer
 * @returns Returns the file size in bytes or -1 if the file is null.
 */
int fsize(FILE* file)
{
    if (file == NULL)
    {
        return -1;
    }
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}