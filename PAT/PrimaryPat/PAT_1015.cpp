#include "PrimaryPatInterface.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPrime(int n)
{
	if(n == 1)
		return false;
	for(int i = 2; i*i <= n; ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int ReverseNum(int n, int d)
{
	vector<int> nums;
	while(n != 0)
	{
		nums.push_back(n%d);
		n /= d;
	}
	int p = 1, result = 0;
	for(int i = nums.size()-1; i >= 0; --i)
	{
		result += nums[i] * p;
		p *= d;
	}
	return result;
}
int Execute_1015()
{
	vector<bool> results;
	while(1)
	{
		int n, d;
		cin >> n;
		if(n < 0)
			break;
		cin >> d;
		if(!IsPrime(n))
		{
			results.push_back(false);
			continue;
		}
		results.push_back(IsPrime(ReverseNum(n, d)));
	}
	for(int i = 0; i < results.size(); ++i)
	{
		if(results[i])
			printf("Yes");
		else
			printf("No");
		if(i != results.size() - 1)
			printf("\n");
	}
	return 0;
}
