#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// bonus

using std::cout;
using std::cin;
using std::endl;


// end vars

// func prototypes

// random number
int randomNum();
int randomTurn();

int mePlaying();
int rollOrHold();

void gameOn();
void winner(int score, int &playing);

// end func prototypes

int main()
{
	// bonus improved random number
	
	//srand(time(0));
	
	gameOn();
	
	
	



	return 0;
}

// random number
int randomNum()
{

	int number = rand()% 6 + 1;
	return number;

}

int randomTurn()
{
	int number = rand()% 2 + 1;
	return number;

}

int mePlaying()
{
	int playing = 1;
	int thisScore = 0;
	int number = 0;
	int answer;
	
	while (playing == 1)
	{
		number = randomNum();
		
		if (number > 1)
		{
			thisScore = number + thisScore;
			cout << "You got " << number << "Current total for this turn is " << thisScore << "!\n";
			
			answer = rollOrHold();
			if (answer == 0)
			{
				playing = 0;
			}
	
	
		}
		else if (number == 1)
		{
			cout << "You got one for this turn, so no point for you! \n";
			thisScore = 0;
			playing = 0;	
		}

	}

	return thisScore;


}

int rollOrHold()
{
	cout << "Do you want to roll or hold?(1 for roll and 0 for hold): ";
	int answer;
	cin >> answer;
	return answer;
}

void gameOn()
{
	int playing = 1;
	int myTotal = 0;
	int compTotal = 0;	

	while (playing == 1)
	{
		int whoseTurn = randomTurn();
		int thisScore = 0;

		if (whoseTurn == 1)
		{
			cout << "You're rolling first!";
			thisScore = mePlaying();
			myTotal = thisScore +myTotal;
			cout << "Your score is " << myTotal << "!\n";
			winner(myTotal, playing);
			////		

		}		
		else
		{
			cout << "I'm rolling first";

		}
		
		

	}

}

void winner(int score, int &playing)
{

	if (score >= 100)
	{

		cout << "Congratulations, you won!";
		playing = 0;

	}


}

