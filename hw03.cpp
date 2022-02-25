// Programmer: Will Weidler
// Date: 2/7/22
// File: hw03.cpp
// Assignment: HW3
// Purpose: This file contains a clone of the popular game "Wordle".

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int WORDLENGTH = 5; // sets a constant for the length of each guess

// Description: Greets the user.
// Pre: None
// Post: None
void greet();
// Description: Displays a menu for the user.
// Pre: None
// Post: None
void menu();
// Description: The total game summary that spans multiple rounds is displayed
// Pre: Needs accurate values for below parameters
// Post: A summary is displayed and if friendshipValue < 20, 2 is added to it's value
void printGameSummary(int roundNumber, string playerOneName, string playerTwoName, int & friendshipValue, int initialFV);
// Description: Displays the last round's results in a shareable way.
// Pre: Needs accurate values for below parameters
// Post: A summary is displayed
void shareWordle(string playerOneName, string playerTwoName, string & roundResults, int roundNumber, int attempts);
// Description: Used to find out if each letter in a guess is in a word.
// Pre: Needs the guess and goalword
// Post: Returns a true if the letter is in the word and a false value if not
bool isInWord(const char guess, const string goalWord, const int WORDLENGTH);
// Description: Prints the basic summary at the end of a round
// Pre: Needs accurate values for below parameters
// Post: A summary is displayed
void endRoundSummary(int roundNumber, string playerOneName, string playerTwoName, int & friendshipValue, int attempts, const int victory = 0);



