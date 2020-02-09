#include "DynamicProgramming/DynamicProgrammingInterface.h"

void ExecuteDynamicProgramming()
{
	printf("********************Welcome to Dynamic Programming!!!******************\n");
	while(1)
	{
		printf("\n0: Return to last menu.\n1: Number Pyramid.\n2: Max subsequence.\n");
		printf("3: Longest Increasing Sequence.\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				ExecuteNumberPyramid();
				break;
			case 2:
				ExecuteMaxSubsequence();
				break;
			case 3:
				ExecuteLIS();
				break;
			default:
				printf("Illegal input!!!");
				break; 
		}
	}
}
