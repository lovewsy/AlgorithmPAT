#include "DynamicProgrammingInterface.h"
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000
void ExecuteMaxSubsequence()
{
	int n, A[MAX_N], dp[MAX_N];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &A[i]);
	}
	dp[0] = A[0];
	for(int i = 1; i < n; ++i)
	{
		dp[i] = max(A[i], dp[i-1]+A[i]);
	}
	int k = 0;
	for(int i = 1; i < n; ++i)
	{
		if(dp[i] > dp[k])
			k = i;
	}
	printf("%d", dp[k]);
}
