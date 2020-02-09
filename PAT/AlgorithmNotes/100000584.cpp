#include "AlgorithmNotesInterface.h"

#include <cstdio>
#include <algorithm>
#define MAXSIZE 100
typedef struct TVShow
{
	int start, end;
}TVShow;

bool cmp(TVShow a, TVShow b)
{
	if(a.start != b.start)
		return a.start > b.start;
	else
		return a.end < b.end;
}

int Exe_100000584_A()
{
	int num;
	TVShow shows[MAXSIZE];
	while(1)
	{
		scanf("%d", &num);
		if(num == 0)
			return 0;
		for(int i = 0; i < num; ++i)
		{
			scanf("%d %d", &shows[i].start, &shows[i].end);
		}
		std::sort(shows, shows+num, cmp);
		int LastStart = shows[0].start;
		int ShowNum = 1;
		for(int i = 1; i<num; ++i)
		{
			if(LastStart >= shows[i].end)
			{
				LastStart = shows[i].start;
				++ShowNum;
			}
		}	
		printf("%d\n", ShowNum);
	}
	return 0;	
}

int Exe_100000584_B()
{
	double stage1 = 18.0f;
	int Num1 = 8;
	int A;
	double cost;
	while(scanf("%d", &A), A)
	{		
		cost = 0.0;
		int le = A / Num1;
		A -= le * Num1;
	
		if(le > 0 && A <= 4)
		{
			cost += A*2.4f;
		}
		else
		{
			cost += 10.0f;
			A -= 4;
			if(A > 0)
			{
				cost += A*2.0f;
			}
		}
		
		if(le > 0)
			cost += stage1*(float)(le);
		if(cost == (int)cost)
		{
			printf("%d\n", (int)cost);
		}
		else
		{
			printf("%.1lf\n", cost);
		}
			
	}
	
	return 0;
}


typedef struct Station
{
	double p;
	int d;
}Station;
bool CmpStation(Station a, Station b)
{
	if(a.d != b.d)
		return a.d < b.d;
	else
		return a.p < b.p;
}
#define MAX_STATIONS 500
int Exe_100000584_C()
{
	Station stations[MAX_STATIONS];
	double cmax, dis, Rdis, MaxRdis; 
	int N, CheapStation, Location, CurrDis, LastDis, k;
	double SumPrice, GasUnits, DecreasePrice;
	bool CanReach;
	while(scanf("%lf %lf %lf %d", &cmax, &dis, &Rdis, &N) != EOF)
	{	
		for(int i = 0; i < N; ++i)
		{
			scanf("%lf %d", &stations[i].p, &stations[i].d);
		}
		std::sort(stations, stations+N, CmpStation);
		if(stations[0].d != 0)
		{
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		MaxRdis = cmax * Rdis;
		CheapStation = 0;
		Location = 0;
		CurrDis = 0;
		LastDis = 0;
		SumPrice = 0.0;
		DecreasePrice = 0.0;
		CanReach = true;
		k = 1;
		while(k < N)
		{
			CurrDis = stations[k].d - stations[Location].d;
			if(CurrDis <= MaxRdis)
			{
				if(stations[k].p <= stations[Location].p)
				{					
					SumPrice += stations[Location].p * (1.0*CurrDis/(double)Rdis);
					Location = k;
					CheapStation = 0;
				}
				else
				{
					if(CheapStation == 0 || (CheapStation != 0 && stations[k].p <= stations[CheapStation].p))
					{
						CheapStation = k;
					}
				}
				++k;
			}
			else
			{
				if(CheapStation == 0)
				{
					CanReach = false;
					break;
				}
				else
				{
					CurrDis = stations[CheapStation].d - stations[Location].d;
					SumPrice += stations[Location].p * (1.0*CurrDis/(double)Rdis);
					DecreasePrice += (stations[CheapStation].p-stations[Location].p) * (1.0*(MaxRdis-CurrDis)/Rdis);
					Location = CheapStation;
					k = CheapStation + 1;
					CheapStation = 0;
				}
			}			
		}
		if(!CanReach)
		{
			printf("The maximum travel distance = %.2f\n", stations[Location].d+MaxRdis);
			continue;
		}
		CurrDis = dis - stations[Location].d;	
		if(CurrDis > MaxRdis)
		{
			if(CheapStation == 0)
			{
				printf("The maximum travel distance = %.2f\n", stations[Location].d+MaxRdis);
				continue;
			}
			else
			{
				LastDis = dis - stations[CheapStation].d;
				if(LastDis > MaxRdis)
				{
					printf("The maximum travel distance = %.2f\n", stations[CheapStation].d+MaxRdis);
					continue;
				}
				else
				{
					SumPrice += stations[Location].p * (1.0*MaxRdis/(double)Rdis);
					SumPrice += stations[CheapStation].p * (1.0*(CurrDis-MaxRdis)/(double)Rdis);
				}
			}
		}
		else
		{
			SumPrice += stations[Location].p * (1.0*CurrDis/Rdis);
		}	
		SumPrice -= DecreasePrice;		
		printf("%.2lf\n", SumPrice);
	}
	return 0;
}
