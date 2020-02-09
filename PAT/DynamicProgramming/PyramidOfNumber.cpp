#include "DynamicProgrammingInterface.h"
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAX_N 1000

int P[MAX_N][MAX_N], dp[MAX_N][MAX_N];
int MaxSum(int i, int j, int n)
{
	if(i+2 == n)
	{
		dp[i][j] = max(P[i+1][j], P[i+1][j+1]) + P[i][j];
	}
	else if (dp[i][j] == -1)
	{
		dp[i][j] = max(MaxSum(i+1, j, n), MaxSum(i+1, j+1, n)) + P[i][j];
	}
	return dp[i][j];
}

void ExecuteNumberPyramid()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			scanf("%d", &P[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	for(int j = 0; j < n; ++j)
	{
		dp[n-1][j] = P[n-1][j];
	}
	MaxSum(0, 0, n);
	printf("%d", dp[0][0]);
}
