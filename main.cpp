#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void getHighScore(string &name, int &score)
{
    ifstream file("scores.txt");

    string highestName;
    int highestScore=0;
    string na;
    int scc;
    while(file>>na>>scc){
        if(scc>highestScore){
            highestScore=scc;
            highestName=na;
        }
    }
    name=highestName;
    score=highestScore;
}

int main()
{
    string name;
    int score;
    getHighScore(name, score);
    cout<<name<<"\n"<<score;

}