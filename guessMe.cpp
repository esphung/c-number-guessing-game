#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

//number guessing program.
//computer generates a random number
//user guesses a number
//computer responds with "high, low, or correct"
//continue until user has guessed the numberc




int main(){
    srand(time(NULL));
    int correct = rand() % 100;
    int guess = rand() % 100;
    //bool keepgoing = true;
    int turn = 0;
    //cout << "Correct: " << correct << endl;
    while(turn == 0){ // (keepgoing){
        turn++;
        //cout << turn << ": please enter a number: ";
        printf("Correct: %d\n", correct);
        printf("Guess: %d\n", guess);

        //cin >> guess;

        if (guess < correct){
            cout << "Too Low" << endl;
        } else if (guess > correct){
            cout << "Too High" << endl;
        } else {
            cout << "Correct!" << endl;
            //keepgoing = false;
        } // end if
    } // end while
    cout << "It took " << turn << " turns." << endl;
} // end main


