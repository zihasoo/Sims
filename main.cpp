#include "loaded_dice.h"

using namespace std;

int rollTwoDice(const Dice* die1, const Dice* die2)
{
    return die1->rollDice() + die2->rollDice();
}

int main(){
    Dice* dice1 = new Dice(10);
    Dice* dice2 = new Dice(20);
    for (int i = 0; i < 10; ++i) {
        cout << rollTwoDice(dice1,dice2) << '\n';
    }
    delete dice1;
    delete dice2;
    cout << "Loaded Dice" << '\n';

    dice1 = new LoadedDice(10);
    dice2 = new LoadedDice(20);
    for (int i = 0; i < 10; ++i) {
        cout << rollTwoDice(dice1,dice2) << '\n';
    }
    delete dice1;
    delete dice2;
}
