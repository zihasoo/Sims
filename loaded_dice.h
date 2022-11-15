#ifndef LOADEDDICE_H
#define LOADEDDICE_H
#include "dice.h"

class LoadedDice : public Dice{
public:
    LoadedDice(int numSides);
    int rollDice() const override;
};


#endif //LOADEDDICE_H
