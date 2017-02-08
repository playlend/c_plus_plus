#include <iostream> //Necessary for standard console input/output
#include <cstdlib> //Allows use of rand/srand functions
#include <ctime> //Allows use of system time to modify srand function
using namespace std;
//Function in use for dice rolls, including a time delay and random number generation.
int rollDie() {
	int val = rand() % 6;
	return val + 1;
	
}
	/*This function will print the final scores and present the choice to continue or exit
	at the end of the game.*/
int endGame(int uScore, int cScore) {
	char reply;
	cout << "Game over!" << endl;
	cout << "Your score: " << uScore << "." << endl;
	cout << "Computer score: " << cScore << "." << endl;
	cout << "Play again? Y/N: ";
	cin >> reply;
	if (reply == 'Y') {
		return 1;
	}else if (reply == 'y'){
		return 1;
	}else {
		return 0;
	}
}

int playerTurn() {
	int turnScore = 0;
	char response = 'R';
	bool rolling = true;
    /*After declaring relevant variables, the 'rolling' loop begins. Similar to the player phase
	in the main function, the rolled variable is determined by the rollDie function farther above.*/
	while (rolling) {
		int rolled = rollDie();
		if (rolled == 1) {
			turnScore = 0;
			rolled = 0;
			cout << "You rolled a one! No points this turn." << endl;
			rolling = false;
		}
		turnScore = turnScore + rolled;	
/*This if statement will make sure that there actually was a score to continue from before printing
it and the query as to whether the player would like to continue or not. Otherwise, it'll print rather
redundantly.*/
		if (turnScore != 0) {
			cout << "You rolled a " << rolled << ". Your score this turn is " << turnScore << "." << endl;
			cout << "Would you like to (R)oll again or (H)old?" << endl;
			cin >> response;
			switch (response) {
				case 'H':
					rolling = false;
				case 'h':
					rolling = false;
			}
		}
	}
	return turnScore;
}
int compTurn() {
	/*This function behaves in much the same way as playerTurn, of course lacking the "roll" or "hold"
	feedback.*/
	int cTurnScore = 0;
	bool cRolling = true;
	while (cRolling) {
		int cRolled = rollDie();
		if (cRolled == 1){
			cTurnScore = 0;
			cRolled = 0;
			cout << "Computer rolled a one! No points this turn." << endl;
			cRolling = false;
		}
		cTurnScore = cTurnScore + cRolled;
	/*As in playerTurn, this if statement is intended to avoid redundant console output if the score
	is zero.*/
		if (cTurnScore != 0){
		cout << "Computer rolled a " << cRolled << ". Its score this turn is " << cTurnScore << "." << endl;
	/*As aforementioned, no "roll or hold" feedback. In the background, it checks to see if the current
	turn score is at or above 20 and ends the loop if that condition is satisified.*/
		}if (cTurnScore >= 20) {
			cRolling = false;
		}
	}
	return cTurnScore;
}

int main( ) {
	//Declaring major game-tracking variables here.
	srand(time(0));
	int playerScore = 0;
	int compScore = 0;
	bool playing = true;
	
	while (playing) {
		//Player phase, initializing the turnscore variable to be modified by the playerTurn function.
		cout << "Your turn." << endl;
		int turnScore = playerTurn();
		playerScore = playerScore + turnScore;
		cout << "Your score so far is " << playerScore << "." << endl;
		//Checking to see if cumulative score counts for a win, in which case the loop is stopped.
		if (playerScore >= 100) {
			cout << "You WIN." << endl;
			playing = false;
		}
		
		//Computer phase, same organization as the player phase.
		cout << "Computer's turn." << endl;
		int cTurnScore = compTurn();
		compScore = cTurnScore + compScore;
		cout << "Computer's score so far is " << compScore << "." << endl;
		if (compScore >= 100) {
			cout << "The computer wins! You LOSE." << endl;
			playing = false;
		}
	}
    /*When the "playing" loop is exited as the result of the user or computer winning, the
	endGame function is called with the score parameters passed to be displayed by that function. 
	The function then returns user input into variable x as to restart the game or close the program.*/
	int x = endGame(playerScore, compScore);
		if (x == 1) {
			main();
		}else {
			return 0;
		}
	return 0;
}
