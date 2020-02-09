#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_N 1001
struct CityGraph
{
	vector<int> AdjList[MAX_N];
	int N;
};

void DFS_City(const CityGraph& G, int index, bool visit[], int enmy)
{
	visit[index] = true;
	for(auto city : G.AdjList[index])
	{
		if(!visit[city] && city != enmy)
			DFS_City(G, city, visit, enmy);
	}
}
int Execute_1013()
{
	CityGraph G;
	vector<int> AdjList[MAX_N];
	vector<int> Check;
	int M, K;
	bool visit[MAX_N];
	scanf("%d %d %d", &G.N, &M, &K);
	for(int i = 0; i < M; ++i)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		G.AdjList[src].push_back(dest);
		G.AdjList[dest].push_back(src);
	}
	for(int i = 0; i < K; ++i)
	{
		int city;
		scanf("%d", &city);
		Check.push_back(city);
	}
	for(int d = 0; d < Check.size(); ++d)
	{
		int city = Check[d];
		memset(visit, false, sizeof(visit));
		int SearchTime = 0;
		for(int i = 1; i <= G.N; ++i)
		{
			if(!visit[i] && i != city)
			{
				SearchTime++;
				DFS_City(G, i, visit, city);
			}
		}
		SearchTime = SearchTime -1 > 0 ? SearchTime-1 : 0;
		printf("%d", SearchTime);
		if(d != Check.size()-1)
			printf("\n");
	}
	return 0;
}
