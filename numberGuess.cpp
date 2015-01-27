#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

//number guessing program.
//computer generates a random number
//user guesses a number
//computer responds with "high, low, or correct"
//continue until user has guessed the number

int main(){
    srand(time(NULL));
    int correct = rand() % 100;
    int guess;
    bool keepgoing = true;
    int turn = 0;
    cout << "correct: " << correct << endl;
    while(keepgoing){
        turn++;
        cout << turn << ": please enter a number: ";
        cin >> guess;

        if (guess < correct){
            cout << "Too Low" << endl;
        } else if (guess > correct){
            cout << "Too High" << endl;
        } else {
            cout << "Correct!" << endl;
            keepgoing = false;
        } // end if
    } // end while
    cout << "It took " << turn << " turns." << endl;
} // end main


