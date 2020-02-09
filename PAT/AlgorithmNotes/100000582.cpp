#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
#define MaxSize 201
int Exe_100000582_A()
{
	int Books[MaxSize];
	int Readers[MaxSize];
	int M, N;
	while(scanf("%d %d", &N, &M) != EOF)
	{	
		memset(Books, 0, MaxSize*sizeof(int));
		for(int i = 0; i<N; ++i)
		{
			scanf("%d", &Readers[i]);
			Books[Readers[i]]++;
		}
		for(int i=0; i<N; ++i)
		{
			if(Books[Readers[i]] > 1)
			{
				printf("%d\n", Books[Readers[i]]-1);
			}
			else
			{
				printf("BeiJu\n");
			 
			}
		}
	}
	return 0;
}

#define MaxNum 102
int Exe_100000582_B()
{	
	int m, n;
	while(scanf("%d", &m) != EOF)
	{	
		for(int i = 0; i < m; ++i)
		{
			int Data[MaxNum][MaxNum];
			memset(Data, 0, sizeof(Data));
			
			int Num[MaxNum]; 
			int Team[MaxNum];
			memset(Num, 0, sizeof(Num));
			memset(Team, 0, sizeof(Team));
			scanf("%d", &n);
			for(int j = 0; j<n; ++j)
			{
				scanf("%d", &Num[j]);
			}
			for(int k = 0; k<n; ++k)
			{
				scanf("%d", &Team[k]);
			}
			for(int r = 0; r < n; ++r)
			{
				Data[0][Team[r]] = 1;
				Data[MaxNum-1][Num[r]] = 1;
				++Data[Team[r]][Num[r]]; 
			}
			for(int s = 1; s < MaxNum; ++s)
			{
				if(Data[0][s] == 1)
				{
					printf("%d={", s);
					bool IsFirst = true;
					for(int t = 1; t < MaxNum-1; ++t)
					{
						if(Data[MaxNum-1][t] == 1)
						{
							if(!IsFirst)
							{
								printf(",");
							}
							printf("%d=%d", t, Data[s][t]);
							IsFirst = false;
						}
					}
					printf("}\n");
				}
			}
		}
	}
	return 0;
}


#define NumPeople 100001
#define MaxNumSize 10001
int Exe_100000582_C()
{
	int people[NumPeople]; 
	int nums[MaxNumSize];
	int k;
	while(scanf("%d", &k) != EOF)
	{
		memset(people, 0, sizeof(people));
		memset(nums, 0, sizeof(nums));
		for(int i = 0; i < k; ++i)
		{
			scanf("%d", &people[i]);
			++nums[people[i]];
		}
		int UniqueNum = 0;
		for(int i = 0; i < k; ++i)
		{
			if(nums[people[i]] == 1)
			{
				UniqueNum = people[i];
				break;
			}
		}
		if(UniqueNum == 0)
		{
			printf("None\n");
		}
		else
		{
			printf("%d\n", UniqueNum);
		}
	}
	return 0;
}


#define AsciiNum 200
int Exe_100000582_D()
{
	string str1, str2;
	int HashTable[AsciiNum];
	cin.get();
	while(!(getline(cin, str1).eof()))
	{	
		getline(cin, str2);
		memset(HashTable, 0, sizeof(HashTable));
		int k = 0;
		if(str2.compare("") != 0)
		{	
			while(str2[k] != '\0')
			{	
				HashTable[str2[k]] = 1;
				++k;
			}
		}
		int j = 0;
		bool IsOut = false;
		if(str1.compare("") != 0)
		{
			while(str1[j] != '\0')
			{
				printf("%d\n", HashTable[str1[j]]);
				if(HashTable[str1[j]] == 0)
				{
					printf("%c", str1[j]);
					IsOut = true;
				}
				++j;
			}
		}
		if(IsOut)
		{
			printf("\n");
		}
	}
	return 0;
}
