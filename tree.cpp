#include <iostream>
#include <string>

using namespace std;

string Answer();
	
int main()
{
	
	string answer;
	string answer1 = "Y";
	string answer2 = "N";
	string answer3 = "Q";

	cout << "Are you airborne?";
	cout << endl;
	answer = Answer();

	if (answer == answer1)
		{
			cout << "Is the electrical system working?";
			answer = Answer();

			// 2
			
				if (answer == answer1)
					{
						cout << "Has the engine stopped running?";
					}
				else if (answer == answer2)
					{
						cout << "Turn on the Master Switch";
					}
				else
					{
						cout << "Good bye!";

					}

				

		}
	else if (answer == answer2)
		{
			cout << "Have a drink and call a mechanic.";
		}
	else 
		{
			cout << "Good bye!";
		}

	cout << endl;
	return 0;
}

string Answer()
{
	string answer;
	cout << endl;	
	cout << "(Please, answer with 'Y' for Yes, 'N' for No(in order to quit, please answer 'Q' anytime)): ";	
	cin >> answer;
	return answer;

}
