#include <iostream>
#include <cstdlib>
#include <regex>
#define TRUE 1
#define FALSE 0
#define MAX 7

using namespace std;

/* c is used for previous answer comparison */
int a, b, c, tries = 1, i;// Declaration of main variables used
int keepGoing = TRUE;// Boolean for control of while main 
int previousGuesses[] = {};// empty list to store used values
char arg[] = {};
int aiGuess;
int highLimit = 100;
int lowLimit = 1;
//int v1 = rand() % 100;         // v1 in the range 0 to 99
//int v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
//int v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

int isCorrect(){
	// DESTROY THIS CODE AND REMAKE AS CASE SWITCH STATEMENT
	/* When tries == 6 or b == a */
	if (b == a)
	{
		/* exact guess */
		printf("%i is exactly right.\n", b);
		printf("\n        I WIN!!!");
		keepGoing = FALSE;
		return keepGoing;
	}
	else if (b+1 == a or b-1 == a)
	{
		/* approximate guess */
		printf("\n\tI WIN!!!  \n I guessed %i, but it is close to the correct number >>> %i", b, a);
		//printf("Close enough. If this was golf you would put it in the hole.\nThe answer is %i,  par 7, and it took me %i swings to find it.\n", a, tries);
		keepGoing = FALSE;
		return keepGoing;
	}
	else {
		return 0;
	}// end of if statement
	return 0;
	
}



void tooLow(){
	//keepGoing = FALSE;
	//cout << "TOO LOW\n";
	tries = (tries+1);
	printf("Tries: %i\n", tries);
	//printf("Tries: %i\n", tries);
	int lowLimit = b;
	printf("new lowLimit: %i\n", lowLimit);
	//printf("highLimit: %i\n", highLimit);
	//b = rand() % highLimit + *lowLimit;
	//b = (lowLimit + (rand() %(highLimit - (lowLimit +1))));
	b = lowLimit + (std::rand() %(highLimit - lowLimit +1));



	printf("New guess if b was too low = %i\n", b);




}

void tooHigh(){
	tries = (tries+1);
	printf("Tries: %i\n", tries);

	int highLimit = b;
	printf("new highLimit %i\n", highLimit);
	//aiGuess = rand() % highLimit + lowLimit;

	//b = (rand() % (*highLimit + lowLimit));
	b = lowLimit + (std::rand() %(highLimit - lowLimit -1));

	//b = rand() % a + b/2;
	//if (b > previousGuesses[0])
	//{
	//	srand (time(NULL));
	//	b = rand() % a + b/2;
	//}
	
	printf("\nGuess(%i) = %i\n", tries, b);
	//a = a*2;
	

}


void guessCompare(){
	cout << "Is my previous guess too high or too low?\n" << endl;
	cin >> arg;

	/* Match argument to 'too high' or 'too low' */
	regex highPattern("(.*)high?.*|.*high?.*", regex_constants::icase);//Match "high"
	bool highMatched = regex_match(arg, highPattern);
	cout << (highMatched? "High Matched" : "High Not Matched") << endl;
	
	if (highMatched == TRUE){
		printf("Too high = True\n");
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
			printf("Too low = True\n");
			lowLimit = b;
			tooLow();
		}
		else if (lowMatched != TRUE)
		{
			/* if guess is correct */
			printf("Hello Correct ANSWER!\n");
			return;
		}
		
	}
	else {
		cout << "Oops! Something isn't right with the my initial guess";
		return;
	}

/*
	switch ( arg ) {
	case this-value:
	  Code to execute if <variable> == this-value
	  break;
	case that-value:
	  Code to execute if <variable> == that-value
	  break;
	...
	default:
	  Code to execute if <variable> does not equal the value following any of the cases
	  break;
}
*/
	
	/*
	if (b < a) {
		tooLow();
	}
	else if (b > a) {
		tooHigh();
	}
	else {
		cout << "Oops! Something isn't right with the my initial guess";
	}
	*/

}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	/* initialize random values */
	a = rand() % highLimit + lowLimit;
	//b = rand() % highLimit + lowLimit;
	b = 50;
	cout << b << endl;
	//aiGuess = b;
	//cout << aiGuess << endl;
	//printf("%i\n", aiGuess);
	printf("Correct = %i\n", a);
	printf("\nGuess(%i) = %i\n", tries, b);

	/* main loop OR return from tooHigh() */
	while(tries <= 7) {
	    /* code */
	    guessCompare();
	    printf(">>>correct: %i\nhighLimit: %i\nlowLimit: %i\n", a, highLimit, lowLimit);

	}
	



	/*
	while(keepGoing == TRUE) {
		
		printf("\n");// for human
		guessCompare();
		isCorrect();
		keepGoing = FALSE;
	}
	*/
	keepGoing = FALSE;




	



	printf("\n");
	return 0;
}