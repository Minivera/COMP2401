
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_STRING_SIZE 25
#define ANOTHER_STRING_SIZE 45

int requiredStrLength(char *s1, char *s2);
int concatStrings(char *s1, char *s2, char *outString, int sizeOfOutsrting); 
int printLowerCaseInStringRecursive(char *s1); 


int main()

{
    int rc = 0;
    char s1[50] = "Tutorial 5";
    char *s2 = " is about strings!";
    char outString[OUT_STRING_SIZE];
    char anotherOutString[ANOTHER_STRING_SIZE];
    char *lowerCaseString = "THE sTART OF A NEW COuRSE cAN BE cHALLeNGING.  EsPECIALLY UsING LINUX.";

    rc = requiredStrLength(s1, s2);
    printf("concatenating s1 and s2 required a charcater array of size >= %d \n\n", rc);

    // test unsuccessful concatenation
    if (concatStrings(s1, s2, outString, OUT_STRING_SIZE) == 0) {
        printf("conactenated string = %s \n\n", outString); 
    } else {
        printf("s1 =%s and s2= %s could not be concatenated \n\n", s1, s2);
    }

    // test successfule concatenation
    if (concatStrings(s1, s2, anotherOutString, ANOTHER_STRING_SIZE) == 0) {                                                
        printf("conactenated string = %s \n\n", anotherOutString);                                         
    } else {                                                                                        
        printf("s1 =%s and s2= %s could not be concatenated \n\n", s1, s2);                         
    }                                                                                               
                                                                                                    
     
    // test printing only lower case letters
    printLowerCaseInStringRecursive(lowerCaseString);                                                               


    return(0);
}

/***************************************************************************/

/* Purpose: determines the amount of memory that is required to store a string
that is a concatenation of the two input strings

Input:
s1 - first string
s2 - second string

Output:
None

Return:
The number of bytes required to store a concatenation of the two input strings

*/

int requiredStrLength(char *s1, char *s2)
{
    return strlen(s1) + strlen(s2);
}   



/***************************************************************************/

/* Purpose: concatenate two input string and store it in the output string.  In doing so
s1 is the first string and the conctenated string is s2

Input:
s1 - first string
s2 - second string
sizeOfOutString - the amount of memory that was allocated to the outString

Output:
outString - holds the conctenated string

Return:
0 - if the string were concatenated
1 - if the two string could not be concatenated

*/


int concatStrings(char *s1, char *s2, char *outString, int sizeOfOutsrting)

{
    if (requiredStrLength(s1, s2) < sizeOfOutsrting)
    {
        strcat(outString, s1);
        strcat(outString, s2);
        return 0;
    }
    else
    {
        return 1;
    }
}   

/***************************************************************************/
/* Purpose: prints only the lower case letters in a string using iterative operation
Input:
s1 - a string

Output:
None

Return:
0

*/
int printLowerCaseInStringIterative(char *s1) 
{
    for(int i = 0; i < strlen(s1); i++)
    {
		if (s1[i] >= 97 && s1[i] <= 122)
		{
			printf("%c", s1[i]);
		}
    }
}   



/***************************************************************************/
/* Purpose: prints only the lower case letters in a string using recurive operation
Input:
s1 - a string

Output:
None

Return:
0

*/
int printLowerCaseInStringRecursive(char *s1) 

{
	if (*s1)
	{
        if (*s1 >= 97 && *s1 <= 122)
		{
			printf("%c", *s1);
		}
        printLowerCaseInStringRecursive(s1 + 1);
    }
}   

