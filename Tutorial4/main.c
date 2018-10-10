#include <stdio.h>
#include "bit_functions.h"


int main() 
{
    unsigned char a = 'A';
    unsigned char c1, c2;
 
    int i,j,k;
 
    printBitsIterative(a);
    printf("setting bits 2 and 3 \n");
    a = setBit(a, 2);
    a = setBit(a, 3);
    printBitsIterative(a);

    printf("clearing bit 2 \n");
    a = clearBit(a, 2);
    printBitsRecursive(a);

    printf("Check the following operations are correct \n\n");

    c1 = 23;
    c2 = 13;

    printf("%X ^ %X = %X\n",c1, c2, c1 ^ c2);

    printf("myXOR(%X,%X) = %X\n",c1, c2, myXOR(c1,c2));

    if ((c1^c2) == myXOR(c1,c2)) {
        printf("myXOR() is working \n");
    } else {
        printf("myXOR() is NOT working \n");
    } 







    return 0;
}
 

