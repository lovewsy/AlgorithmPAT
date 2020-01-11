#include "AlgorithmNotesInterface.h"

#include <cstdio>
#include <algorithm>
#define MAXSIZE 100
typedef struct TVShow
{
	int start, end;
}TVShow;

bool cmp(TVShow a, TVShow b)
{
	if(a.start != b.start)
		return a.start > b.start;
	else
		return a.end < b.end;
}

int Exe_100000584_A()
{
	int num;
	TVShow shows[MAXSIZE];
	while(1)
	{
		scanf("%d", &num);
		if(num == 0)
			return 0;
		for(int i = 0; i < num; ++i)
		{
			scanf("%d %d", &shows[i].start, &shows[i].end);
		}
		std::sort(shows, shows+num, cmp);
		int LastStart = shows[0].start;
		int ShowNum = 1;
		for(int i = 1; i<num; ++i)
		{
			if(LastStart >= shows[i].end)
			{
				LastStart = shows[i].start;
				++ShowNum;
			}
		}	
		printf("%d\n", ShowNum);
	}
	return 0;	
}

int Exe_100000584_B()
{
	int n = 0; 
	float stage1 = 18.0f;
	int Num1 = 8;
	int A[1000];
	float costs[1000];
	while(1)
	{
		scanf("%d", &A[n]);
		if(A[n]==0)
			break;
		n++;
	}
	for(int i = 0; i < n; ++i)
	{
		costs[i] = 0.0f;
		int le = A[i] / Num1;
		A[i] -= le * Num1;
	
		if(le > 0 && A[i] <= 4)
		{
			costs[i] += A[i]*2.4f;
		}
		else
		{
			costs[i] += 10.0f;
			A[i] -= 4;
			if(A[i] > 0)
			{
				costs[i] += A[i]*2.0f;
			}
		}
		
		if(le > 0)
			costs[i] += stage1*le;
	}
	for(int i = 0; i<n; ++i)
	{
		if(costs[i] == (int)costs[i])
		{
			printf("%d\n", (int)costs[i]);
		}
		else
		{
			printf("%.1f\n", costs[i]);
		}
	}
	return 0;
}

int Exe_100000584_B1()
{
	// > 15
	int n = 0; 
	float stage1 = 18.0f;
	int Num1 = 8;
	float cost;
	while(1)
	{
		scanf("%d", &n);
		if(n==0)
			return 0;
		cost = 0.0f;
		int le = n / Num1;
		n -= le * Num1;
	
		if(le > 0 && n <= 4)
		{
			cost += n*2.4f;
		}
		else
		{
			cost += 10.0f;
			n -= 4;
			if(n > 0)
			{
				cost += n*2.0f;
			}
		}
		if(le > 0)
			cost += stage1*le;
			
		if(cost == (int)cost)
		{
			printf("%d\n", (int)cost);
		}
		else
		{
			printf("%.1f\n", cost);
		}
	}
	
	return 0;
}
