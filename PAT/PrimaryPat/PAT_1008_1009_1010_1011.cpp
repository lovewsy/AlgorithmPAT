#include "PrimaryPatInterface.h"
#include <cstdio>
#include <map>
#include <iostream> 
using namespace std;

int Execute_1008()
{
	int UpTime = 6, DownTime = 4, WaitTime = 5;
	int K, TotalTime = 0;
	int lastRequest = 0, request;
	scanf("%d", &K);
	for(int i = 0; i < K; ++i)
	{
		TotalTime += WaitTime;
		scanf("%d", &request);
		if(request < lastRequest)
			TotalTime += (lastRequest-request)*DownTime;
		else if(request > lastRequest) 
			TotalTime += (request-lastRequest)*UpTime;
		lastRequest = request;
	}
	printf("%d", TotalTime);
	return 0;
} 



#define MAX_K 10
struct Item
{
	int exp;
	double coe;	
};
int Execute_1009()
{
	map<int, double> Result;
	Item A[MAX_K], B[MAX_K];
	int k1, k2;
	scanf("%d", &k1);
	for(int i = 0; i < k1; ++i)
	{
		scanf("%d %lf", &A[i].exp, &A[i].coe);
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; ++i)
	{
		scanf("%d %lf", &B[i].exp, &B[i].coe);
	}
	for(int i = 0; i < k1; ++i)
	{
		for(int j = 0; j < k2; ++j)
		{
			int exp = A[i].exp + B[j].exp;
			double coe = A[i].coe * B[j].coe;
			map<int,double>::iterator iter = Result.find(exp);
			if(iter == Result.end())
				Result.insert(pair<int, double>(exp, coe));
			else
			{			
				Result[exp] += coe;
				if(Result[exp] == 0.0)
					Result.erase(iter);		
			}
		}
	}
	
	printf("%d", Result.size());
	for(map<int, double>::reverse_iterator ite = Result.rbegin(); ite!= Result.rend(); ++ite)
	{
		printf(" %d %.1lf", ite->first, ite->second);
	}
	return 0;
}



int ToNumber(char c)
{
	return (c - 'a' >= 0 ? (c - 'a' + 10) : c - '0');
}

long long ComputeDecimal(string str, int radix)
{
	long long d = 0;
	long long r = 1;
	for(int i = str.length()-1; i >= 0; --i)
	{
		d += ToNumber(str[i]) * r;
		if(d < 0 || r < 0)
			return -1;
		r = r * radix;
	}
	return d;
}

int Execute_1010()
{
	long long low = 1, high = 36;	//×¢Òâ¾«¶È 
	long long dec;
	int option, radix;
	string N1, N2;
	cin >> N1 >> N2 >> option >> radix;
	if(option == 2)
	{
		string m = N1;
		N1 = N2;
		N2 = m;
	}
	dec = ComputeDecimal(N1, radix);
	high = dec + 1;
	char maxC = N2[0];
	for(int i = 1; i < N2.length(); ++i)
	{
		if(N2[i] > maxC)
			maxC = N2[i];
	}
	low = max(ToNumber(maxC) + 1, 2);
	while(low <= high)
	{
		long long mid = (low + high) / 2;
		long long dec2 = ComputeDecimal(N2, mid);
		if(dec2 == -1 || dec2 > dec)
			high = mid - 1;
		else if(dec2 < dec)
			low = mid + 1;
		else
		{
			printf("%d", mid);
			return 0;
		}		
	}
	if(ComputeDecimal(N2, low) == dec)
		printf("%d", low);
	else
		printf("Impossible");
	return 0;
}







int Execute_1011()
{
	float odds[3][3];
	int bets[3] = {0, 1, 2};
	char str[3] = {'W', 'T', 'L'};
	for(int i = 0; i < 3; ++i)
	{
		float a = -1.0;
		for(int j = 0; j < 3; ++j)
		{
			scanf("%f", &odds[i][j]);
			if(a < odds[i][j])
			{
				a = odds[i][j];
				bets[i] = j;
			}
		}
	}
	
	float profit = 1.0;
	for(int i = 0; i < 3; ++i)
	{
		printf("%c ", str[bets[i]]);
		profit *= odds[i][bets[i]];
	}
	profit = (profit * 0.65 - 1) * 2;
	printf("%.2f", profit);
	return 0;
}
