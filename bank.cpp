// bank.cpp | a program that enables to create two types of bank account
// Taras Yakovchuk-Besarab, April 30 2016
// CISP 360
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>


// bonus
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;


// template for conversion from string type to any other type
template <typename T>
T string_to_T(const string &parameter)
{
	istringstream thestr(parameter);
	T t;
	thestr >> t;
	return t;
}


// regular accout structure
struct regular {
	string name;
	int number;
	float balance;
		

} first;

// plus account structure
struct plus {
	string name;
	int number;
	float balance;
	int overdraftLimit;
	float interestRate;
	int amountOfLoans;
		

} second;


//welcome message
void welcome();

// void list of actions
void list();

// function prototype for operations on the account

// creating an account
// get name of the account holder
string getName();

// assign account number
//int accountNum(int);
//int num = 0;
int accountNumber(int &num)
{

	num = num + 1;
	return num;

}

// deposit money on the account 
string deposit();

// withdraw money from the account 
string withdraw();

// interest rate
string getRate();



// print account info
void info(string name, int number, float balance);
void infoPlus(string name, int number, float balance, int limit, float rate, int loans);

int main()
{
	
	welcome();

	// account num counter
	int counterRegular = 0;
	int counterPlus = 0;
	string amount;
	string withdrawAmount;
	float withdrawed;

	
	// BONUS menu for actions
	
	int answer;

	list();

	cin >> answer;
	switch (answer)
		{
			case 0:
				cout << "We appreciate your business!";
				break;
			// regular account			
			case 1:
				first.name = getName();
				first.number = accountNumber(counterRegular);
				
				amount = deposit();
				
				//first.balance = atof(amount.c_str());
				first.balance = string_to_T<float>(amount);				

				// will not withdraw money if the entered amount is larger than the balance
			
				withdrawAmount = withdraw();
				withdrawed = atof(withdrawAmount.c_str());
				
				
				while (withdrawed > first.balance)
				{				
				
				cout << "Such sum is not available in your account!";
				cout << endl;				
				withdrawAmount = withdraw();
				
				withdrawed = atof(withdrawAmount.c_str());
		
				}
				
				first.balance = first.balance - withdrawed;							
				
				// print account info
				// bonus clear the screen before printing info
				system("clear");
				info(first.name, first.number, first.balance);
	
				break;
			// plus account
			case 2:
				cout << "Plus account provides an overdraft protection with $500 upper limit.";
				cout << endl;				
				second.overdraftLimit = 500;
				second.amountOfLoans = 0;
				second.name = getName();
				second.number = accountNumber(counterPlus);
				amount = deposit();
				second.balance = string_to_T<float>(amount);
		
				second.interestRate = string_to_T<float>(getRate());

				withdrawAmount = withdraw();
				withdrawed = string_to_T<float>(withdrawAmount);

				while (withdrawed > (second.balance+second.overdraftLimit))
				{				
				
				cout << "Such sum prevails your balance and overdraft limit!";
				cout << endl;				
				withdrawAmount = withdraw();
				
				withdrawed = string_to_T<float>(withdrawAmount);
		
				}
									
				
				// calc the balance
				second.balance = second.balance - withdrawed;
				
				// check if there is goiing to be a loans
				if (second.balance < 0)
				{
					second.amountOfLoans++;
				}
				
				// bonus clear the screen before printing info
				system("clear");
				infoPlus(second.name, second.number, second.balance, second.overdraftLimit, second.interestRate, second.amountOfLoans);
			
				break;
			default:
				cout << "We appreciate your business!";
				break;

		}
	// menu ended
		



	cout << endl;
	return 0;

}



// welcome message

void welcome()
{
	cout << "Welcome to Pangloss Bank!";
}

// menu func

void list()
{
	cout << endl;	
	cout << "0. Exit";
	cout << endl;
	cout << "1. Create regular account";
	cout << endl;
	cout << "2. Create plus account";
	cout << endl;
			
	cout << "Please, choose your action from a list: ";
}

// get name
string getName()
{
	string name;
	cout << "Please, enter your name: ";
	cin >> name;
	return name;

}



// deposit money
string deposit()
{
	string amount;
	cout << "Please, enter the sum you want to deposit: $";
	cin >> amount;
	return amount;

}

// withdraw money
string withdraw()
{
	string amount;
	cout << "Please, enter the sum you want to withdraw from your account: $";
	cin >> amount;
	return amount;

}


// interest rate
string getRate()
{
	string rate;
	cout << "Please, enter your interest rate: ";
	cin >> rate;
	return rate;


}

// printing info for regular account

void info(string name, int number, float balance)
{
	cout << endl;	
	cout << "Account Information";
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Account Number: " << number << endl;
	cout << "Current Balance: $" << balance << endl;

}

// printing info for plus account 
void infoPlus(string name, int number, float balance, int limit, float rate, int loans)
{
	cout << endl;	
	cout << "Account Information";
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Account Number: " << number << endl;
	cout << "Current Balance: $" << balance << endl;
	cout << "Overdraft Limit: $" << limit << endl;	
	cout << "Interest Rate: %" << rate << endl;
	cout << "Number of loans: " << loans << endl;
	


}
