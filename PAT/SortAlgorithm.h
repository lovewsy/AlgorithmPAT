#ifndef SortAlgorithm_H
#define SortAlgorithm_H
#include "PCH.h"
#include "Log.h"

/*
Default Test Case
*/
namespace TestCase
{
	const int n = 10;
	int T[n] = {12, 34, 2, 5, 9, 0, 19, 5, 13, 7};	//test array
	int A[n];
	void InitTestCase()
	{
		for(int i = 0; i < n; ++i)
		{
			A[i] = T[i];
		}
	}
	
	const int MaxSize = 20;
	int B[MaxSize];
}



/************************************************Algorithm section*******************************************/
/*
Basic select sort
*/
void BasicSelectSort(int A[], int n)
{	
	if(n < 2)
		return;
	
	for(int i = 0; i < n-1; ++i)
	{
		int k = i;
		for(int j = i+1; j < n; ++j)
		{
			if(A[j] < A[k])
			{
				k = j;
			}
		}
		int temp = A[k];
		A[k] = A[i];
		A[i] = temp;
	}
}

/*
Direct insert sort
*/
void DirectInsertSort(int A[], int n)
{
	if(n < 2)
		return;
	
	for(int i = 1; i < n; ++i)
	{
		int tmp = A[i];
		int j = i -1;
		while(j>=0 && A[j]>tmp)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = tmp;
	}
}


/**************************Execution section*******************************/

/*
Select Algorithm to execute
*/
void SupplySortTestCase(int*& Array, int& ArraySize)
{
	int option = 0;
	printf("Do you want to use default test case(0) or a custom case(1): ");
	scanf("%d", &option);
	if(option)
	{
		printf("****Please input an integer array which max count is %d ****\n", TestCase::MaxSize);
		int ArrayCount = 0;
		printf("Please input array count: ");
		scanf("%d", &ArrayCount);
		if(ArrayCount < 1 || ArrayCount > TestCase::MaxSize)
		{
			printf("Input is illegal, Program is returning to section start!!!\n");
			return;
		}
		printf("******Start to input array, press enter after every element input*****\n");
		for(int i = 0; i < ArrayCount; ++i)
		{
			scanf("%d", &TestCase::B[i]);  
		}
		Array = TestCase::B;
		ArraySize = ArrayCount;
	}
	else
	{
		Array = TestCase::A;
		ArraySize = TestCase::n;
	}
}
void SelectAlgorithm()
{
	printf("Welcom To PAT Execise! \n");
	printf("Please follow the below instructions! \n");
	
	while(1)
	{
		printf("0: Return to last menu \n1: BasicSelectSort\n2: DirectInsertSort\n3: sort of C++\n");
		printf("Please input an instruction : ");
		int n = 0;
		scanf("%d", &n);
		int* Array = NULL;
		int ArraySize = 0;
		if(n>0 && n<=3)
		{
			TestCase::InitTestCase();
			SupplySortTestCase(Array, ArraySize);
			PrintArray(Array, ArraySize, "Original array");
		}
					
		switch(n)
		{
			case 0:
				return;
			case 1:
				BasicSelectSort(Array, ArraySize);
				PrintArray(Array, ArraySize, "Basic select sort result");				
				break;
			case 2:
				DirectInsertSort(Array, ArraySize);
				PrintArray(Array, ArraySize, "Direct Insert sort result");
				break;
			case 3:
				std::sort(Array, Array + ArraySize);
				PrintArray(Array, ArraySize, "C++ sort result");
				break;
			default:
				printf("Illegal input, Program is returning to section start!!!\n");
				break;
		}
	}
}



#endif
