// pick a winner | a program that picks a winner and shows the name of the winner in the browser
// Taras Yakovchuk-Besarab, 12 March 2016
// CISP 360
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <fstream>



using namespace std;

int main()
{
	// bonus welcome message and instructions
	cout << "Welcome to the program which picks winners!" << endl;
	cout << "Please enter names, and when you're done just press ENTER" << endl;
	
	// bonus creating vector
  	string line;
  	vector <string> names;
	int index = 0;
	int randomNumber = 0;
	srand (time(NULL));

	// pre-input
	cout << "Please, enter your name: ";
	getline(cin,line);  	
	
	// checking pre-input for an empty line and getting input till the line is not empty
	while (!line.empty())
	{
		index++;
		names.push_back(line);
		cout << "Please, enter your name: ";
		getline(cin,line);
			
	}

	
	// getting the random number for the first winner
	if (index != 0) 
	{

		randomNumber = rand() % index;
  		
	
	}
	
	// writing a winner's name to a file

	// creating a file
	
	ofstream myfile ("winner.html");
	
	if (myfile.is_open())
    	{
		// html skeleton
		myfile << "<!DOCTYPE html>";
		myfile << "<html>";
		myfile << "<head>";
		myfile << "<title>Winner!</title>";	
		myfile << "<title>Winner!</title>";	
		myfile << "<body style='text-align: center;'>";	
					
			
			
			
		// BONUS a first, second, third winners will appear on the center of a page and the name will be bold
		
		// 1		
		myfile << "<p>The first winner is: <h1>";
		
		if (index != 0) 
		{

			myfile << names[randomNumber];
  		
	
		}	

		myfile << "!</h1></p>";

		// getting the second winner	
		myfile << "<p>The second winner is: <h1>";
		int randomNumber2 = 0;
		if (index !=0)
		{			
			randomNumber2 = rand() % index;
			while (randomNumber2 == randomNumber) {
			randomNumber2 = rand() % index;

			}
			myfile << names[randomNumber2];		
		}
		

		myfile << "!</h1></p>";	
		
		// getting the third winner
		myfile << "<p>The third winner is: <h1>";
		int randomNumber3 = 0;
		if (index !=0)
		{			
			randomNumber3 = rand() % index;
			while ((randomNumber3 == randomNumber)||(randomNumber3 == randomNumber2)) {
			
			randomNumber3 = rand() % index;

			}
			myfile << names[randomNumber3];		
		}
		
			

		myfile << "!</h1></p>";	
	
			
		// end html	   
		myfile << "</body>";
		myfile << "</html>";	
		// close the file
	      myfile.close();

    	}
    	
	else
   	{
      
		cout << "Error. File couldn't be open.";

    	}



	// bonus open the winner.html file in the browser
	
	cout << "Do you want to open a list of winner in your browser?";
	cout << endl << "Please, enter 0 if no, and 1 if yes: ";
	int answer = 0;
	cin >> answer;
		
	if (answer == 1) {
	system("firefox winner.html");
	}
	else {
		cout << "You can open a winner list manually. The file name is winner.html. Thank you!" << endl; 
	}


	return 0;

}




