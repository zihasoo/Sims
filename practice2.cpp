#include<iostream>

using namespace std;

class HotDogStand{
    int ID;
    unsigned short numSold = 0;
    static unsigned totalSold;
public:
    HotDogStand(): numSold(0){}
    HotDogStand(int standID, unsigned short soldCount) : ID(standID), numSold(soldCount) {
        totalSold += numSold;
    }
    int getID(){return ID;}
    void setID(int newID){ID = newID;}
    void justSold(){
        numSold++;
        totalSold++;
    }
    unsigned short getNumSold(){
        return numSold;
    }
    static unsigned getTotalSold(){
        return totalSold;
    }
};

unsigned HotDogStand::totalSold = 0;

int main() {
    HotDogStand std1(1,3);
    HotDogStand std2(2,10);
    HotDogStand std3(3,5);
    std1.justSold();
    std3.justSold();

    cout << "id: " << std1.getID() << ", sold: " << std1.getNumSold() << '\n';
    cout << "id: " << std2.getID() << ", sold: " << std2.getNumSold() << '\n';
    cout << "id: " << std3.getID() << ", sold: " << std3.getNumSold() << '\n';

    cout << "total: " << HotDogStand::getTotalSold();

    return 0;
}