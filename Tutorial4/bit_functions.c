
/* file is bit_functions.c 
Purpose: helper functions for bit manipulation

*/

#include "bit_functions.h"




/*
Purpose: checks if bit in position bitNum of the character c is set to 1 
input:
c - a character
bitNum - the bit position

return
1 if the bits is set
0 is the bit is not set

*/
int isBitSet(unsigned char c, int bitNum) 
{
    if ( (c >> bitNum ) & 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/***************************************************************/


/*
Purpose: sets bit in position bitNum of the character c to 1 
input:
c - a character 
bitNum - the bit position

return
the modified character

*/
unsigned char setBit(unsigned char c, int bitNum) 
{
    return c | 1 << bitNum;
	
}


/***************************************************************/

/*
Purpose: clears bit in position bitNum of the character c 
input:
c - a character upon
bitNum - the bit position

return
the modified character

*/

unsigned char clearBit(unsigned char c, int bitNum) 
{
    return c & ~(1 << bitNum);
}


/***************************************************************/

/*
Purpose: prints the bits of the the character using an iterative method 
input:
c - a character that its bits must be printed

return
none

*/

void printBitsIterative(unsigned char c) 
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d\n", isBitSet(c, i));
    }
}

/***************************************************************/


/*
Purpose: prints the bits of the the character using recurive method
input:
c - a character that its bits must be printed

return
none

*/

void printBitsRecursive(unsigned char c) 
{
    if(c == 0)
    {
        return;
    }
    printBitsRecursive(c >> 1);
    printf("%d\n", isBitSet(c, 0));
}



/***************************************************************/

/*
Purpose: computes the xor operation between two characeters. 
input:
c1 - the first character 
c2 - the second character

output:
none

return:
the value of c1 ^ c2

*/


unsigned char myXOR(unsigned char c1, unsigned char c2)

{
    return (c1 | c2) & (~c1 | ~c2);
}
