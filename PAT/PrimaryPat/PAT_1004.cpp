#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <queue>
using namespace std; 

#define MAX_N 101
int Execute_1004()
{
	int NumNodes, NumNonLeaf;
	scanf("%d %d", &NumNodes, &NumNonLeaf);
	if(NumNodes == 0)
		return 0;
	if(NumNonLeaf == 0)
	{
		printf("%d", NumNodes);
		return 0;
	}
	vector<int> Nodes[MAX_N];
	for(int i = 0; i < NumNonLeaf; ++i)
	{
		int RootId, ChildrenNum;
		scanf("%d %d", &RootId, &ChildrenNum);		
		for(int j = 0; j < ChildrenNum; ++j)
		{
			int TmpId;
			scanf("%d", &TmpId);
			Nodes[RootId].push_back(TmpId);
		}
	}
	
	queue<int> LevelNodes;
	LevelNodes.push(1);
	while(!LevelNodes.empty())
	{
		int LevelLeafNum = 0;
		int LevelNum = LevelNodes.size();
		for(int i = 0; i < LevelNum; i++)
		{
			int Id = LevelNodes.front();
			if(Nodes[Id].size() == 0)
			{
				LevelLeafNum++;
			}
			else
			{
				for(auto tmp : Nodes[Id])
				{
					LevelNodes.push(tmp);
				}
			}
			LevelNodes.pop();
		}
		printf("%d", LevelLeafNum);
		if(!LevelNodes.empty())
			printf(" ");
	}
	return 0;
} 
