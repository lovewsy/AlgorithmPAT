#include "PrimaryPatInterface.h"
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int Execute_1005()
{
	char* Number = new char[101];
	string HashTable[10] = {"zero", "one", "two", "three", "four", "five",
					"six", "seven", "eight", "nine"};
	stack<string> Result;
	scanf("%s", Number);
	int Sum = 0;
	char* TmpChar = Number;
	while(*TmpChar != '\0')
	{
		Sum += *TmpChar - '0';
		TmpChar++;
	}
	if(Sum == 0)
	{
		Result.push(HashTable[0]);
	}
	else
		while(Sum != 0)
		{
			Result.push(HashTable[Sum%10]);
			Sum = Sum/10;
		}
	while(!Result.empty())
	{
		printf("%s", Result.top().c_str());
		Result.pop();
		if(!Result.empty())
			printf(" ");
	}
	delete[] Number;
	return 0;
}



#define MAX_N 100
struct Date
{
	int hour;
	int minute;
	int second;
};
struct Record
{
	string ID;
	Date SignIn;
	Date SignOut;
};

bool Cmp(Date a, Date b)
{
	if(a.hour != b.hour)
		return a.hour < b.hour;
	else
	{
		if(a.minute != b.minute)
			return a.minute < b.minute;
		else
		{
			return a.second < b.second;
		}
	}
}

bool CmpSignIn(Record r1, Record r2)
{
	return Cmp(r1.SignIn, r2.SignIn);
}
bool CmpSignOut(Record r1, Record r2)
{
	return Cmp(r1.SignOut, r2.SignOut);
}
int Execute_1006()
{
	int RecordsNum;
	scanf("%d", &RecordsNum);
	if(RecordsNum == 0)
		return 0;
	vector<Record> records;
	auto GetDate = [](string str) -> Date
			{
				Date d;
				d.hour = (str[0]-'0')*10 + (str[1]-'0');
				d.minute = (str[3]-'0')*10 + (str[4]-'0');
				d.second = (str[6]-'0')*10 + (str[7]-'0');
				return d;
			};
	for(int i = 0; i < RecordsNum; ++i)
	{
		Record r;
		string SignInDate, SignOutDate;
		cin>>r.ID>>SignInDate>>SignOutDate;		
		r.SignIn = GetDate(SignInDate);
		r.SignOut = GetDate(SignOutDate);
		records.push_back(r);
	}
	sort(records.begin(), records.end(), CmpSignIn);
	printf("%s ", records[0].ID.c_str());
	sort(records.begin(), records.end(), CmpSignOut);
	printf("%s", records[records.size()-1].ID.c_str());
	return 0;
}

#define MAX_K 10000
int Execute_1007()
{
	int k, A[MAX_K];
	scanf("%d", &k);
	if(k == 0)
		return 0;
	
	for(int i = 0; i < k; ++i)
		scanf("%d", &A[i]);
	int first = 0, last = 0, CurrFirst = 0, CurrLast = 0;
	int MaxSum = A[0], Sum = A[0];
	bool IsAllNegative = A[0] < 0;
	for(int i = 1; i < k; ++i)
	{
		if(A[i] >= 0)
			IsAllNegative = false;
		if(Sum < 0)
		{
			Sum = A[i];
			CurrFirst = i;
			CurrLast = i;
		}
		else
		{
			CurrLast = i;
			Sum += A[i];		
		}
		if(MaxSum < Sum)
		{
			MaxSum = Sum;
			first = CurrFirst;
			last = CurrLast;
		}
	}
	if(IsAllNegative) 
		printf("0 %d %d", A[0], A[k-1]);
	else
	{
		printf("%d %d %d", MaxSum, A[first], A[last]);
	}
	return 0;
}
