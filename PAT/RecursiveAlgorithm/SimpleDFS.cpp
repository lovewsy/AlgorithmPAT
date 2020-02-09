#include "RecursiveAlgorithmInterface.h"
#include "../Log.h"
#include <cstdio>
namespace SimpleDFSTestCase
{
	const int MaxN = 30;
	int W[MaxN];
	int C[MaxN];	
	int N, V, MaxValue = 0;
}; 
using namespace SimpleDFSTestCase;
void SimpleDFS(int index, int SumW, int SumC)
{
	if(index == N)
		return;
	
	SimpleDFS(index+1, SumW, SumC);
	if(SumW + W[index] <= V)
	{
		if(C[index] + SumC > MaxValue)
		{
			MaxValue = C[index] + SumC;
		}
		SimpleDFS(index+1, SumW+W[index], SumC+C[index]);
	}
}


void ExecuteSimpleDFS()
{
	scanf("%d %d", &SimpleDFSTestCase::N, &SimpleDFSTestCase::V);
	InputArray(SimpleDFSTestCase::W, SimpleDFSTestCase::N);
	InputArray(SimpleDFSTestCase::C, SimpleDFSTestCase::N);
	
	SimpleDFS(0, 0, 0);
	
	printf("MaxValue: %d\n", MaxValue);
}