int main(){
    bool returnToMenu = false;
    string option = "-1";    
    string playerOneName = "";
    string playerTwoName = "";
    string roundResults = "";
    int choice = -1;
    int roundNumber = 0;
    int friendshipValue = -1;
    int initialFV = -1;
    int attempts = 1;
    int victory = 0;
	greet();
    while (option != "5"){
        if (returnToMenu == false){
            menu();
            cin >> option;
            if (any_of(option.begin(), option.end(), ::isalpha))
                    {
                        cout << "You must enter a number (1-5)!" << endl << endl;
                    }
                    else if (stoi(option) < 1 || stoi(option) > 5)
                    {
                        cout << "You must enter a number (1-5)!" << endl << endl;
                    }
                    else
                    {
                        choice = stoi(option);
                    }
        }
            switch (choice){
                case 1:{
                    roundNumber = 0;
                    friendshipValue = -1;
                    playerOneName = "";
                    playerTwoName = "";
                    cout << "Player 1, please enter your name: ";

                    cin >> playerOneName;

                    cout << endl << "Welcome, " << playerOneName << "!" << endl;
                    
                    cout << endl << "Now, Player 2, please enter your name: ";

                    cin >> playerTwoName;

                    cout << endl << "Welcome, " << playerTwoName << "!" << endl;
                    while ((friendshipValue >= 0 && friendshipValue <= 100) == false){
                        cout << endl << playerOneName << ", please rate the friendship level you have with " << playerTwoName << "." << endl;
                        cout << "(enter an integer value in [0, 100]): ";

                    
                        string userInput = "";
                        cin >> userInput;
                        if (any_of(userInput.begin(), userInput.end(), ::isalpha))
                        {
                            cout << "HEY!";
                        }
                        else
                        {
                            friendshipValue = stoi(userInput);
                            initialFV = friendshipValue;
                        }
                        
                        cout << endl;

                        if (friendshipValue >= 0 && friendshipValue <= 100){
                            cout << "Hooray, that's an admirable friendship between you two!" << endl << endl;
                        }
                        else{
                            cout << "Can't you read, " << playerOneName << "? The friendship level you input is invalid!" << endl;
                        }
                    }
                    choice = 2;
                    returnToMenu = true;
                    break;
                }
                case 2:{
                    if(playerOneName == "" && friendshipValue == -1)
                    {
                        cout << "USER SELECTION ERROR!"<< endl << "Message: No player data found. Please start a game before starting a new round." << endl << endl;
                    }
                    else
                    {
                        roundResults = "";
                        attempts = 1;
                        roundNumber += 1;
                        cout << "Alright! Round " << roundNumber << " with " << playerOneName << " and " << playerTwoName << "!" << endl << endl;
                        cout << "Let the game begin!" << endl << endl;

                        cout << "Wait... " << playerOneName << ", I need the key word from you (yes, you may whisper into my ears... and remember, it has to be a valid five-letter word, all UPPERCASE!): ";

                        string keyWord = "";

                        while (keyWord.length() != 5 || !all_of(keyWord.begin(), keyWord.end(), ::isalpha) || any_of(keyWord.begin(), keyWord.end(), ::isdigit)){ // If the keyword is not 5 characters long or if there are characters other than letters in the word, this loops until it meets the criteria.
                            cin >> keyWord;
                            cout << endl;
                            if (keyWord.length() < 5 || keyWord.length() > 5){
                                cout << "Seriously, " << playerOneName << "? Your input word is " << keyWord.length() << " letters long! Don't make me quit on you right now..." << endl << endl;
                                cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
                            }
                            else if (!all_of(keyWord.begin(), keyWord.end(), ::isalpha) || any_of(keyWord.begin(), keyWord.end(), ::isdigit)){
                                cout << "Don't make me arrest you, " << playerOneName << "! Your input word is contaminated with non-alphabet characters..." << endl << endl;
                                cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
                            }
                            else{
                                cout << "Got it, " << playerOneName << "! The key word is now securely processed and saved." << endl << endl;
                            }

                        }

                        cout << "Get ready, " << playerTwoName << "! It's now time to Wordle with " << playerOneName << "!" << endl << "You will have a total of 6 attempts to guess the word correctly." << endl << endl;

                        int victory = 0;
                        while (attempts <= 6 && (attempts <= 6 && victory != 1)){ // This is the 6 attempts of the game
                            cout << "This is your attempt #" << attempts << ", " << playerTwoName << ", please enter a valid five-letter word (all UPPERCASE): ";
                            string guessWord;
                            while (guessWord.length() != 5 || any_of(guessWord.begin(), guessWord.end(), ::isdigit)|| !all_of(guessWord.begin(), guessWord.end(), ::isalpha)){ // If the keyword is not 5 characters long or if there are characters other than letters in the word, this loops until it meets the criteria.
                                cin >> guessWord;
                                cout << endl;
                                if (guessWord.length() != 5){
                                    cout << "Seriously, " << playerTwoName << "? Your input word is " << guessWord.length() << " letters long! Don't make me quit on you right now..." << endl << endl;
                                    cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
                                }
                                else if (any_of(guessWord.begin(), guessWord.end(), ::isdigit) || !all_of(guessWord.begin(), guessWord.end(), ::isalpha)){
                                    cout << "Don't make me arrest you, " << playerTwoName << "! Your input word is contaminated with non-alphabet characters..." << endl << endl;
                                    cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
                                }
                                else if (guessWord == keyWord){
                                    cout << "You entered \"" << guessWord << "\". Congratulations, \"" << guessWord << "\" it is!" << endl << endl;
                                    victory = 1;
                                    roundResults += "^o^ ^o^ ^o^ ^o^ ^o^ ";
                                }
                                else{ // Outputs guess and hints if word meets all above criteria, ends game after 6 rounds and gives special failure message
                                    if (attempts == 6){
                                        cout << "You entered \"" << guessWord << "\". Sorry, you lose! The word was \"" << keyWord << "\"." << endl;
                                        attempts += 1;
                                    }
                                    else{
                                        cout << "You entered \"" << guessWord << "\". Nice try, keep going!" << endl;
                                        for(int index=0; index < (int) guessWord.length(); index++)
                                        {
                                            cout << guessWord.at(index) << ":";
                                            if (guessWord.at(index) == keyWord.at(index)){
                                                cout << " ^o^" << endl;
                                                roundResults += "^o^ ";
                                            } 
                                            else if (isInWord(guessWord.at(index), keyWord, keyWord.length())){
                                                cout << " ^-^" << endl;
                                                roundResults += "^_^ ";
                                            }
                                            else if (isInWord(guessWord.at(index), keyWord, keyWord.length()) == false){ 
                                                cout << " @.@" << endl;
                                                roundResults += "@.@ ";
                                            }
                                            
                                        }
                                        roundResults += "\n";
                                        cout << endl;
                                        attempts += 1; // Progresses the round
                                    }
                                }
                            }
                        }
                    endRoundSummary(roundNumber, playerOneName, playerTwoName, friendshipValue, attempts, victory);
                    returnToMenu = false;
                    }
                    break;
                }
                case 3:{
                    if(playerOneName == "" && friendshipValue == -1){
                        cout << "No game data found. Please start a new game." << endl << endl;
                    }
                    else{
                        printGameSummary(roundNumber, playerOneName, playerTwoName, friendshipValue, initialFV);
                    }
                    break;
                }
                case 4:{
                    if(playerOneName == "" && friendshipValue == -1){
                        cout << "No game data found. Please start a new game." << endl << endl;
                    }
                    else{
                        shareWordle(playerOneName, playerTwoName, roundResults, roundNumber, attempts);
                    }
                    break;
                }
            }
    }
    cout << "OK, good bye! See you soon, Wordle Wordle!" << endl << "Remember, a real friend is one who always Wordles with you when the rest of the world won't!" << endl;       
    return 0;    
}
void greet(){
    cout << "Welcome to Wordle For Friends!" << endl << "<=^.^=>"<< endl << endl;
    return;
}
void menu(){
    cout << "The Wordle's Menu" << endl << "------------------" << endl << "1. Start a new game (with new players)" << endl << "2. Start a new round (with existing players)" << endl << "3. Print game summary (of existing players)" << endl << "4. Share result (of last round)" << endl << "5. Exit the game (are you sure?)" << endl << endl << "Please choose an option (1-5): ";
    return;
}
void printGameSummary(int roundNumber, string playerOneName, string playerTwoName, int & friendshipValue, int initialFV){
    if (friendshipValue < 20){
        friendshipValue += 2;
        cout << "Game Summary" << endl;
        cout << "     Player 1: " << playerOneName << endl;
        cout << "     Player 2: " << playerTwoName << endl;
        cout << "     Number of rounds played: " << roundNumber << endl;
        cout << "     Initial friendship level: " << initialFV << endl;
        cout << "     Current frienship level: " << friendshipValue << " (2 bonus levels added)" << endl;
    }
    else{
        cout << "Game Summary" << endl;
        cout << "     Player 1: " << playerOneName << endl;
        cout << "     Player 2: " << playerTwoName << endl;
        cout << "     Number of rounds played: " << roundNumber << endl;
        cout << "     Initial friendship level: " << initialFV << endl;
        cout << "     Current frienship level: " << friendshipValue << endl;
    }
        return;
}
void shareWordle(string playerOneName, string playerTwoName, string & roundResults, int roundNumber, int attempts){
    cout << "\nWordle for Friends (" << playerOneName << " and " << playerTwoName << ")" << endl << endl;
    cout << roundResults << endl << endl;
    cout << "Wordle Round " << roundNumber << " " << (attempts) << "/6" << endl << "This is your Wordle journey for the day to be shared!" << endl << endl;
    return;
}
bool isInWord(const char guess, const string goalWord, const int WORDLENGTH) // Function used to find out if each letter in a guess is in a word
{
    bool returnVal = false;
    for(int i=0; i<=WORDLENGTH; i++)
    {
        if(guess == goalWord[i])
            returnVal = true;
    }
    return returnVal;
}
void endRoundSummary(int roundNumber, string playerOneName, string playerTwoName, int & friendshipValue, int attempts, const int victory){
    int friendshipValueOld;
    cout << "Round " << roundNumber << " Summary" << endl;
    cout << "     Player 1 : " << playerOneName << endl;
    cout << "     Player 2 : " << playerTwoName << endl;
    if (victory == 1){
        if ((friendshipValue + attempts) > 100){
            friendshipValueOld = friendshipValue;
            friendshipValue = 100;
        }
        else{
            friendshipValueOld = friendshipValue;
            friendshipValue += attempts;
        }
        cout << "     Friendship Level: " << (friendshipValueOld) << " -> " << (friendshipValue) << endl << endl;
    }
    else if (victory == 0){
        cout << "     Friendship Level: " << (friendshipValue) << endl << endl;
        }
    return;
}