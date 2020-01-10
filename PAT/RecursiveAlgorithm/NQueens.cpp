#include "RecursiveAlgorithmInterface.h"
#include "../Log.h"
#include "../PCH.h"

namespace TestCaseNQueens
{
	int *HashTable;
	int *Queens;
	int number;
	void Initialize()
	{
		HashTable = new int[number];
		memset(HashTable, 0, number * sizeof(int));
		// index of element indicates column number, the value of element indicates the row number.
		Queens = new int[number];	
		for(int i = 0; i < number; ++i)
		{
			Queens[i] = i;
		}
	}
	void Destroy()
	{
		delete HashTable;
		delete Queens;
	}
}

void PrintQueens(int count)
{
	for(int i = 0; i < TestCaseNQueens::number; ++i)
	{
		printf("	");
		for(int j = 0; j < TestCaseNQueens::number; ++j)
		{			
			if(TestCaseNQueens::Queens[j] == i)
			{
				printf("$");
			}
			else
			{
				printf("*");
			}
			if(j != TestCaseNQueens::number - 1)
				printf("-.-");
		}
		printf("\n");
		if(i != TestCaseNQueens::number-1)
		{
			printf("	");
			for(int k = 0; k < TestCaseNQueens::number; ++k)
			{	
				printf("|  ");	
			}
			printf("\n");
		}
	}
	printf("%dth solution: ", count);
	for(int i = 0; i < TestCaseNQueens::number; ++i)
	{
		printf("%d ", TestCaseNQueens::Queens[i]);
	}
	printf("\n");
}

int PermutateQueens(int index)
{
	static int count = 0;
	if(index == TestCaseNQueens::number)
	{
		count++;		
		PrintQueens(count);
		return count;
	}
	
	for(int i = 0; i < TestCaseNQueens::number; ++i)
	{	
		if(TestCaseNQueens::HashTable[i] == 0)
		{
			bool IsRight = true;	
			for(int j = 0; j < index; ++j)
			{	
				int param1 = i-TestCaseNQueens::Queens[j];
				int param2 = index-j;
				if(param1 == param2 || param1 == -param2)	// there are two queens in same diagonal
				{
					IsRight = false;
				}
			}
			if(IsRight)	//correct solution, place the queen in the location index
			{
				TestCaseNQueens::Queens[index] = i;
				TestCaseNQueens::HashTable[i] = 1;	
				PermutateQueens(index + 1);			
				TestCaseNQueens::HashTable[i] = 0;
			}
		}
	}
	return count;
}

void NQueens()
{
	int number;
	printf("Input the number of queues: ");
	scanf("%d", &TestCaseNQueens::number);
	TestCaseNQueens::Initialize();
	PermutateQueens(0);
	TestCaseNQueens::Destroy();
}
