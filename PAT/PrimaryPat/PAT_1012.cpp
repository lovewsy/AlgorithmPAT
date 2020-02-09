#include "PrimaryPatInterface.h"
#include <cstdio>
#include <iostream>
#include <unordered_map> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX_N 2000
struct Grade
{
	int Score[4];
	char better;
	int rank[4];
	int bestRank;
};
char Course[4] = {'A', 'C', 'M', 'E'};

class CmpByValueI
{
	public:
		CmpByValueI() = default;
		CmpByValueI(int a):i(a){}
		bool operator()(pair<string, Grade>& a, pair<string, Grade>& b)
		{
			return a.second.Score[i] > b.second.Score[i];
		}
	private:
		int i;
};

int Execute_1012()
{
	unordered_map<string, Grade> stu;
	vector<pair<string, Grade>> OrderVec;
	string CheckIds[MAX_N];
	int Sum, CheckNum;
	scanf("%d %d", &Sum, &CheckNum);
	for(int i = 0; i < Sum; ++i)
	{
		string key;
		Grade value;
		memset(value.rank, 0, sizeof(value.rank));
		value.bestRank = 2002;
		cin >> key >> value.Score[1] >> value.Score[2] >> value.Score[3];
		value.Score[0] = (value.Score[1] + value.Score[2] + value.Score[3]) / 3;
		stu[key] = value;
	}
	for(int i = 0; i < CheckNum; ++i)
	{
		cin >> CheckIds[i];
	}
	OrderVec.assign(stu.begin(), stu.end());
	for(int i = 0; i < 4; ++i)
	{
		sort(OrderVec.begin(), OrderVec.end(), CmpByValueI(i));
		OrderVec[0].second.rank[i] = 1;
		if(stu[OrderVec[0].first].bestRank > 1)
		{
			stu[OrderVec[0].first].bestRank = 1;
			stu[OrderVec[0].first].better = Course[i];
			stu[OrderVec[0].first].rank[i] = 1;
		}		
		for(int j = 1; j < OrderVec.size(); ++j)
		{
			if(OrderVec[j].second.Score[i] != OrderVec[j-1].second.Score[i])
			{
				OrderVec[j].second.rank[i] = j+1;
				stu[OrderVec[j].first].rank[i] = j+1;
			}
			else
			{
				OrderVec[j].second.rank[i] = OrderVec[j-1].second.rank[i];
				stu[OrderVec[j].first].rank[i] = OrderVec[j-1].second.rank[i];
			}
			if(stu[OrderVec[j].first].rank[i] < stu[OrderVec[j].first].bestRank)
			{
				stu[OrderVec[j].first].bestRank = stu[OrderVec[j].first].rank[i];
				stu[OrderVec[j].first].better = Course[i];
			}
		}
	}
	
	for(int i = 0; i < CheckNum; ++i)
	{
		unordered_map<string, Grade>::iterator ite = stu.find(CheckIds[i]);
		if(ite != stu.end())
		{
			printf("%d %c", ite->second.bestRank, ite->second.better);
		}
		else
		{
			printf("N/A");
		}
		if(i != CheckNum-1)
			printf("\n");
	}
	return 0;
}
