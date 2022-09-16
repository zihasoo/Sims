#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>

using namespace std;

void file_write(const vector<pair<string,unsigned int>>& content){
    ofstream fileout("C:\\Codes\\C++\\SImsCoding\\scores.txt");
    for(const auto& person : content){
        fileout << person.first << '\n';
        fileout << person.second << '\n';
    }
}

auto& random_content_gen(int count){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> length(2,15);
    uniform_int_distribution<int> score(0,1000000);
    uniform_int_distribution<int> alpha(0,25);
    auto &result = *new vector<pair<string, unsigned int>>;
    result.resize(count);
    for (int i = 0; i < count; ++i) {
        int rand_len = length(gen);
        string& name = result[i].first;
        name.resize(rand_len);
        for (int j = 0; j < rand_len; ++j) {
            name[j] = static_cast<char>(alpha(gen)+'a');
        }
        result[i].second = score(gen);
    }
    return result;
}

int main() {
    srand(time(NULL));
    auto &content = random_content_gen(rand()%100+5);
    file_write(content);
    return 0;
}
