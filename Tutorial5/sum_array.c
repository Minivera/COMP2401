
#include "stdio.h"
#include "stdlib.h"
 
int computeSum(float arr[][6], int sizeD1);

int main(int argc, char* argv[])
{
	int i, j, k;
	int count = 0;

    float arr2D[3][6];
	float arr3D[4][5][6];



	// populate the array arr2D
    //  
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
		    arr2D[i][j] = count;
			count++;
		}
	}

	// populate the array arr3D
    //  

    count = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 6; k++) {
				arr3D[i][j][k] = count;
				count++;
			}
		}
	}



    // call the function to compute the sum arr2D[2]
    printf("Sum of array 2D = %d\n", computeSum(arr2D, 3));


    // print the sum of arr3D[2]
    printf("Sum of array 2D = %d\n", computeSum(arr3D[2], 5));

    
    return 0;
}

int computeSum(float arr[][6], int sizeD1)
{
	int sum = 0;
	for(int i = 0; i < sizeD1; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
