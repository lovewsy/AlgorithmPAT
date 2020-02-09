#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 20
#define MAX_K 1000
struct Customer
{
	int num;
	int time;
};
struct Time
{
	int hour;
	int minute;
};
Time TimerElapse(int minutes)
{
	static Time startTime = {8, 0};
	startTime.hour += minutes / 60;
	startTime.minute += minutes % 60;
	return startTime;
}
int Execute_1014()
{
	int N, M, K ,Q;
	queue<Customer> customers;
	queue<Customer> windows[MAX_N];
	Time EndTimes[K];
	int query[MAX_K];
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for(int i = 0; i < K; ++i)
	{
		Customer c;
		c.num = i;
		scanf("%d", &c.time);
		if(windows[i % N].size() < M)
		{
			windows[i % N].push(c);
		}
		else
			customers.push(c);
	}
	for(int i = 0; i < Q; ++i)
	{
		scanf("%d", &query[i]);
	}
	int served = 0;
	while(!customers.empty() || served != K)
	{
		int minMinute = 0;
		for(int i = 0; i < N; ++i)
		{
			if(!windows[i].empty())
			{
				if(minMinute == 0)
					minMinute = windows[i].front().time;
				else
					minMinute = min(windows[i].front().time, minMinute);
			}
		}
		Time now = TimerElapse(minMinute);
		for(int i = 0; i < N; ++i)
		{
			if(!windows[i].empty())
			{
				windows[i].front().time -= minMinute;
				if(windows[i].front().time == 0)
				{
					EndTimes[windows[i].front().num] = now;
					windows[i].pop();
					++served;
					if(!customers.empty())
					{
						windows[i].push(customers.front());
						customers.pop();
					}	
				}
			}			
		}		
	}
	for(int i = 0; i < Q; ++i)
	{
		if(query[i] > K || query[i] < 1)
			printf("Sorry");
		else
		{
			if((EndTimes[query[i] - 1].hour == 17 && EndTimes[query[i] - 1].minute == 0) || EndTimes[query[i] - 1].hour < 17)
				printf("%2.d:%2.d", EndTimes[query[i] - 1].hour, EndTimes[query[i] - 1].minute);
			else 
				printf("Sorry");
		}
		if(i != Q-1)
			printf("\n");
	}
	return 0;
}
