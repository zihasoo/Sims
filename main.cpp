#include <fstream>
#include <iostream>

using namespace std;

void find_highest_score(string& best_player, int& best_score) {
    ifstream fin("scores.txt");
    best_score = 0;
    pair<string, int> player;
    while (fin >> player.first >> player.second){
        if(player.second > best_score){
            best_player = player.first;
            best_score = player.second;
        }
    }
}

int main(){
    string player;
    int score;
    find_highest_score(player,score);
    cout << player << ' ' << score;
}
