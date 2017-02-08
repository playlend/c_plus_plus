// complex.cpp | a program that adds and substracts two complex numbers
// Taras Yakovchuk-Besarab, April 9 2016
// CISP 360
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// void function that welcomes the user
void Greeting();

// BONUS void instrutions
void Instructions();

// get complex numbers
double GetRealPart(string);
double GetImaginaryPart(string);

// addition of two complex numbers
double AdditionReal(double,double);
double AdditionImaginary(double,double);

// subst of two complex numbers
double SubsReal(double,double);
double SubsImaginary(double, double);

// displaying results
void Results(double, double);

int main()
{
    Greeting();
 Instructions();
    string first = "first";
    string second = "second";
    //  complex numbers
    int arraySize = 2;
    double firstNum[arraySize];
    double secondNum[arraySize];
   
    // complex numbers
    firstNum[0] = GetRealPart(first);
   
    firstNum[1] = GetImaginaryPart(first);

    secondNum[0] = GetRealPart(second);
   
    secondNum[1] = GetImaginaryPart(second);
   
	
	   

	// addition
	//real
	double realResult;
	realResult = AdditionReal(firstNum[0], secondNum[0]);			
	//imaginary	
	double imaginaryResult;
	imaginaryResult = AdditionImaginary(firstNum[1], secondNum[1]);
	
	//subs
	//real
	double realSubsResult = SubsReal(firstNum[0], secondNum[0]);

	//imaginary
	double imaginarySubsResult = SubsImaginary(firstNum[1], secondNum[1]);
	
// Bonus clear the screen
system("clear");

	// BONUS displaying results
	
	//addition
	cout << "Addition Result" << endl;
	cout << "(";
	Results(firstNum[0],firstNum[1]);
	cout << ") + (";	
	Results(secondNum[0],secondNum[1]);
	cout << ") = ";
	Results(realResult, imaginaryResult);
	cout << endl;
	
	//substraction
	cout << "Substraction Result" << endl;
	cout << "(";
	Results(firstNum[0],firstNum[1]);
	cout << ") - (";	
	Results(secondNum[0],secondNum[1]);
	cout << ") = ";
	Results(realSubsResult, imaginarySubsResult);
	cout << endl;

    return 0;
}

// void Greeting func
void Greeting()
{

    cout << "Welcome to the program that adds and substracts complex numbers!" << "\n";

}

//BONUS instructions
void Instructions()
{
	cout << "You will be prompted for two parts of two complex numbers - real part and imaginary part. After you entered your numbers, the program is going to calculate and display results. Thank you!";
	cout << endl;
}

// get numbers
double GetRealPart(string num)
{
    double number1;
    cout << "Please, enter the real part of the " << num << " complex number: ";
    cin >> number1;
   
    return number1;
}

double GetImaginaryPart(string num)
{
    double number2;
    cout << "Please, enter the imaginary part of the " << num << " complex number: ";
    cin >> number2;
   
    return number2;
}

// addition of two complex numbers

double AdditionReal(double realFirst, double realSecond)
{
    double additionRealResult;
	
   additionRealResult = realFirst + realSecond;

    return additionRealResult;
}

double AdditionImaginary(double imaginaryFirst, double imaginarySecond)
{
    double additionImaginaryResult;
	

   additionImaginaryResult = imaginaryFirst + imaginarySecond;

    return additionImaginaryResult;
}

// subs of complex numbers
double SubsReal(double realFirst, double realSecond)
{
    double additionRealResult;
	
   additionRealResult = realFirst - realSecond;

    return additionRealResult;
}

double SubsImaginary(double imaginaryFirst, double imaginarySecond)
{
    double additionImaginaryResult;
	

   additionImaginaryResult = imaginaryFirst - imaginarySecond;

    return additionImaginaryResult;
}

// BONUS displaying results
void Results (double real, double imaginary)
{
	
	cout << real << " + " << imaginary << "i";
}	



