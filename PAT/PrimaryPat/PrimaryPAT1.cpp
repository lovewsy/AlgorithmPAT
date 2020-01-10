/*Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.
* Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
*
* Input:
* Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations.
* Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and the K lines constaining 
* the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
* 		Input Sample:
* 		2
* 		5
* 		1234567890001 95
* 		1234567890005 100
* 		1234567890003 95
* 		1234567890002 77
* 		1234567890004 85
*		4
*		1234567890013 65
*		1234567890011 25
*		1234567890014 100
*		1234567890012 85
* Output:
* For each test case, first print in one line the total number of testees. Then print the final ranklist in the following formt:
* 		registration_number final_rank location_number local_rank
* The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with 
* the same rank, and the output must be sorted in nondecreasing order of their registrantion numbers
*		Ouput Sample:
*		9
*		1234567890005 1 1 1
*		1234567890014 1 2 1
*		1234567890001 3 1 2

*		1234567890003 3 1 2
*		1234567890004 5 1 4
*		1234567890012 5 2 2
*		1234567890002 7 1 5
*		1234567890013 8 2 3
*		1234567890011 9 2 4
*/

#include "../PCH.h"
#include "PrimaryPatInterface.h"

namespace TestCasePat1
{
	const int Location_Count = 2;	// count of test locations
	int Count_Testee[Location_Count] = {5, 4};
	const char** RegistIds[Location_Count];
	int* Scores[Location_Count];
	void InitTestCase()
	{
		for (int i = 0; i < Location_Count; ++i)
		{
			RegistIds[i] = (const char**)malloc(sizeof(char*)*Count_Testee[i]);
			Scores[i] = (int*)malloc(sizeof(int)*Count_Testee[i]);
		}
		/*Test location 1*/
		RegistIds[0][0] = "1234567890001";
		RegistIds[0][1] = "1234567890005";
		RegistIds[0][2] = "1234567890003";
		RegistIds[0][3] = "1234567890002";
		RegistIds[0][4] = "1234567890004";
		Scores[0][0] = 95;
		Scores[0][1] = 100;
		Scores[0][2] = 95;
		Scores[0][3] = 77;
		Scores[0][4] = 85;

		/*Test location 2*/
		RegistIds[1][0] = "1234567890013";
		RegistIds[1][1] = "1234567890011";
		RegistIds[1][2] = "1234567890014";
		RegistIds[1][3] = "1234567890012";
		Scores[1][0] = 65;
		Scores[1][1] = 25;
		Scores[1][2] = 100;
		Scores[1][3] = 85;
		
		printf("Input Sample: \n");
		printf("%d\n", Location_Count);
		
		for(int i = 0; i < Location_Count; ++i)
		{
			printf("%d\n", Count_Testee[i]);
			for(int j = 0; j < Count_Testee[i]; ++j)
			{			
				printf("%s %d\n", RegistIds[i][j], Scores[i][j]);
			}
		}
	}
}

typedef struct Student
{
	const char* id;
	int LocationNum;
	int LocalRank;
	int Score;		
}Student;
bool Cmp(Student t1, Student t2)
{
	if(t1.Score != t2.Score) 
		return t1.Score > t2.Score;
	else
		return strcmp(t1.id, t2.id) < 0;
}

void PATRanking()
{
	TestCasePat1::InitTestCase();
	Student students[100];
	int k = 0;
	for(int i = 0; i < TestCasePat1::Location_Count; ++i)
	{
		int start = k;
		for(int j = 0; j < TestCasePat1::Count_Testee[i]; ++j)
		{
			students[k].id = TestCasePat1::RegistIds[i][j];
			students[k].Score = TestCasePat1::Scores[i][j];
			students[k].LocationNum = i+1;
			k++;
		}
		std::sort(students+start, students+k, Cmp);
		students[start].LocalRank = 1;
		for(int m = start+1; m < k; ++m)
		{
			if(students[m].Score != students[m-1].Score)
				students[m].LocalRank = m-start+1;
			else
				students[m].LocalRank = students[m-1].LocalRank;
		}
	}
	
	std::sort(students, students+k, Cmp);
	printf("Output:\n");
	printf("%d\n", k);
	int FinalRank = 1;
	printf("%s %d %d %d\n", students[0].id, FinalRank, students[0].LocationNum, students[0].LocalRank);
	for(int i = 1; i < k; ++i)
	{
		if(students[i].Score != students[i-1].Score)
			FinalRank = i+1;
		printf("%s %d %d %d\n", students[i].id, FinalRank, students[i].LocationNum, students[i].LocalRank);
	}
	for(int i = 0; i < TestCasePat1::Location_Count; ++i)
	{
		delete TestCasePat1::RegistIds[i];
		delete TestCasePat1::Scores[i];
	}
}



