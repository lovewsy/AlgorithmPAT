#include "DataStructure/DataStructureInterface.h"

void ExecuteDataStructure()
{
	printf("********************Welcome to data structure algorithm!!!******************\n");
	while(1)
	{
		printf("0: Return to last menu.\n1: Graph algorithm.\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				ExecuteGraph();
				break;
			default:
				printf("Illegal input!!!");
				break; 
		}
	}
}
