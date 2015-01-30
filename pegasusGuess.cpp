/*
FILENAME:			pegasusGuess.cpp
AUTHOR:				Eric Scott Phung
CREATED:			2014.01.26 (ESP)
PURPOSE:			c++ Number Guessing Game
					Human user chooses a number;
					Ai will guess the number up to 7 times;
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>


#define TRUE 1
#define FALSE 0
#define MAX 7

using namespace std;


int a, aiGuess, tries = 1;// Declaration of main variables used
char arg[] = {};
char userInput[] = {};
char userChoice[] = {};// user declare ready
int highLimit = 100;
int lowLimit = 1;

void tooLow();
void tooHigh();


void tooLow(){
	tries = (tries+1);
	lowLimit = aiGuess;
	aiGuess = lowLimit + (std::rand() %(highLimit - lowLimit +1));
	do{
		/* first guess partition */
		aiGuess = (lowLimit+highLimit)/2;
	} while (tries < 2);
}


void tooHigh(){
	tries = (tries+1);
	highLimit = aiGuess;
	aiGuess = lowLimit + (std::rand() %(highLimit - lowLimit));
	do{
		/* first guess partition */
		aiGuess = (lowLimit+highLimit)/2;
	} while (tries < 2);
	//printf("\nGuess(%i) = %i\n", tries, b);
}

/*highLimit = b;
tooHigh();*/

/*
lowLimit = b;
			tooLow();
*/







int main(){

	srand(time(NULL));
	/* initialize random values */
	//a = rand() % highLimit + lowLimit;// random coorect number for development
	aiGuess = 50;// initialize first guess as two possible partitions

	cout << "\tHello Guessing Game Version 2.0" << endl;


	/* DEBUG: user input */
	std::string userInput;
	std::string userReady;


	
	std::string strWin ("correct");// str cmd to win
	std::string strQuit ("quit");// str cmd to quit
	std::string strReady ("ready");// for ready
	std::string strHigh ("too high");// for comparison
	//std::string str1 ("too high");
	std::string strLow ("too low");// for compari
	

	/* code for user choice "ready" */
	cout << "Rusty: 	This is a game in which you ,the user, will think of a number from 1 - 100.  I, Rusty, will guess what number you are thinking of in 7 guesses or less.\n\tPlease type ready when you have picked a number" << endl;
	getline(std::cin, userReady);
		


	/* Evaluate user input at every pass 
	thru while loop until 7 tries have passed */
	while(tries <= MAX) {

		if (tries == MAX){
			/* force win */
			cout << "Rusty: 	The number you chose is " << aiGuess << "\nYay!  Cake and punch for everyone!!!\n\tGoodbye!" << endl;
			return 0;
		}// end game if user input = "correct"

		if ((userReady.compare(strReady)==1))
		{
			/* if user is 'ready', then begin the game, else input, then quit */
			break;
		}// begin game if user input = 'ready'
		
		/* main code */

		//cout << "Correct: 	" << a << endl;
		cout << "Guess(" << tries << ") = 	" << aiGuess << endl;
		cout << "Rusty: 	Is this guess too high or too low?\n(type 'too high' or 'too low' or 'correct' or 'quit')" << endl;
        getline(std::cin, userInput);
	
		    /* exit game QUIT */
		if (userInput.compare(strQuit) == 0)
		{
			/* if user enters 'quit', then quit */
			cout << "Rusty: 	Thanks for playing!\n\tGoodbye!" << endl;
			return 0;
		}
		/* exit game WIN */
		if (userInput.compare(strWin) == 0){
			/* if user enters correct, then win */
			cout << "I win!!!" << endl;
			return 0;
		}

		if (userInput.compare(strHigh) == 0){
	    	/* if user typed 'too high' */
	        cout << "You said my answer was too high" << endl;
	        //cout << b << endl;
	        highLimit = aiGuess;
	        tooHigh();

	    }// end if statement for user input = 'too high'
	    else if (userInput.compare(strLow) == 0){
	    	/* if user typed 'too low' */
	        cout << "You said my answer was too low" << endl;
	        lowLimit = aiGuess;
	        tooLow();
	    } // end if statement for user input = 'too low'
	    else {
	    	/* catch all if statement */
	    	cout << "oh no! sumthing broke!\nRusty: 	Let's try this again...type 'too low' if I guessed TOO LOW, 'too high' if I guessed TOO HIGH, and 'quit' if you decide not to play." << endl;
	    } // end if statement for catch-all for user input

	}// end of main while control loop

	return 0;
}