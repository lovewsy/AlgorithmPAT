#ifndef ExecutePrimaryPat_H
#define ExecutePrimaryPat_H
#include "PrimaryPat/PrimaryPatInterface.h"
void ExecutePrimaryPat()
{
	printf("***************Welcom to Primay PAT tests!!!*****************\n");
	
	while(1)
	{
		printf("\n0: Return to last menu.\n1: PAT Ranking.\n2: PAT 1003\n3: PAT 1004\n");
		printf("4: PAT 1005\n5: PAT 1006\n6: PAT 1007\n7: PAT 1008\n8: PAT 1009\n9: PAT 1010\n");
		printf("10: PAT 1011\n11: PAT 1012\n12: PAT 1013\n13: PAT 1014\n");
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
			case 2:
				Execute_1003();
			break;
			case 3:
				Execute_1004();
			break;
			case 4:
				Execute_1005();
			break;
			case 5:
			 	Execute_1006();
			break;
			case 6:
			 	Execute_1007();
			break;
			case 7:
			 	Execute_1008();
			break;
			case 8:
			 	Execute_1009();
			break;
			case 9:
			 	Execute_1010();
			break;
			case 10:
			 	Execute_1011();
			break;
			case 11:
			 	Execute_1012();
			break;
			case 12:
			 	Execute_1013();
			break;
			case 13:
			 	Execute_1014();
			break;
			default:
				printf("Illegal input!!!");
			break;
		}
	}	
}
#endif
