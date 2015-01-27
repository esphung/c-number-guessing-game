#include <iostream>
#include <cstdlib>
#include <regex>
#define TRUE 1
#define FALSE 0
#define MAX 7

using namespace std;

/* c is used for previous answer comparison */
int a, b, tries = 1;// Declaration of main variables used
int previousGuesses[] = {};// empty list to store used values
char arg[] = {};
int highLimit = 100;
int lowLimit = 1;

void tooLow();
void tooHigh();


void tooLow(){
	tries = (tries+1);
	printf("Tries: %i\n", tries);
	int lowLimit = b;
	//printf("new lowLimit: %i\n", lowLimit);
	b = lowLimit + (std::rand() %(highLimit - lowLimit +1));
	do{
		/* first guess partition */
		b = (lowLimit+highLimit)/2;
	} while (tries < 2);
	//printf("New guess if b was too low = %i\n", b);
	printf("\nGuess(%i) = %i\n", tries, b);
}


void tooHigh(){
	tries = (tries+1);
	printf("Tries: %i\n", tries);
	highLimit = b;
	//printf("new highLimit %i\n", highLimit);	
	b = lowLimit + (std::rand() %(highLimit - lowLimit));
	do{
		/* first guess partition */
		b = (lowLimit+highLimit)/2;
	} while (tries < 2);
	printf("\nGuess(%i) = %i\n", tries, b);
}


void guessCompare(){
	if (a == b)
	{
		/* code */
		cout << "==== I win! ====" << endl;
		exit(1);
	}
	cout << "Is my previous guess too high or too low?\n" << endl;
	cin >> arg;
	/* Match argument to 'too high' or 'too low' */
	regex highPattern("(.*)high?.*|.*high?.*", regex_constants::icase);//Match "high"
	bool highMatched = regex_match(arg, highPattern);
	cout << (highMatched? "High Matched" : "High Not Matched") << endl;
	
	if (highMatched == TRUE){
		//printf("Too high = True\n");
		highLimit = b;
		tooHigh();
	}
	else if (highMatched == FALSE)
	{
		/* possiblle if guess was not too high */
		regex lowPattern("(.*)low?.*|.*low?.*", regex_constants::icase);//Match "low"
		bool lowMatched = regex_match(arg, lowPattern);
		cout << (lowMatched? "Low Matched" : "Low Not Matched") << endl;
		if (lowMatched == TRUE)
		{
			/* if guess was too low */
			//printf("Too low = True\n");
			lowLimit = b;
			tooLow();
		}
		else if (lowMatched != TRUE)
		{
			/* if guess is correct */
			printf("lol let us be confused together!\n");
			return;
		}	
	}
	else {
		cout << "Oops! Something isn't right with the my initial guess";
		return;
	}

}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	/* initialize random values */
	a = rand() % highLimit + lowLimit;// random coorect number for development
	b = 50;// initialize first guess as two possible partitions

	printf("Correct = %i\n", a);// SHow correct number for dev
	printf("\nGuess(%i) = %i\n", tries, b);// show initial stats

	/* main loop passes thru 7 times but says eight to make up for humans */
	while(tries <= 8) {
	    /* code */
	    guessCompare();
	    printf("correct: %i\nhighLimit: %i\nlowLimit: %i\n", a, highLimit, lowLimit);// show cpu guessing range for dev

	}
	


	printf("\n");
	return 0;
}