#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

namespace PAT_1022
{
	struct Book
	{
		int ID;
		string title;	// 1
		string author;	// 2
		vector<string> keyWords; // 3
		string publisher; // 4
		int year; //5
	};
	struct Query
	{
		int type;
		string strSearch;
		int year;
	};
}
using namespace PAT_1022;
int Execute_1022()
{
	int N, M;
	vector<Book> library;
	vector<vector<int>> result;
	vector<Query> query;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		Book b;
		while(cin >> b.ID)
		{
			if(getchar() == '\n')
				break;
		}
		getline(cin, b.title);
		getline(cin, b.author);
		string s;
		while(cin >> s)
		{
			b.keyWords.push_back(s);
			if(getchar() == '\n')
				break;
		}
		getline(cin, b.publisher);
		cin >> b.year;
		library.emplace_back(b);
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
		if(q.type != 5)
			getline(cin, q.strSearch);
		else
			cin >> q.year;
		//getchar();
		query.push_back(q);
	}
	
	for(int i = 0; i < query.size(); ++i)
	{
		for(int j = 0; j < library.size(); ++j)
		{
			switch(query[i].type)
			{
				case 1:
				{
					if(library[j].title == query[i].strSearch)
					{
						result[i].push_back(library[j].ID);
					}
				}
					
				break;
				case 2:
					if(library[j].author == query[i].strSearch)
					{
						result[i].push_back(library[j].ID);
					}
				break;
				case 3:
					for(auto w : library[j].keyWords)
					{
						if(w == query[i].strSearch)
						{
							result[i].push_back(library[j].ID);
							break;
						}
					}
				break;
				case 4:
					if(library[j].publisher == query[i].strSearch)
					{
						result[i].push_back(library[j].ID);
					}
				break;
				case 5:
					if(library[j].year == query[i].year)
					{
						result[i].push_back(library[j].ID);
					}
				break;
			}
		}
	}
	for(int i = 0; i < result.size(); ++i)
	{
		cout << query[i].type << ": ";
		if(query[i].type != 5)
			cout << query[i].strSearch << "\n";
		else
			cout << query[i].year << "\n";
		if(result[i].size() == 0)
			printf("Not Found\n");
		else
		{
			sort(result[i].begin(), result[i].end());
			for(auto id : result[i])
			{
				cout << id << "\n";
			}
		}
	}
	return 0;
}
