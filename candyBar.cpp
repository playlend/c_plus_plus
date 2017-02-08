// candyBar | a program that provides information about candy bars
// Taras Yakovchuk-Besarab, 27 February 2016
// CISP 360
#include <iostream>
#include <string>
using namespace std;
// a creation of CandyBar structure	
struct CandyBar
		{
			string name;
			float weight;
			int calories;

		};

int main()
{
	// BONUS WELCOME MESSAGE
	cout << "Welcome to the program that provides information about candy bars!" << endl;


	// snack var

	CandyBar snack = {"Mocha Munch", 2.3, 350};

	// BONUS creating one more CandyBar var

	CandyBar almond = {"Almond Joy", 50, 232};
	
	// displaying the content of snack

	cout << "Candy #1" << endl;
	cout << "Name: " << snack.name << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Calories: " << snack.calories << endl;
	cout << endl;

	// BONUS displaying the content of an extra CandyBar var almond
	
	cout << "Candy #2" << endl;
	cout << "Name: " << almond.name << endl;
	cout << "Weight: " << almond.weight << endl;
	cout << "Calories: " << almond.calories << endl;
	cout << endl;

	// array of candy bar struct
			
	CandyBar candies[3] = 
		{
			{"Twix", 58, 307},
			{"Starburst", 59, 233},
			{"Snickers", 57, 273}

		};

	// displaying the content of an array

	// candy 3
	cout << "Candy #3" << endl;
	cout << "Name: " << candies[0].name << endl;
	cout << "Weight: " << candies[0].weight << endl;
	cout << "Calories: " << candies[0].calories << endl;
	cout << endl;
	
	// candy 4
	cout << "Candy #4" << endl;
	cout << "Name: " << candies[1].name << endl;
	cout << "Weight: " << candies[1].weight << endl;
	cout << "Calories: " << candies[1].calories << endl;
	cout << endl;
	
	// candy 5
	cout << "Candy #5" << endl;
	cout << "Name: " << candies[2].name << endl;
	cout << "Weight: " << candies[2].weight << endl;
	cout << "Calories: " << candies[2].calories << endl;
	cout << endl;




	// bonus dynamic array sample

	CandyBar * psome = new CandyBar[1];
	cout << "Add one more snack using the form below."<< endl;
	cout << "Enter the name of snack: ";
	getline(cin, psome[0].name);
	cout << "Enter the weight of snack: ";
	cin >> psome[0].weight;
	cout << "Enter the number of calories of snack: ";
	cin >> psome[0].calories;

	// candy #5
	cout << endl << "Candy #6" << endl;
	cout << "Name: " << psome[0].name << endl;
	cout << "Weight: " << psome[0].weight << endl;
	cout << "Calories: " << psome[0].calories << endl;
	cout << endl;


	
	return 0;
}
