#include "RecursiveAlgorithmInterface.h"
#include "../Log.h"
#include "../PCH.h"

namespace PermutationTestCase
{
	const int n = 6;
	int P[n];
	int HashTable[n];
	
}

/*
Every execution select an element which is not selected as the index_th element of P
*/
void Permutation(int index)
{
	if(index == PermutationTestCase::n)	// finish one permutaion
	{
		static int count = 1;
		char buffer[255];
		sprintf(buffer, "The %dth permutation array: ", count);
		PrintArray(PermutationTestCase::P, PermutationTestCase::n, buffer);
		count++;
		return;
	}
	for(int i = 0; i < PermutationTestCase::n; ++i)
	{
		if(PermutationTestCase::HashTable[i] == 0)
		{
			PermutationTestCase::P[index] = i + 1;
			PermutationTestCase::HashTable[i] = 1;
			Permutation(index+1);
			PermutationTestCase::HashTable[i] = 0;
		}
	}
}

void BasicFullPermutation()
{
	printf("perform full permutation of 1~%d integer numbers!\n", PermutationTestCase::n);
	memset(PermutationTestCase::HashTable, 0, PermutationTestCase::n*sizeof(int));
	Permutation(0);
}
