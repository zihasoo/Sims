#include "loaded_dice.h"

LoadedDice::LoadedDice(int numSides) : Dice(numSides) {}

int LoadedDice::rollDice() const {
    std::cout << "yay!\n";
    int mode = rand()%2;
    if(mode == 0){
        return numSides;
    }
    else{
        return Dice::rollDice();
    }
}