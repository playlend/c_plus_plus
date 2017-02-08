// madlib | a program for displaying user input inside of the paragraph
// Taras Yakovchuk-Besarab, 4 March 2016
// CISP 360
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

int main()
{
	// welcome message
	cout << "Welcome to the Mad Libs game!" << endl;
	cout << "You're going to be prompted to enter some words. In order for a program to create a good paragraph try to enter all of them." << endl;
	cout << "Have fun!" << endl; 	
		
	// array declaration
	string wordInput[27];

	// declaration and initialiaztion of vars for input

	wordInput[0] = "TIME-SPAN";
	wordInput[1] = "NOUN";
	wordInput[2] = "VERB";
	wordInput[3] = "VERB";
	wordInput[4] = "NOUN(plural or singular)";
	wordInput[5] = "NOUN";
	wordInput[6] = "VERB ING";
	wordInput[7] = "2 WORD OCCUPATION";
	wordInput[8] = "NOUN";
	wordInput[9] = "NOUN";
	wordInput[10] = "FAMOUS PERSON";
	wordInput[11] = "ADJECTIVE";
	wordInput[12] = "VERB";
	wordInput[13] = "NOUN";
	wordInput[14] = "NOUN(plural)";
	wordInput[15] = "ADJECTIVE";
	wordInput[16] = "NOUN(plural)";
	wordInput[17] = "VERB PREPOSITION";
	wordInput[18] = "INTEGER";
	wordInput[19] = "VERB";
	wordInput[20] = "FLOAT";
	wordInput[21] = "LETTER";
	wordInput[22];
	wordInput[23] = "VERB ING";	
	wordInput[24] = "VERB";
	wordInput[25] = "VERB";	
	wordInput[26] = "NOUN";
	
	// additional vars	
	int intNumber;
	char letter;
	float floatNumber;
	
	// vars
	string time;
	
	
	
	string entered;
	
	int counter = 0;
	

	// main loop
	for(counter = 0; counter<=27; counter++) {
		// switch case for input validation and assignment input for specific data types
		switch (counter) {
			// validation for time span			
			case 0:
				
				cout << "Enter TIME-SPAN: ";
				getline(cin, time);
		
				
				while(time != "second" && time != "minute" && time != "hour"
					&&	time != "day" && time != "morning" && time != "noon"
					&& time != "evening" && time != "week" && time != "month" &&
					time != "year" && time != "decade")
									
					 {
				cout << "Please, enter the valid TIME-SPAN(possible values are second, minute, hour, day, morning, noon, evening, week, month, year, decade): ";
				
				
				getline(cin, time);
							
				
					}
				break;
			// different data types		 	
			case 18:
				cout << "Please, enter " << wordInput[counter] << ": ";
					
				cin>> intNumber;
				break;
			case 19:
				cout << "Please, enter " << wordInput[counter] << ": ";
						

				cin >> wordInput[counter];
				break;	
			
			case 20:
				cout << "Please, enter " << wordInput[counter] << ": ";
						

				cin>>floatNumber;
				break;
			case 21:
				cout << "Please, enter " << wordInput[counter] << ": ";
						

				cin>> letter;
				break;
			// empty line separates two paragraphs
			case 22:
				cout << endl;
				break;

			// bonus adding new sensences

	
			case 23 :
				cout << "Please, enter " << wordInput[counter] << ": ";
						

			cin >> wordInput[counter];
				break;
			case 24 :
				cout << "Please, enter " << wordInput[counter] << ": ";
						

			cin >> wordInput[counter];
				break;
			case 25 :
				cout << "Please, enter " << wordInput[counter] << ": ";
						

			cin >> wordInput[counter];
				break;
			case 26 :
				cout << "Please, enter " << wordInput[counter] << ": ";
						

			cin >> wordInput[counter];
				break;
		// added validation for entered data
			case 27:
				do {
				cout << "Please, enter done to submit all input: ";
			
				cin >> entered;

			}
			while(entered != "DONE" && entered != "done" && entered != "Done"); {
				
				getline(cin, entered);			
				
				}
				break;
			default:
				cout << "Please, enter " << wordInput[counter] << ": ";
						

			getline(cin, wordInput[counter]);
				break;

		}		
	
	}
	
	
	

	
	// print
	

//BONUS cleared the screen
	system("clear");

	// printing paragraph
	cout << "A Day In The Life Of a College Student" << endl;

	
	cout << "Every " << time << ", I wake up and get off my " << wordInput[1] << ".";
	cout << " I don't always have time to " << wordInput[2] << " a shower, but I always make sure to " << wordInput[3] << " my hair.";
	cout << " Once that's done I get some " << wordInput[4] << ", and then it's off to my first " << wordInput[5] << ".";
	cout << " I often get caught " << wordInput[6] << " in class.";
	cout << " No one likes it when the " << wordInput[7] << " gives a surprise " << wordInput[8] << ".";
	cout << " My second class is " << wordInput[9] << " Theory.";
	cout << " Dr. " << wordInput[10] << " is incredibly " << wordInput[11] << ", but I never " << wordInput[12] << " her because of her thick " << wordInput[13] << ".";
	cout << " Her " << wordInput[14] << ", however, are really " << wordInput[15] << ".";
	cout << " After lunch, I have no more " << wordInput[16] << " and I'm free to " << wordInput[17] << " my friends.";
	cout << " This is right around " << intNumber << " o'clock.";
	cout << " Before I go to bed I " << wordInput[19] << " a little bit, in my room, " << floatNumber << " " << letter << ".";
	cout << endl;

	// print

	//BONUS more sentences
	
	cout << "I'm really " << wordInput[23] << " my classes.";
	cout << " I " << wordInput[24] << " to do my homework.";
	cout << " I usually " << wordInput[25] << " to go to bed on time.";
	cout << " Have a happy " << wordInput[26] << "!";
	cout << endl;


 
	return 0;

}


