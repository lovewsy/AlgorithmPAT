#ifndef ExecuteRecursiveAlgorithm_H
#define ExecuteRecursiveAlgorithm_H
#include "RecursiveAlgorithm/RecursiveAlgorithmInterface.h"

void ExecuteRecursiveAlgorithm()
{
	printf("********************Welcome to recursive algorithm!!!******************\n");
	while(1)
	{
		printf("0: Return to last menu.\n1: Basic Full Permutation.\n2: N Queue.\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				BasicFullPermutation();
				break;
			case 2:
				NQueens();
				break;
			default:
				printf("Illegal input!!!");
				break; 
		}
	}
}

#endif
