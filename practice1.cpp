#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void getHighScores(vector<string>& players, vector<int>& scores) {
    ifstream fin("scores.txt");
    pair<string, int> player;
    while (fin >> player.first >> player.second){
        players.push_back(player.first);
        scores.push_back(player.second);
    }
    for (int i = 0; i < scores.size()-1; ++i) {
        int maxidx = i;
        for (int j = i+1; j < scores.size(); ++j) {
            if(scores[j] > scores[maxidx]){
                maxidx = j;
            }
        }
        swap(scores[i],scores[maxidx]);
        swap(players[i],players[maxidx]);
    }
}

int main(){
    vector<string> players;
    vector<int> scores;

    getHighScores(players,scores);
    for (int i = 0; i < 5; ++i) {
        cout << players[i] << ' '  << scores[i] << '\n';
    }
    return 0;
}
