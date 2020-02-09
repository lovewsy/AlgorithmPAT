#include "DataStructureInterface.h"
#include <cstdio>
#include <vector>
#include <string.h>

#define MAX_V 10
#define MAX_A 20
typedef struct ArcNode
{
	int Value;
	int Vertex;
}ArcNode;
namespace GraphAlgorithm
{
	int G[MAX_V][MAX_V];
	int VertexNum;
	int ArcNum;
	std::vector<ArcNode> Adj[MAX_V];
	int Visit[MAX_V];
	const int MAX_LEN = 999;
}

/***adjacent matrix**/

void DFS_Matrix(int index)
{
	//visit
	GraphAlgorithm::Visit[index] = 1;
	printf("%d ", index);
	for(int i = 0; i < GraphAlgorithm::VertexNum; ++i)
	{
		if(GraphAlgorithm::Visit[i] == 0 && 
			GraphAlgorithm::G[index][i] != GraphAlgorithm::MAX_LEN &&
			GraphAlgorithm::G[index][i] != 0)
		{
			DFS_Matrix(i);
		}
	}
}

void ExecuteDFS_Matrix()
{
	printf("DFS of adjacent matrix: ");
	for(int i = 0; i < GraphAlgorithm::VertexNum; ++i)
	{
		if(GraphAlgorithm::Visit[i] == 0)
			DFS_Matrix(i);
	}
	printf("\n");
}

/****adjacent list****/
void DFS_AdjList(int index)
{
	// visit
	GraphAlgorithm::Visit[index] = 1;
	printf("%d ", index);
	for(auto const & ArcNode : GraphAlgorithm::Adj[index])
	{
		if(GraphAlgorithm::Visit[ArcNode.Vertex] == 0)
			DFS_AdjList(ArcNode.Vertex);
	}
}

void ExecuteDFS_AdjList()
{
	printf("DFS of adjacent matrix: ");
	for(int i = 0; i < GraphAlgorithm::VertexNum; ++i)
	{
		if(GraphAlgorithm::Visit[i] == 0)
			DFS_AdjList(i);
	}
	printf("\n");
}

void Initialize(std::vector<ArcNode> Adj[])
{
	printf("Initialize a graph following the rule of adjacent matrix.\n");
	printf("Input the count of vertex: ");
	scanf("%d", &GraphAlgorithm::VertexNum);
	printf("Input an adjacent matrix.\n");
	for(int i = 0; i < GraphAlgorithm::VertexNum; ++i)
	{
		for(int j = 0; j < GraphAlgorithm::VertexNum; ++j)
		{
			scanf("%d", &GraphAlgorithm::G[i][j]);
			if(GraphAlgorithm::G[i][j] != 0 && GraphAlgorithm::G[i][j] != GraphAlgorithm::MAX_LEN)
			{
				Adj[i].push_back(ArcNode{GraphAlgorithm::G[i][j], j});
				++GraphAlgorithm::ArcNum;
			}
		}
	}
}

void ExecuteGraph()
{
	for(auto& vec : GraphAlgorithm::Adj)
	{
		vec.empty();
	}
	GraphAlgorithm::ArcNum = 0;
	Initialize(GraphAlgorithm::Adj);
	while(1)
	{
		printf("0: Return to last menu.\n1: DFS for adjacent matrix.\n2: DFS for adjacent list.\n");
		
		printf("Please select graph algorithm: ");
		memset(GraphAlgorithm::Visit, 0, sizeof(GraphAlgorithm::Visit));
		int option;
		scanf("%d", &option);
		switch(option)
		{
			case 0:
				return;
			case 1:
				ExecuteDFS_Matrix();
				break;
			case 2:
				ExecuteDFS_AdjList();
				break;
			default:
				printf("Illegal input!!\n");
				break;
		}
	}		
}
