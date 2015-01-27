#include <iostream>
#include <cstdlib>
#define TRUE 1
#define FALSE 0
#define MAX 7

using namespace std;
/* c is used for previous answer comparison */
int a, b, c, tries = 1, i;// Declaration of main variables used
int keepGoing = TRUE;// Boolean for control of while main 
int previousGuesses[] = {};// empty list to store used values for comparison

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
	cout << "TOO LOW\n";
	srand (time(NULL));
	tries++;
	a = a/2;
	previousGuesses[0] = b;
	b = rand() % a + b;	
	if (b < previousGuesses[0])
	{
		srand (time(NULL));
		b = rand() % a + b;
	}
	
	printf("\nGuess(%i) = %i\n", tries, b);
	a = a*2;
	

}

void tooHigh(){
	cout << "TOO HIGH\n";
	srand (time(NULL));
	tries++;
	previousGuesses[0]= b;
	a = a/2;
	b = rand() % a + b/2;
	if (b > previousGuesses[0])
	{
		srand (time(NULL));
		b = rand() % a + b/2;
	}
	

	printf("\nGuess(%i) = %i\n", tries, b);
	a = a*2;
	

}

void guessCompare(){
	if (b < a) {
		tooLow();
	}
	else if (b > a) {
		tooHigh();
	}
	else {
		cout << "Oops! Something isn't right with the my initial guess";
	}

}


int main(int argc, char const *argv[])
{
	srand (time(NULL));
	/* initialize random values */
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;

	printf("Correct = %i\n", a);
	printf("\nGuess(%i) = %i\n", tries, b);

	/* main loop */
	while(keepGoing == TRUE) {
		
		printf("\n");// for human
		guessCompare();
		isCorrect();
		keepGoing = FALSE;
	}
	keepGoing = FALSE;




	



	printf("\n");
	return 0;
}