
/*

File bit_manipulation.h

Purpose:header file of functions prototypes

*/

/************************************************************************/

// INCLUDE FILES


#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"


/************************************************************************/
// FUNCTION PROTOTYPES

void rotateLeft(char *c, int numBits);
void rotateRight(char *c, int numBits);
void translateChar(char *c, char key, int index);
void revTranslateChar(char *c, char key, int index);
void xorChar(char *c, char key);
int encryptChar(char *c, char key, int index);
int decryptChar(char *c, char key, int index);
int countBits(char c);
bool checkBit(char c, int bitNum);


