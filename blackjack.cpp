#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Generates a random number to be used as card value.
int ranNum(){
    int randomNumber = (rand() % 10) + 1;
    return randomNumber;
}

//Will determine what the dealer will have as their card value.
int compNum(){
    int compFirstCard = ranNum();
    int compSecondCard = ranNum();
    int compTotal = 0;

    if (compFirstCard == 1) {
        compTotal = compFirstCard + compSecondCard;
        if (compTotal + 10 <= 21) {
            compFirstCard = 11;
        }
    }
    if (compSecondCard == 1) {
        compTotal = compFirstCard + compSecondCard;
        if (compTotal + 10 <= 21) {
            compSecondCard = 11;
        }
    }

    int compNewCard = ranNum();
    for (compTotal = compFirstCard + compSecondCard; compTotal < 17; compTotal += compNewCard) {
        if (compNewCard == 1) {
            if (compTotal + 10 <= 21) {
                compNewCard = 11;
            }
        }
        compNewCard = ranNum();
    }
    
    return compTotal;
}

//Will determine what the player will have as their card value.
int playerNum() {
    int playerFirstCard = ranNum();
    int playerSecondCard = ranNum();
    string playerChoice;
    string hit;
    int playerTotal;

    cout << "Your first card number is: " << playerFirstCard << endl;
    cout << "Your Second card number is: " << playerSecondCard << endl;

    if (playerFirstCard == 1) {
        cout << "Would you like your first card to be 11? (Y=Yes, N=No) ";
        cin >> playerChoice;
        if (playerChoice == "Y") {
            playerFirstCard = 11;
            cout << "Your first card is now 11" << endl;
        } 
    }
    if (playerSecondCard == 1) {
        cout << "Would you like your second card to be 11? (Y=Yes, N=No) ";
        cin >> playerChoice;
        if (playerChoice == "Y") {
            playerSecondCard = 11;
            cout << "Your Second card is now 11" << endl;
        } 
    }
    playerTotal = playerFirstCard + playerSecondCard;
    cout << "Your total is " << playerTotal << endl;
    cout << "Would you like to hit? (Y=Yes, N=No) ";
    cin >> hit;
    int playerNewCard = ranNum();
    while(hit == "Y") {
        cout << "Your added card is " << playerNewCard << endl;
        if (playerNewCard == 1) {
        cout << "Would you like your new card to be 11? (Y=Yes, N=No) ";
        cin >> playerChoice;
            if (playerChoice == "Y") {
                playerNewCard = 11;
                cout << "Your new card is now 11" << endl;
            }
        }
        playerTotal += playerNewCard;
        playerNewCard = ranNum();
        cout << "Your new total is " << playerTotal << endl;
        if (playerTotal <= 21) {
            cout << "Would you like to hit? (Y=Yes, N=No) ";
            cin >> hit;
        } else {
            break;
        }
    }
    return playerTotal;
    
}

//Makes a decision for who will win the game.
void determineWinner() {
    int player = playerNum();
    int dealer = compNum();
    string deal = "The dealer got " + to_string(dealer);

    if (player > 21) {
        cout << "Your cards are a bust" << endl;
        cout << "Your a loser" << endl;
    }
    else if (dealer > 21) {
        cout << "The dealer busted with " << dealer << endl;
        cout << "You WIN!!" << endl;
    }
    else if (player > dealer) {
        cout << deal << endl;
        cout << "You WIN!!" << endl;
    } 
    else if (player == dealer){
        cout << "Its a draw, play again" << endl;
    } else {
        cout << deal << endl;
        cout << "Your a loser" << endl;
    }
}

int main() {
    srand(time(0));

    determineWinner();

    return 0;
}