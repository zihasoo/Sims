#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Set{
    vector<T> arr;

public:
    void append(T val){
        for(const T& x : arr)
            if(x == val) return;
        arr.push_back(val);
    }

    int size(){
        return arr.size();
    }

    T* getPointer(){
        T* temp = new T[arr.size()];
        copy(arr.begin(),arr.end(),temp);
        return temp;
    }
};

int main(){
    Set<int> intset;
    intset.append(10);
    intset.append(10);
    intset.append(10);
    intset.append(15);
    intset.append(20);
    auto itptr = intset.getPointer();
    for (int i = 0; i < intset.size(); ++i) {
        cout << itptr[i] << ' ';
    }
    cout << '\n';
    delete[] itptr;

    Set<string> strset;
    strset.append("hello");
    strset.append("hello");
    strset.append("hello");
    strset.append("seoul");
    strset.append("tech");
    auto stptr = strset.getPointer();
    for (int i = 0; i < strset.size(); ++i) {
        cout << stptr[i] << ' ';
    }
    cout << '\n';
    delete[] stptr;
}
