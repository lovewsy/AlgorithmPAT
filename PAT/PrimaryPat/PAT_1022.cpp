/*
* key point:
* If you use integer type for ID, you should consider the output format when ID is less than 1000000.
* Because, ID is a 7-digital number.
*/
#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
using namespace std;

namespace PAT_1022
{
	struct Query
	{
		int type;
		string search;
	};
}
using namespace PAT_1022;
int Execute_1022()
{
	int N, M;
	map<string, vector<int>> data[5];
	vector<vector<int>> result;
	vector<Query> query;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int ID;
		string title, author, publisher, year;
		while(cin >> ID)
		{
			if(getchar() == '\n')
				break;
		}
		getline(cin, title);
		data[0][title].push_back(ID);
		getline(cin, author);
		data[1][author].push_back(ID);
		string keyword;
		while(cin >> keyword)
		{
			data[2][keyword].push_back(ID);
			if(getchar() == '\n')
				break;
		}
		getline(cin, publisher);
		data[3][publisher].push_back(ID);
		cin >> year;
		data[4][year].push_back(ID);
	}
	while(cin >> M)
	{
		if(getchar() == '\n')
			break;
	}
	result.resize(M);
	for(int i = 0; i < M; ++i)
	{
		char tmp;
		Query q;
		cin >> q.type >> tmp;
		getchar();
		getline(cin, q.search);
		query.push_back(q);
	}
	
	for(int i = 0; i < query.size(); ++i)
	{
		if(data[query[i].type-1].find(query[i].search) != data[query[i].type-1].end())
			result[i].assign(data[query[i].type-1][query[i].search].begin(), data[query[i].type-1][query[i].search].end());
	}
	for(int i = 0; i < result.size(); ++i)
	{
		cout << query[i].type << ": ";
		cout << query[i].search << "\n";
		if(result[i].size() == 0)
			printf("Not Found\n");
		else
		{
			sort(result[i].begin(), result[i].end());
			for(auto id : result[i])
			{
				printf("%07d\n", id);
			}
		}
	}
	return 0;
}
