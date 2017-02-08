// tipCalc | a program created to calculate tips and add them to the bill
// Taras Yakovchuk-Besarab, 22 January 2016
// CISP 360

#include <iostream>
#include <cmath>

// function prototypes start
int GetAmountOfTheBill();
void print_tips(double);

double calc_10(int);
double calc_15(int);
double calc_20(int);
double calc_25(int);
// function prototypes end

using namespace std;

// constants for the tip percents 
const double tip10 = 0.10;
const double tip15 = 0.15;
const double tip20 = 0.20;
const double tip25 = 0.25; 

int main ()

{
	// welcome message
	
	cout << "Welcome to the program which calculates your bill!" << endl;
	
	int amountOfBill = 0;
	amountOfBill = GetAmountOfTheBill();
	
	// declaration and initialization of required vars
	double tipTen = 0;
	double tipFifteen = 0;
	double tipTwenty = 0;
	double tipTwentyFive = 0;
	
	// assinging the results to the declared vars in order to use them to print results
	tipTen = calc_10(amountOfBill);
	tipFifteen = calc_15(amountOfBill);
	tipTwenty = calc_20(amountOfBill);
	tipTwentyFive = calc_25(amountOfBill);
		
	// calling void function which prints the results
	print_tips(tipTen);
	print_tips(tipFifteen);
	print_tips(tipTwenty);
	print_tips(tipTwentyFive);
		
	

	cout << endl;
	return 0;

}

// promting the user to get the amount of the bill
int GetAmountOfTheBill() 
{
	
	int amountOfBill = 0;
 	cout << "Enter the amount of your bill: ";
	cin >> amountOfBill;
	return amountOfBill;

}

// function that calculates the 10 percent tip
double calc_10(int amountOfBill) 
{

	double billTip10 = 0;
	billTip10 = (amountOfBill * tip10)+ amountOfBill;
	return billTip10;

}

// function that calculates the 15 percent tip
double calc_15(int amountOfBill) 
{

	double billTip15 = 0;
	billTip15 = (amountOfBill * tip15)+ amountOfBill;
	return billTip15;

}

// function that calculates the 20 percent tip
double calc_20(int amountOfBill) 
{

	double billTip20 = 0;
	billTip20 = (amountOfBill * tip20)+ amountOfBill;
	return billTip20;

}

// function that calculates the 25 percent tip
double calc_25(int amountOfBill) 
{

	double billTip25 = 0;
	billTip25 = (amountOfBill * tip25)+ amountOfBill;
	return billTip25;

}

// void function which prints the results
void print_tips(double billTip)
{

	cout << "The bill + tip amount is $" << billTip << endl;

}




