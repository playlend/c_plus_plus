#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
	
// structure student
using namespace std;

struct student 
{
	string name;
	int scores[9];
	int totalOf6;
	char grades[5] = {'A', 'B', 'C', 'D', 'F'};
	string advices[5] = {"You did excellent!", "You did good; however, there is a room for improvement.", "You did okay, but you need to study more.", "You barely passed!", "You failed!"};
	char grade;
	string advice;
		
};

// function prototypes

// get first and last name of a student

string GetStudentName();

// get nine quiz scores

int GetScores(int);

// drop three lowest scores and add the rest
void bubble(int grade[]);
int totalScore(int total[]);

// create an array which corresponds to word of advice
int LetterGradeQuizes(int);

// print a report
void report(string, int, char, string);

int main()
{
	student index;


	index.name = GetStudentName();


	int counter = 0;
	
	for (counter = 0; counter <=8; counter++)
	{
		index.scores[counter] = GetScores(counter+1);

	}
	
	bubble(index.scores);
	
	
	index.totalOf6 = totalScore(index.scores);
	
	
	int number = LetterGradeQuizes(index.totalOf6);

	index.grade = index.grades[number];
	index.advice = index.advices[number];

	// report
	
	int answer;
	cout << "Do you want me to print a report for you?" << endl;
	cout << "Please, enter 1 for yes, and 0 for no: ";
	cin >> answer;
	// BONUS system clear	
	if (answer == 1) {
		system("clear");
		report(index.name, index.totalOf6, index.grade, index.advice);
		
	}
	else {
		system("clear");
		cout << "Thank you!"<< endl;

	}


	
	return 0;

}

// get name
string GetStudentName() 
{
	cout << "Please, enter your first and last name: ";
	
	student index;

	getline(cin, index.name);

	return index.name;
	
}

// get scores
int GetScores(int index)
{
	int score;	
	cout << "Please, enter the score for quiz number " << index << ": ";
	
	cin >> score;	
	// BONUS input-validation
	while (!(score>=0 && score <=100))
	{
		cout << "Please enter the correct score(the score has to be between 0 and 100): ";
		cin >> score;
	}

	return score;


}

// BONUS sort scores and add
void bubble(int grade[])
{
	int temp;	
	int arraySize = 9;
	int maxElement = arraySize - 1;
	int index;
	for (maxElement= arraySize - 1; maxElement >= 1; maxElement=maxElement-1)
	{
		for (index = 0; index <= (maxElement-1); index++)
		{
			if (grade[index] > grade[index+1]) 
			{
				temp = grade[index];
				grade[index] = grade[index+1];
				grade[index+1] = temp;	
			}
			
		}
		
	}

}
// calc total score of 6 quizes
int totalScore (int total[])
{
	int finalScore = 0;
	for (int i=3; i <= 8; i++)
	{
		finalScore = finalScore + total[i];
	}


	return finalScore;
}

// assinging a grade
int LetterGradeQuizes(int score)
{
	
	int number;	
	if (score<=600 && score>=540)
	{
		number = 0;
		
	}
	else if (score <= 539 && score >= 480)
	{
		number = 1;
		

	}
	else if (score <= 479 && score >= 420)
	{
		number = 2;
						
		
	}
	else if (score <= 419 && score >= 360)
	{
		number = 3;
	}	

	else if (score <= 359 && score >= 0)
	{
	number = 4;
		
		
	}
return number;
	

}

// print a report
void report(string name, int total, char grade, string advice)
{
	cout << "Name: " << name << endl;
	cout << "Total points for quizes(3 lowest were dropped): " << total << endl;
	cout << "Overall grade: " << grade << endl;
	cout << "Advice: " << advice << endl;

}
