#include "Log.h"
#include "PCH.h"
/*
Output an integer array
*/
void PrintArray(int A[], int n, const char* info)
{
	if(strcmp(info, "") != 0)
	{
		printf("***** %s *****\n", info);
	}
	printf("Array Count is %d: ", n);
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
