#ifndef ExecutePrimaryPat_H
#define ExecutePrimaryPat_H
#include "PrimaryPat/PrimaryPatInterface.h"
void ExecutePrimaryPat()
{
	printf("***************Welcom to Primay PAT tests!!!*****************\n");
	
	while(1)
	{
		printf("0: Return to last menu.\n1: PAT Ranking.\n");
		printf("Please input an instruction: ");
		int options = 0;
		scanf("%d", &options);
		switch(options)
		{
			case 0:
				return;
			case 1:
				PATRanking();
			break;
			default:
				printf("Illegal input!!!");
			break;
		}
	}	
}
#endif
