#include <stdio.h>
#include <stdlib.h>

#include "mystat.h"


void average(float *arr, int size, float *average)
{
	int i;

	*average = 0;
	for (i = 0; i < size; i++, arr++) {
        *average += *arr;
    };
	*average /= size;
}
