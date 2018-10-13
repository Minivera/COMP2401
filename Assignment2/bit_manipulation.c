/*

File bit_manipulation.c

Purpose :
contains helper functions for manipulating bits


Revisions:
file created: Doron Nussbaum

* /

/************************************************************************/

// INCLUDE FILES

#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES


/************************************************************************/
// FUNCTION PROTOTYPES


/*************************************************************************************/
/* purpose: perform circular rotation to the left by numBits

input:
c - the character to be checked
numBits - how many bits need to be rotated

return:
none

*/

void rotateLeft(char *c, int numBits)
{
	for (int i = 0; i < numBits; i++)
	{
		// Get if the left bit is set
		int lostBit = (*c >> 7) & 1;
		// Rotate by one and set the lost bit as the left bit
		*c = (*c << 1) | lostBit;
	}
}



/*************************************************************************************/
/* purpose: perform circular rotation to the right by numBits

input:
c - the character to be checked
numBits - how many bits need to be rotated

return:
none

*/

void rotateRight(char *c, int numBits)
{
	for (int i = 0; i < numBits; i++)
	{
		// Get if the right bit is set
		int lostBit = *c & 1;
		// Right shift by 1 and clear the right bit
		*c = (*c >> 1) & (~(1 << 7));
		// Set it's right bit as the new left bit
		*c |= lostBit << 7;
	}
}

/*************************************************************************************/

/* purpose: translate the value of by a certain amount

input:
c - the character
key - is the key for the encryption
index - is the index of the character in the array

output:
c - the character

return:
None

Description:
This function translate the value of c by a computed amount.
The translate can be by adding "amount" to c.

The amount is computed using the the key, the index, and the
value of *c.
the formula is
the value of the character + (57 * index + key)

Example 1:
Assume that *c is 65 (0x41), key is 87 and index is 1.

65 + 57 * 1 + 87.


*/
void translateChar(char *c, char key, int index)
{
    // Depending on the platfrom, the char overflow is automatically handled
    // This was tested on windows 10, OSX mojave, Ubuntu 16.04 and Debian
	*c += (57 * index + key);
}



/*************************************************************************************/

/* purpose: rev the translate the value of by a certain amount

Description:
This function translate the value of c by a computed amount.
The translate can be by adding "amount" to c.

The amount is computed using the the key, the index, and the
value of *c.
the formula is
the value of the character - (57 * index + key)

Example 1:
Assume that *c is 65 (0x41), key is 87 and index is 1.

65 - (57 * 1 + 87).


*/
void revTranslateChar(char *c, char key, int index)
{
    // Depending on the platfrom, the char overflow is automatically handled
    // This was tested on windows 10, OSX mojave, Ubuntu 16.04 and Debian
	*c -= (57 * index + key);
}

/*************************************************************************************/

/* Modifies a char variable but chaging it to the exclusive or version of itself. */
void xorChar(char *c, char key)
{
	*c ^= key;
}

/*************************************************************************************/

/*  Check if a bit is set to 1

input:
c - The char containing the bit
bitNum - The position of the bit to check

return
Whether or not the bit is set



*/
bool checkBit(char c, int bitNum)
{
	return (c >> bitNum) & 1;
}


/*************************************************************************************/


/*  count the number of bits in a short

input:
num - a short integer

return
the number of bits that are set to 1 in num

*/
int countBits(char c)
{
	int bitCount = 0;
	// If we had access to the math library, we could use log2(c) + 1 for the number of bits
	for (int i = 0; i <= 7; i++)
	{
		if (checkBit(c, i))
		{
			bitCount++;
		}
	}
	return bitCount;
}






/*************************************************************************************/


/* Purpose: encrypt a character

input:
*c - the character to encrypt
key - the encryption key
index - the index of the character in the array

output:
*c - the encrypted character

return
0

*/
int encryptChar(char *c, char key, int index)
{
	translateChar(c, key, index);
	int numBits = countBits(*c);
	if (numBits % 2 == 0)
	{
		rotateLeft(c, (index + numBits) % 8);
	}
	else
	{
		rotateRight(c, (index + numBits) % 8);
	}
	xorChar(c, key);
	return(0);
}


/*************************************************************************************/


/* Purpose: decrypt a character

input:
*c - the character to encrypt
key - the encryption key
index - the index of the character in the array

output:
*c - the encrypted character

return
0

*/
int decryptChar(char *c, char key, int index)
{
	xorChar(c, key);
	int numBits = countBits(*c);
	if (numBits % 2 == 0)
	{
		rotateRight(c, (index + numBits) % 8);
	}
	else
	{
		rotateLeft(c, (index + numBits) % 8);
	}
	revTranslateChar(c, key, index);
	return(0);
}