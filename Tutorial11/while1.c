#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

int main() 

{
    int i=0;

    while(1){
        printf("while %d \n",i);
        sleep(1);
        i++;
    }
}
