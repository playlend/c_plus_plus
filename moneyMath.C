// moneyMath | a program for performing a number of math exercises using money
// Taras Yakovchuk-Besarab, 13 February 2016
// CISP 360

#include <iostream>
#include <cstring>
#include <locale>
#include <iomanip>


using namespace std;

// prototype of welcome message func
void ProgramGreeting();
// prompt user for dollar amounts
double amount(string);
// prompt user for interest rate
int interestRate();
// prompt user for number of years
int numberYears();

// math calculations
double addition(double, double);
double substraction(double, double);
double multiplication(double, double);
double division(double, double);

// calculate interest
double calcInterest(double, double, int, int);
// print interest
void displayInterest(double, double, double);
// print taxes
void displayTaxes(double, double, double, double, double, double);

// dollar to euro conversion
void euro(double,double);

// dollar to uah converstion
void uah (double, double);

const double federalTax = 0.32;
const double caTax = 0.07;
const double alabamaTax = 0.04;
const double alaskaTax = 0.00;

int main()
{
	ProgramGreeting();
	

	string first = "first";
	string second = "second";

	double amount1 = amount(first);
	double amount2 = amount(second);

	int interest = interestRate();
	int years = numberYears();
	
	
	double additionResult = addition(amount1, amount2);
	 double substractionResult = substraction(amount1, amount2);
	 double multiplicationResult = multiplication(amount1, amount2);
	 double divisionResult = division(amount1, amount2);

	double simpleInterest = calcInterest(amount1, amount2, interest, years);
	
	displayInterest(amount1, amount2, simpleInterest);
	
	displayTaxes(amount1, amount2, federalTax, caTax, alabamaTax, alaskaTax);
	
	euro(amount1, amount2);
	cout << endl;	
	uah(amount1, amount2);



	return 0;
}

// welcome message
void ProgramGreeting()
{
	
	cout << "Welcome to the program for performing math exercises using money!";
	cout << endl;
	cout << "Note: when asked to enter dollar amounts, enter them without decimal point (ex. 1000 for 10(ten) dollars).";
	cout << endl;

}

// prompt for dollar amounts
double amount(string number)
{	
	double dollar;	
	cout << "Please, enter the " << number << " dollar amount: ";
	cin >> dollar;
	return dollar;
}

// prompt user for interest rate
int interestRate()
{
	int interest;
	cout << "Please, enter an interest rate: ";
	cin >> interest;	
	return interest;
}

// prompt user for number of years
int numberYears()
{
	int years;
	cout << "Please, enter the number of years to calculate the interest: ";
	cin >> years;
	return years;

}




// displaying math calculations
double addition(double amount1, double amount2)
{
	double result;
	result = 0;	
	cout << endl;
	cout << "Displaying math operations:" << endl;
	// amount1 + amount2
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " + ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;
	cout << " = ";
	result = amount1 + amount2;
	cout << "$ " << setprecision (2) << fixed << result/100 << endl;
	
	result = result/100;
	return result; 

}

double substraction(double amount1, double amount2)
{
	double result;	
	result = 0;
	cout << endl;
	
	// amount1 - amount2
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " - ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;
	cout << " = ";
	result = amount1 - amount2;
	cout << "$ " << setprecision (2) << fixed << result/100 << endl;
	
	result = result/100;
	return result; 

}

double multiplication(double amount1, double amount2)
{
	double result;	
	result = 0;
	cout << endl;
	
	// amount1 x amount2
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " x ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;
	cout << " = ";
	result = amount1 * amount2;
	cout << "$ " << setprecision (2) << fixed << result/10000 << endl;
	
	
	return result; 

}

double division(double amount1, double amount2)
{
	double result;
	result = 0;	
	cout << endl;
	
	// amount1 / amount2
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " / ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;
	cout << " = ";
	result = amount1 / amount2;
	cout << "$ " << setprecision (2) << fixed << result << endl << endl;
	
	
	return result; 

}


// calculate interest
double calcInterest(double amount1, double amount2, int interest, int years)
{
	double result;
	amount1 = amount1 * 0.01;
	amount2 = amount2 * 0.01;
	double principal = amount1 + amount2;
	double interestRate = interest * 0.01;
	
	result = principal * interestRate * years;

	return result;


}

// print interest
void displayInterest(double amount1, double amount2, double interest)
{
	cout << "Displaying Simple Interest on " << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " + ";
	cout << "$ " << setprecision (2) << fixed << amount2/100 << endl;
	cout << "An investment with the parameters specified above will generate, $ " << interest << endl << endl;

}

// print taxes
void displayTaxes(double amount1, double amount2, double federalTax, double caTax, double alabamaTax, double alaskaTax)
{
	
	cout << "Displaying taxes on ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " x ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;
	cout << endl;
	double result;
	double tax1;
	double tax2;
	double alabamaSalesTax;	
	double alaskaSalesTax;
	amount1 = amount1 * 0.01;
	amount2 = amount2 * 0.01;
	result = amount1 * amount2;
	tax1 = result * federalTax;
	tax2 = result * caTax;
	alabamaSalesTax = result * alabamaTax;
	alaskaSalesTax = result * alaskaTax;
	
	cout << "Federal taxes: " << tax1 << endl;
	cout << "California taxes: " << tax2 << endl;
	cout << "Alabama taxes: " << alabamaSalesTax << endl;
	cout << "Alaska taxes: " << alaskaSalesTax << endl << endl;
		
		 
	
}

// dollar to euro conversion
void euro(double amount1, double amount2)
{
	
	double total, result;
	cout << "Dollar to Euro conversion" << endl;
	// addition
	total = (amount1*0.01)+(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " + ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*0.89;
	
	cout << ":  € " << result << endl;

	// subs
	total = (amount1*0.01)-(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " - ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*0.89;
	
	cout << ":  € " << result << endl;

	// mult
	total = (amount1*0.01)*(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " x ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*0.89;
	
	cout << ":  € " << result << endl;

	// div
	total = (amount1*0.01)/(amount2*0.01);
	
	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " / ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*0.89;
	
	cout << ":  € " << result << endl;



}

// dollar to euro conversion
void uah(double amount1, double amount2)
{
	
	double total, result;
	cout << "Dollar to UAH conversion" << endl;
	// addition
	total = (amount1*0.01)+(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " + ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*25.97;
	
	cout << ":  UAH " << result << endl;

	// subs
	total = (amount1*0.01)-(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " - ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*25.97;
	
	cout << ":  UAH " << result << endl;

	// mult
	total = (amount1*0.01)*(amount2*0.01);

	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " x ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*25.97;
	
	cout << ":  UAH " << result << endl;

	// div
	total = (amount1*0.01)/(amount2*0.01);
	
	cout << "Conversion of ";
	cout << "$ " << setprecision (2) << fixed << amount1/100;
	cout << " / ";
	cout << "$ " << setprecision (2) << fixed << amount2/100;

	result = total*25.97;
	
	cout << ":  UAH " << result << endl;



}


