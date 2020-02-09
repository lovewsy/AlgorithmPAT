#include "DynamicProgrammingInterface.h"
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000
void ExecuteLIS()
{
	int A[MAX_N], dp[MAX_N] = {0}, n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &A[i]);
	}
	
	int result = -9999;
	for(int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		for(int j = 0; j < i; ++j)
		{
			if(A[i] >= A[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		result = max(dp[i], result);
	}
	
	printf("%d", result);
}
