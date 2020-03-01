/*
* Key point: 
* The path from PBMC to S should be nonreversing, 
* which means we can not use the bikes of next station to adjust the previous station in the path.
*/
#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

namespace PAT_1018
{
	struct ArcNode
	{
		int dest;
		int value;
	};
	
	struct Station
	{
		int count;
		vector<ArcNode> arcs;
		int value;
	};

	int C, N, S, M;
	vector<Station> Graph;
	vector<int> visit;
	vector<int> minPath;
	int minLength = 99999999, minSend, minBack;
}
using namespace PAT_1018;
void DFS(int index, vector<int>& path, int length)
{
	if(index == 0)
	{
		int send = 0, back = 0;
		for(int i = path.size()-1; i >= 0; --i)
		{
			back += Graph[path[i]].value;
			
			if(back < 0)
			{
				send += abs(back);
				back = 0;
			}
		}
		if(minPath.size() == 0)
		{
			minPath.assign(path.begin(), path.end());
			minLength = length;
			minSend = send;
			minBack = back;
		}
		else
		{
			if(minLength > length || (minLength == length && (minSend > send || (minSend == send && minBack > back))))
			{
				minPath.empty();
				minPath.assign(path.begin(), path.end());
				minLength = length;
				minSend = send;
				minBack = back;
			}
		}
		return;
	}
	
	visit[index] = 1;
	path.push_back(index);
	for(int i = 0; i < Graph[index].arcs.size(); ++i)
	{
		int dest = Graph[index].arcs[i].dest;
		if(visit[dest] == 0 && length+Graph[index].arcs[i].value <= minLength)
		{
			if(dest == 0)
			{
				DFS(dest, path, length+Graph[index].arcs[i].value);
			}
			else
			{
				DFS(dest, path, length+Graph[index].arcs[i].value);
			}
		}
	}
	path.pop_back();
	visit[index] = 0;
}

int Execute_1018()
{
	scanf("%d %d %d %d", &C, &N, &S, &M);

	Graph.resize(N+1);	
	visit.resize(N+1, 0);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &Graph[i].count);
		Graph[i].value = Graph[i].count - C/2;
	}
		
	for(int i = 0; i < M; ++i)
	{
		int src, dest, value;
		scanf("%d %d %d", &src, &dest, &value);
		Graph[src].arcs.push_back(ArcNode{dest, value});
		Graph[dest].arcs.push_back(ArcNode{src, value});
	}
	vector<int> path;
	DFS(S, path, 0);
	
	printf("%d ", minSend);
	printf("0");
	for(int i = minPath.size()-1; i >= 0; --i)
	{
		printf("->%d", minPath[i]);
	}
	printf(" %d", minBack);
	return 0;
}
