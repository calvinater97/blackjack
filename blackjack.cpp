#include<iostream>
using namespace std;


void gamePlay(){
    cout << "Welcome to Blackjack!!" << endl;
    cout << "Are you ready to play? (Yes, No)" << endl;
}

int main() {
    string ready;
    gamePlay();
    cin >> ready;

    if (ready == "Yes"){
        srand((unsigned) time(0));
        int randomNumber = (rand() % 13) + 1;
        cout << randomNumber << endl;
        cout << randomNumber + randomNumber << endl;
    } else {
        cout << "Maybe next time!" << endl;
    }


    return 0;
}