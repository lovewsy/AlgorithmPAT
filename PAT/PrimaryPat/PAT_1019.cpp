#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int Execute_1019()
{
	vector<int> nums;
	int N, b;
	scanf("%d %d", &N, &b);
	
	int k = N;
	while(k != 0)
	{
		nums.push_back(k % b);
		k /= b;
	}
	reverse(nums.begin(), nums.end());
	bool isPal = true;
	for(int i = 0; i < nums.size()/2; ++i)
	{
		if(nums[i] != nums[nums.size()-i-1])
			isPal = false;
	}
	if(isPal)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = 0; i < nums.size(); ++i)
	{
		printf("%d", nums[i]);
		if(i != nums.size()-1)
			printf(" ");
	}
	
	return 0;
}
