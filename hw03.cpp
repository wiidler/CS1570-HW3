// Programmer: Will Weidler
// Date: 2/14/22
// File: hw03.cpp
// Assignment: HW3
// Purpose: This program expands upon the previous assignment of Wordle by implementing switch-cases and functions.

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void menu();
void newGame();
void newRound();
void printSummary();
void shareResult();

int main(){
    menu();
    return 0;
}

void menu(){
    cout << "The Wordle's Menu" << endl << "------------------" << endl << "1. Start a new game (with new players)" << endl << "2. Start a new round (with existing players)" << endl << "3. Print game summary (of existing players)" << endl << "4. Share result (of last round)" << endl << "5. Exit the game (are you sure?)" << endl << endl << "Please choose an option (1-5): ";
    int option;
    cin >> option;
    cout << endl;
    switch(option){
        case 1:
        {
            newGame();
            break;
        }
        case 2:
        {
            newRound();
            break;
        }
        case 3:
        {
            printSummary();
            break;
        }
        case 4:
        {
            shareResult();
            break;
        }
        case 5:
        {
            cout << "OK, good bye! See you soon, Wordle Wordle!" << endl << "Remember, a real friend is one who always Wordles with you when the rest of the world won't!" << endl;
            break;
        }
    }

}
void newGame(){
    menu();
}
void newRound(){
    menu();
}
void printSummary(){
    menu();
}
void shareResult(){
    menu();
}