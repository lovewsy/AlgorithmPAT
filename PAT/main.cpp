#include <iostream>
#include "SortAlgorithm.h"
#include "ExecutePrimaryPat.h"
#include "ExecuteRecursiveAlgorithm.h"
#include "ExecuteAlgorithmNotes.h"
#include "ExecuteDataStructureAlgorithm.h"
#include "ExecuteDynamicProgramming.h"

int main(int argc, char** argv)
{
	printf("*************Welcome to PAT execise program!!!************\n");
	int options = 0;
	while(1)
	{
		printf("0: Exit\n1: Sort Algorithm\n2: PAT tests\n3: Recursive Algorithm\n4: Algorithm Notes\n");
		printf("5: Data Structure Algorithm\n6: Dynamic Programming\n");
		printf("Please input an instruction: ");
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return 0;
			case 1:
				SelectAlgorithm();
				break;
			case 2:
				ExecutePrimaryPat();
				break;
			case 3:
				ExecuteRecursiveAlgorithm();
				break;
			case 4:
				ExecuteAlgorithmNotes();
				break;
			case 5:
				ExecuteDataStructure();
				break;
			case 6:
				ExecuteDynamicProgramming();
				break;
			default:
				printf("Illegal input!!!");
				break;
		}
	}
	
	return 0;
}
