#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

namespace PAT_1021
{
	int N;
	vector<bool> visit;
	vector<bool> reached;
	vector<vector<int>> Graph;
	vector<int> depths;
	bool HasCircle;
	void DFS(int index, int depth, int root)
	{
		depths[root] = max(depths[root], depth);
		visit[index] = true;
		for(int i = 0; i < Graph[index].size(); ++i)
		{		
			int tmp = Graph[index][i];
			if(!visit[tmp])
				DFS(tmp, depth+1, root);
			/*else
				HasCircle = true;*/
		}
	}
}
using namespace PAT_1021;


int Execute_1021()
{
	scanf("%d", &N);
	reached.resize(N+1, false);
	Graph.resize(N+1);
	depths.resize(N+1);
	fill(depths.begin(), depths.end(), 0);
	for(int i = 0; i < N-1; ++i)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		Graph[src].push_back(dest);
		Graph[dest].push_back(src);
	}
	
	int numCom = 0;
	visit.resize(N+1);
	fill(visit.begin(), visit.end(), false);
	HasCircle = false;
	for(int j = 1; j <= N; ++j)
	{
		if(!visit[j])
		{
			DFS(j, 0, j);
			numCom++;
		}
	}
	
	if(numCom != 1 || HasCircle)
	{
		printf("Error: %d components", numCom);
	}
	else
	{
		for(int j = 1; j <= N; ++j)
		{
			fill(visit.begin(), visit.end(), false);
			DFS(j, 0, j);
		}
		int maxDepth = depths[1];
		for(int i = 1; i < depths.size(); ++i)
		{
			if(maxDepth < depths[i])
				maxDepth = depths[i];
		}
		for(int i = 1; i < depths.size(); ++i)
		{
			if(maxDepth == depths[i])
				printf("%d\n", i);
		}
	}

	return 0;
}
