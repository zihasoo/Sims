#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

void print_movie(const map<string, pair<int, int>> &m) {
    for (const auto &iter: m) {
        cout << iter.first << ": " << iter.second.second << " reviewers. Average of "
             << (double) iter.second.first / iter.second.second << "/5\n";
    }
}

int main() {
    ifstream data("data.txt");

    map<string, pair<int, int>> m;//이름 <점수총합, 개수>
    pair<string, int> movie;
    while (data >> movie.first >> movie.second) {
        if (m.find(movie.first) != m.end()) {//이미 있다면
            m[movie.first].first += movie.second; //점수더하기
            m[movie.first].second++;
        } else {//새로운영화면
            m[movie.first] = make_pair(movie.second, 1);
        }
    }
    print_movie(m);

}