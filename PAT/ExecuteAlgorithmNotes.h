#include "AlgorithmNotes/AlgorithmNotesInterface.h"


void ExecuteAlgorithmNotes()
{
	printf("***************Welcom to Primay AlgorithmNotes!!!*****************\n");
	while(1)
	{
		printf("0: Return to last menu.\n");
		printf("1: 100000582_A.\n2: 100000582_B.\n3: 100000582_C\n4: 100000582_D\n");
		printf("8: 100000584_A.\n9: 100000584_B.\n10: 100000584_C\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				Exe_100000582_A();
				break;
			case 2:
				Exe_100000582_B();
				break;
			case 3:
				Exe_100000582_C();
				break;
			case 4:
				Exe_100000582_D();
				break;
			case 8:
				Exe_100000584_A();
			break;
			case 9:
				Exe_100000584_B();
			break;
			case 10:
				Exe_100000584_C();
			break;
			default:
				printf("Illegal input!!!");
			break;
		}
	}
}
	
