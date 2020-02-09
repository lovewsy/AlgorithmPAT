#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
#define MaxN 500
struct ArcNode
{
	int vex;
	int len;
};
int Visit[MaxN];
vector<ArcNode> Adj[MaxN];
int CityTeams[MaxN];
int MinLength, MaxTeams, ShortestPaths;
int CityNum, RoadNum, Src, Dest;
void DFS(int index, int length, int SumTeams, int dest)
{
	Visit[index] = 1;
	if(index == dest)
	{
		if(MinLength == 0)
		{
			ShortestPaths = 1;
			MinLength = length;
			MaxTeams = SumTeams;
		}			
		else
		{
			if(MinLength == length)
			{
				MaxTeams = SumTeams > MaxTeams ? SumTeams : MaxTeams;
				++ShortestPaths;
			}
			else
			{
				if(MinLength > length)
				{
					ShortestPaths = 1;
					MinLength = length;
					MaxTeams = SumTeams;
				}
			}
		}
		return;
	}
	
	for(auto const & arc : Adj[index])
	{
		if(Visit[arc.vex] == 0 && (MinLength == 0 || MinLength >= (length + arc.len)))
		{
			DFS(arc.vex, length + arc.len, SumTeams + CityTeams[arc.vex], dest);
			Visit[arc.vex] = 0;
		}
	}
}

void Execute_1003()
{
	memset(Visit, 0, sizeof(Visit));
	scanf("%d %d %d %d", &CityNum, &RoadNum, &Src, &Dest);
	for(int i = 0; i < CityNum; ++i)
		scanf("%d", &CityTeams[i]);
	for(int i = 0; i < RoadNum; ++i)
	{
		int s, d;
		ArcNode tmp;
		scanf("%d %d %d", &s, &tmp.vex, &tmp.len);
		Adj[s].push_back(tmp);
		d = tmp.vex;
		tmp.vex = s;
		Adj[d].push_back(tmp);
	}
	MinLength = 0;
	MaxTeams = 0;
	ShortestPaths = 0;
	DFS(Src, 0, CityTeams[Src], Dest);
	printf("%d %d", ShortestPaths, MaxTeams);
}
