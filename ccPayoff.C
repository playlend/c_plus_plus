// ccPayoff | a program created to calculate how long it will take to payoff a credit card
// Taras Yakovchuk-Besarab, 6 February 2016
// CISP 360
#include <iostream>
#include <cstring>
#include <cmath>

//function prototypes

//welcome message
void welcome();



//prompt the current credit card balance
int GetCurrentBalance();

//prompt the APR(Annual Percentage Rate)
int GetAnnualPercentageRate();

//prompt monthly payment
int GetMonthlyPayment();

//transtion of APR
double dailyPR(double);

//main calculation
double amountMonth(int, int, double);

//print results
//void results(int);


//function prototypes


using namespace std;


int main()
{

	welcome();

	int SIZE = 30;
	char name[SIZE];
	cout << "Please, enter your name: ";
	cin >> name;
	
	double dailyPercentageRate = 0;
	int amountOfMonth = 0;



	int currentBalance = GetCurrentBalance();
	double annualPercentageRate = GetAnnualPercentageRate()/100.0;
	int monthlyPayment = GetMonthlyPayment();
	dailyPercentageRate = dailyPR(annualPercentageRate);
	
	amountOfMonth = amountMonth(currentBalance, monthlyPayment, dailyPercentageRate);
	
	//results(amountPerMonth);
	
	cout << "It will take you " << amountOfMonth << " month(s) " << name << " to pay off this card." <<endl;


	
	return 0;

}


//welcome message
void welcome()
{

	cout << "Welcome to the program that helps you to calculate how long it will take to payoff your credit card!" << endl;

}


//getting current balance
int GetCurrentBalance()
{
	int currentBalance = 0;
	cout << "Enter your current credit card balance: ";
	cin >> currentBalance;
	return currentBalance;
	

}

//getting annual percentage rate
int GetAnnualPercentageRate()
{
	int annualPercentageRate = 0;
	cout << "Enter the Annual Percentage Rate (APR) on the card (as a percent): ";
	cin >> annualPercentageRate;
	return annualPercentageRate;


}

//getting monthly payment
int GetMonthlyPayment()
{
	int monthlyPayment = 0;
	cout << "Enter the monthly payment you can make: ";
	cin >> monthlyPayment;
	return monthlyPayment;

}

//transition from annual rate to daily rate
double dailyPR(double annualPercentageRate)
{

	double dailyPercentageRate = annualPercentageRate / 365.0;
	return dailyPercentageRate;

}

//calculation of amount of months
double amountMonth(int currentBalance, int monthlyPayment, double dailyPercentageRate)
{
	double amountMonth = 0.0;

	amountMonth = (-1.0/30.0);
	
	amountMonth = amountMonth * (log(1 + (currentBalance/monthlyPayment) * (1 - pow((1+ dailyPercentageRate), 30)) ));

	amountMonth = (amountMonth / (log(1 + dailyPercentageRate)))+1;

	return amountMonth;


}

/*
void results(int amountMonth)
{

	cout << "It will take you " << amountMonth << " month(s) to pay off this card." <<endl;

}
*/
