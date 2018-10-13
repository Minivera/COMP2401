/*

File encrypt.c


Purpose: simulate the encryption and traqnsmisstion of a message.

The program encrypts a given message and trasmits it as a sequence of intergers. 

Usage: start the program
1. enter a message to be transmitted
2. enter a key that will be used for the encryption

Revision:
a. 2017,Doron Nussbaum - Initial code

*/

/************************************************************************/

// INCLUDE FILES


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES



#define MAX_MSG_LENGTH 2048


/************************************************************************/
// FUNCTION PROTOTYPES


int readMessage(char *s, int len, int *numRead);


/************************************************************************/




int main(int argc, char *argv[])
{
	char msg[MAX_MSG_LENGTH] = "CS";  // message
	int numRead = 0;  // number of characters in the message
	int i;
	char key = 0;

	// read the message
	printf("Please enter a message to encrypt: ");
	readMessage(msg, MAX_MSG_LENGTH, &numRead);

	// get the key
	printf("Please enter the encryption key: ");
	// note that the key is a char and therefore you will need to use 
	// the %hhd in the format string the scanf() function.
	scanf("%hhd", &key);

	// encode the message
	for (i = 0; i < numRead; i++) {
		encryptChar(&msg[i], key, i);
	}

	// print the message
	printf("\n\n Transmitted message:\n");
	for (i = 0; i < numRead; i++) {
		printf("%d ", msg[i]);
	}
	printf("\n");

	return(0);
}




/***********************************************************************************/
/* reads a message from the user

input
len - maximum length of mesage that should be read

output
s - contains the message
numRead - the number of characters in the message

assumption - s is valid
*/

int readMessage(char *s, int len, int *numRead)
{
	int i;
    int rc = 1;
	*numRead = 0;

	// read the message one characger at the time until the characer '\n' 
	// was reached
	for (i = 0; i < len, rc != 0; i++) {
		rc = scanf("%c", &s[i]);
		if (s[i] == '\n') break;
		(*numRead)++;
	}
	return(0);
}
