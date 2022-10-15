#include <iostream>
#include <variant>

using namespace std;

class DynamicStringArray {
private:
    string *dynamicArray;
    int size;

public:
    DynamicStringArray() {
        size = 0;
        dynamicArray = nullptr;
    }
    DynamicStringArray(const DynamicStringArray& copy) {
        size = copy.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = copy.dynamicArray[i];
        }
    }
    ~DynamicStringArray(){
        delete[] dynamicArray;
    }

    DynamicStringArray& operator=(const DynamicStringArray& copy){
        if(&copy != this){
            size = copy.size;
            delete[] dynamicArray;
            dynamicArray = new string[size];
            for (int i = 0; i < size; ++i) {
                dynamicArray[i] = copy.dynamicArray[i];
            }
        }
        return *this;
    }

    int getSize() const noexcept { return size; }

    void addEntry(const string& newString) {
        string* new_dynamic_array = new string[++size];
        int i;
        for (i = 0; i < size - 1; i++) {
            new_dynamic_array[i] = dynamicArray[i];
        }
        new_dynamic_array[i] = newString;
        delete[] dynamicArray;
        dynamicArray = new_dynamic_array;
    }

    string getEntry(int i) {
        if(i < 0 || i > size) return nullptr;
        return dynamicArray[i];
    }

    bool deleteEntry(const string& remove_string) {
        int i;
        bool find = false;
        for (i = 0; i < size; i++) {
            if (remove_string == dynamicArray[i]) {
                find = true;
                break;
            }
        }
        if (find) {
            string *new_dynamic_array = new string[--size];
            int k = 0;
            for (int j = 0; j < size + 1; j++) {
                if (j == i) continue;
                new_dynamic_array[k] = dynamicArray[j];
                k++;
            }
            delete[] dynamicArray;
            dynamicArray = new_dynamic_array;
            return true;
        }
        else return false;
    }
};

int main() {
    DynamicStringArray names;

    // List of names
    names.addEntry("Frank");
    names.addEntry("Wiggum");
    names.addEntry("Nahasapeemapetilon");
    names.addEntry("Quimby");
    names.addEntry("Flanders");

    // Output list
    cout << "List of names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    // Add and remove some names
    names.addEntry("Spuckler");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    names.deleteEntry("Nahasapeemapetilon");
    cout << "After removing a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    names.addEntry("Muntz");
    cout << "After adding another name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    // Remove all of the names by repeatedly deleting the last one
    while (names.getSize() > 0) {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
    }

    cout << "After removing all of the names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    names.addEntry("Burns");
    names.addEntry("Yap");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;


    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);
    // Remove Burns from names
    names.deleteEntry("Burns");
    cout << "Original names: " << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << "Copied names:" << endl;
    for (int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
    cout << endl;

    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2;
    // Remove Burns from names2
    names2.deleteEntry("Burns");
    cout << "Original names: " << endl;
    for (int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
    cout << "Copied names:" << endl;
    for (int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
    cout << endl;

    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;
    return 0;
}
