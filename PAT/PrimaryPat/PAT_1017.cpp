#include "PrimaryPatInterface.h"
#include<cstdio>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;

#define MAX_K 100

namespace PAT_1017
{
	struct Customer
	{
		double arriveTime;	// minute
		double serveTime;	
	};
}
using namespace PAT_1017;

bool Cmp(Customer const& c1, Customer const& c2)
{
	if(c1.arriveTime < c2.arriveTime)
		return true;
	return false;
}

int Execute_1017()
{
	vector<Customer> customers;
	vector<Customer> servedCustomers;
	int n, k;
	scanf("%d %d", &n, &k);
	double closedTime = 9 * 60.0;
	double nowTime = 0.0;
	double totalWait = 0.0;
	vector<double> windows(k, 0.0);
	
	for(int i = 0; i < n; ++i)
	{
		Customer c;
		char tmp;
		int hour, minute, second;
		scanf("%d%c%d%c%d %lf", &hour, &tmp, &minute, &tmp, &second, &c.serveTime);
		c.arriveTime = (hour*60.0*60.0 + minute*60.0+second*1.0 - 8 * 60.0 * 60.0) / 60.0;
		if((c.arriveTime + c.serveTime) <= closedTime)
		{
			customers.emplace_back(c);
		}
	}
	sort(customers.begin(), customers.end(), Cmp);
	
	int served = 0;
	for(int i = 0; i < customers.size(); ++i)
	{
		int tmpIndex = 0;
		for(int j = 1; j < k; ++j)
		{
			if(windows[j] < windows[tmpIndex])
			{
				tmpIndex = j;
			}
		}
		if(windows[tmpIndex] < customers[i].arriveTime)	// served right away, no waiting time
		{
			windows[tmpIndex] = customers[i].arriveTime + customers[i].serveTime;
		}
		else
		{
			totalWait += windows[tmpIndex] - customers[i].arriveTime;
			windows[tmpIndex] +=  customers[i].serveTime;
		}
	}
	if(customers.size() != 0)
		printf("%.1lf", totalWait / customers.size());
	else
		printf("0.0");
	return 0;
}
