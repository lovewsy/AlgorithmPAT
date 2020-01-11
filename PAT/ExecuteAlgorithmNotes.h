#include "AlgorithmNotes/AlgorithmNotesInterface.h"


void ExecuteAlgorithmNotes()
{
	printf("***************Welcom to Primay AlgorithmNotes!!!*****************\n");
	while(1)
	{
		printf("0: Return to last menu.\n1: 100000584_A.\n2: 100000584_B.\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				Exe_100000584_A();
			break;
			case 2:
				Exe_100000584_B();
			break;
			default:
				printf("Illegal input!!!");
			break;
		}
	}
}
	
