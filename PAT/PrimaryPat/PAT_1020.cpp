#include "PrimaryPatInterface.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace PAT_1020
{
	struct Node
	{
		int num;
		Node * left;
		Node * right;
	};
}

using namespace PAT_1020;
void CreateTree(vector<int>& post, vector<int>& in, int start, int end, int postStart, int postEnd, Node*& node)
{
	if(start == end)
	{
		node = new Node();
		node->num = in[start];
		node->left = nullptr;
		node->right = nullptr;
		return;
	}
	if(start > end)
		return;
	int root = post[postEnd];
	int index = -1;
	for(int i = start; i <= end; ++i)
	{
		if(in[i] == root)
		{
			index = i;
			break;
		}
	}
	node = new Node();
	node->num = root;
	node->left = nullptr;
	node->right = nullptr;
	CreateTree(post, in, start, index-1, postStart, postEnd-(end-index)-1 ,node->left);
	CreateTree(post, in, index+1, end, postEnd-(end-index), postEnd-1, node->right);
}

void FreePostOrder(Node*& p)
{
	if(p == nullptr)
		return;
	FreePostOrder(p->left);
	FreePostOrder(p->right);
	delete p;
	p = nullptr;
}
int Execute_1020()
{
	int N;
	vector<int> post, in;
	scanf("%d", &N);
	queue<Node*> Q;
	
	for(int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		post.push_back(tmp);
	}
	for(int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	Node* tree = nullptr;
	CreateTree(post, in, 0, N-1, 0, N-1, tree);
	
	if(tree != nullptr)
		Q.push(tree);
	while(Q.size() != 0)
	{
		Node* tmp = Q.front();
		printf("%d", tmp->num);
		Q.pop();
		if(tmp->left != nullptr)
			Q.push(tmp->left);
		if(tmp->right != nullptr)
			Q.push(tmp->right);
		if(Q.size() != 0)
			printf(" ");
	}
	FreePostOrder(tree);
	return 0;
}
