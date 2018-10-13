/*

File decrypt.c


Purpose: simulate receiving a transmitted message and decypting it

It decodes a trasmitted message and prints the content of the message.
The converted message uses 1-bit error correction code.


Usage: start the program
enter a transmitted message
enter the key

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


#define XSTR(A) STR(A)
#define STR(A) #A
#define MAX_MSG_LENGTH 2048
#define MAX_INPUT_LENGTH  4096


/************************************************************************/
// FUNCTION PROTOTYPES


int readMessage(char *s, int len, int *numRead);


/************************************************************************/


int main(int argc, char *argv[])

{
	int rc = 0;		// return code

	char msg[MAX_MSG_LENGTH];  // message
	int numRead = 0;  // number of characters in the message
	int i;
	char  key = 0;

	// read the message
	printf("Please enter the encrypted message: ");
	readMessage(msg, MAX_MSG_LENGTH, &numRead);

	// get the key
	printf("Please enter the encryption key: ");
	scanf("%hhd", &key);


	// decrypt the message one character at a time using decryptChar()
	for (i = 0; i < numRead; i++)
	{
		decryptChar(&msg[i], key, i);
	}

	// print the message 
	printf("\n\nTransmitted message:\n");
	for (i = 0; i < numRead; i++)
	{
		printf("%c", msg[i]);
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

int readMessage(char *msg, int len, int *numRead)
{
	int i;
	int rc;
	char s[MAX_INPUT_LENGTH + 1];
	char *token = NULL;
	*numRead = 0;

	s[MAX_INPUT_LENGTH] = '\0';
	scanf("%"XSTR(MAX_INPUT_LENGTH)"[^\n]s", s);
	token = strtok(s, " ");

	for (i = 0; token != NULL && i < len; token = strtok(NULL, " "), i++) {
		rc = sscanf(token, "%hhd", &msg[i]);
	}

	*numRead = i; // set the number of read integers

	// empty the input buffer
	for (; getchar() != '\n';);
}