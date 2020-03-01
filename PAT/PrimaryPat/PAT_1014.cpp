#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 20
#define MAX_K 1000
namespace PAT_1014
{
	struct Window
	{
		queue<int> customers;
		int popTime;
		int endTime;
	};
}
using namespace PAT_1014;

int Execute_1014()
{
	int N, M, K ,Q;
	int closedTime = 540;
	vector<Window> windows;
	vector<int> serveTimes;
	vector<int> query;
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	windows.resize(N);
	serveTimes.resize(K);
	query.resize(Q);
	vector<int> endTimes(K, -1);
	for(int i = 0; i < N; ++i)
	{
		windows[i].popTime = 0;
		windows[i].endTime = 0;
	}
	for(int i = 0; i < K; ++i)
	{
		scanf("%d", &serveTimes[i]);
	}
	for(int i = 0; i < Q; ++i)
	{
		scanf("%d", &query[i]);
	}
	int index = 0;
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N && index < K; ++j)
		{
			windows[j].customers.push(index);
			if(i == 0)
			{
				windows[j].popTime = serveTimes[index];			
			}
			if(windows[j].endTime < 540)
			{
				endTimes[index] = windows[j].endTime + serveTimes[index];
			}
			windows[j].endTime += serveTimes[index];
			index++;
		}
	}
	while(index < K)
	{
		int minPopTime = windows[0].popTime, tmpIndex = 0;
		for(int i = 1; i < N; ++i)
		{
			if(windows[i].popTime < minPopTime)
			{
				minPopTime = windows[i].popTime;
				tmpIndex = i;
			}
		}
		windows[tmpIndex].customers.pop();
		windows[tmpIndex].customers.push(index);
		windows[tmpIndex].popTime += serveTimes[windows[tmpIndex].customers.front()];
		if(windows[tmpIndex].endTime < 540)
		{
			endTimes[index] = windows[tmpIndex].endTime + serveTimes[index];
		}
		windows[tmpIndex].endTime += serveTimes[index];
		index++;
	}
	for(int i = 0; i < Q; ++i)
	{
		int end = endTimes[query[i] - 1];
		if(end != -1)
		{
			printf("%02d:%02d\n", 8 + end/60, end%60);
		}
		else
			printf("Sorry\n");
	}
	return 0;
}
