/*
 *
 * Infinite loop that prints a counter every one second
 *
*/


#include <stdio.h>
#include <unistd.h>

int  main(int argc, char **argv)
{
    int i;
	for(i = 0;;i++){
		printf("loop i=%d\n",i);
		 sleep(1);
	}
}

