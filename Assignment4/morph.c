#include <stdio.h>
#include "unistd.h"

/*
 * Morph morphs the current program into the isPrime program
 * @param number The number to check using the isPrime program
 * @returns Returns -1 if the morph could not happen.
 */
int morph(char *number)
{
    char *params[] = {"isPrime", number, NULL};
    return execv("./isPrime", params);
}

/*
 * Finds the given id's index in the array of process ids
 * @param childrenIds Array of integer containing the process ids.
 * @param idToFind The id to find inside the array.
 * @param totalIds The length of the array of process ids.
 * @return Returns the index of the process id or -1 if it could not be found.
 */
int findPid(int *childrenIds, int idToFind, int totalIds)
{
    for (int i = 0; i < totalIds; i++)
    {
        if (childrenIds[i] == idToFind)
        {
            return i;
        }
    }
    return -1;
}