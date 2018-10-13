#include "stdio.h"

int	main()
{
	int num[3];
	int	i;
	for	(i = 0; i < 3; i++)
	{
		printf("Enter a number:");
		scanf("%d",	&num[i]);
	}
	printf("\n");
	for	(i = 0; i < 3; i++)
	{
		printf("value of num[%d]: %d\n", i, num[i]);
	}
}