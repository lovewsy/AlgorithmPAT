#include "PrimaryPatInterface.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int tn = 24;
int tolls[tn];
namespace PAT_1016
{
	class Record
	{
	public:
		std::string name;
		std::string state;
		int month;
		int day;
		int hour;
		int minute;
	};
}
using namespace PAT_1016;
bool Cmp(Record r1, Record r2)
{
	if(strcmp(r1.name.c_str(), r2.name.c_str()) != 0)
		return strcmp(r1.name.c_str(), r2.name.c_str()) < 0;
	if(r1.month != r2.month)
		return r1.month < r2.month;
	if(r1.day != r2.day)
		return r1.day < r2.day;
	if(r1.hour != r2.hour)
		return r1.hour < r2.hour;
	if(r1.minute != r2.minute)
		return r1.minute < r2.minute;
	return strcmp(r1.state.c_str(), r2.state.c_str()) > 0;
}
double ResolveCosts(Record const& r1, Record const& r2)
{
	int sum = 0; 
	int elapsedHours = (r2.day * 24 + r2.hour) - (r1.day * 24 + r1.hour);
	if(elapsedHours == 0)
		return ((r2.minute - r1.minute) * tolls[r1.hour]) / 100.0;
	sum += tolls[r1.hour] * (60 - r1.minute);
	int k = 1;
	while(k < elapsedHours)
	{
		sum += tolls[(k+r1.hour)%24] * 60;
		++k;
	}
	sum += r2.minute * tolls[r2.hour];
	return sum / 100.0;
}

int Execute_1016()
{
	char m;
	vector<Record> records;
	int recordNum;
	for(int i = 0; i < tn; ++i)
		cin >> tolls[i];

	cin >> recordNum;

	for(int i = 0; i < recordNum; ++i)
	{
		Record r = Record();
		cin >> r.name;
		cin >> r.month;
		cin >> m;
		cin >> r.day;
		cin >> m;
		cin >> r.hour;
		cin >> m;
		cin >> r.minute;
		cin >> r.state;
		
		records.emplace_back(r);
	}
	sort(records.begin(), records.end(), Cmp);
	
	auto PrintLine = [](Record const& r1, Record const& r2) -> double
	{
		double cost = ResolveCosts(r1, r2);
		int elapsedMinutes = ((r2.day * 24 + r2.hour) * 60 + r2.minute) - ((r1.day*24 + r1.hour)*60+r1.minute);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", r1.day, r1.hour, r1.minute, r2.day, r2.hour, r2.minute, elapsedMinutes, cost);
		return cost;
	};

	int k = 1;
	double totalAmount = 0.0;
	bool IsLog = true;
	while(k < recordNum)
	{
		if(strcmp(records[k-1].name.c_str(), records[k].name.c_str()) != 0)
		{
			IsLog = true;
			if(totalAmount != 0.0)
			{
				printf("Total amount: $%.2lf\n", totalAmount);
				totalAmount = 0.0;
			}
		}
		else
		{
			if(strcmp(records[k-1].state.c_str(), records[k].state.c_str()) > 0)
			{
				if(IsLog)
				{
					printf("%s %02d\n", records[k-1].name.c_str(), records[k-1].month);
					IsLog = false;
				}			
				totalAmount += PrintLine(records[k-1], records[k]);
			}
		}
		++k;	
	}
	if(totalAmount != 0.0)
	{
		printf("Total amount: $%.2lf\n", totalAmount);
	}
	return 0;
}

