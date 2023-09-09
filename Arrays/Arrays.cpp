#include <iostream>
using namespace std;

int mainArrays()
{
	const int numStudents = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	// using arrays
	int scores[numStudents]{ 84, 92, 76, 81, 56 };
	
	int totalScore = score0 + score1 + score2 + score3 + score4;
	
	double avgScore = static_cast<double>(totalScore) / numStudents;

	int totalScoreArrays = 0;
	double avgScoreArrays = 0.0;
	for (int i = 0; i < numStudents; i++)
	{
		totalScoreArrays += scores[i];
	}
	avgScoreArrays = static_cast<double>(totalScoreArrays) / numStudents;

	cout << avgScoreArrays << endl;
	
	int maxScore = 0;

	for (int i = 0; i < numStudents; i++)
	{
		maxScore = maxScore > scores[i] ? maxScore : scores[i];
	}

	cout << maxScore << endl;

	int minScore = 99999999;
	for (int i = 0; i < numStudents; i++)
	{
		minScore = minScore < scores[i] ? minScore : scores[i];
	}
	cout << minScore << endl;
	
	return 0;
}