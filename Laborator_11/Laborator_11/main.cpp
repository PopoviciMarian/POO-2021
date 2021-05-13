#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MyVector {
public:
    int* arr = new int[100];
    int size = 0;
    int cap = 100;
    bool Add(int x) {
        if (size + 1 >= cap) {
            return false;
        }
        arr[size++] = x;
        return true;
    }
    bool Delete(int index) {
        if (index < 0 || index >= size) {
            return false;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return true;
    }

    void Iterate(void(*func)(int& t)) {
        for (int i = 0; i < size; i++) {
            func(arr[i]);
        }
    }

    void Filter(bool(*func)(int t)) {
        for (int i = 0; i < size; i++) {
            if (func(arr[i])) {
                Delete(i);
            }
        }
    }


    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    vector<string> list;
    list.push_back("ana");
    list.push_back("are");
    list.push_back("mere");
    list.push_back("aa");
    list.push_back("bb");
    list.push_back("aa");

    for (auto w : list) {
        cout << w << " ";
    }
    cout << endl;

    sort(list.begin(), list.end(), [](string& a, string& b) {
        if (a.length() == b.length()) {
            if (strcmp(a.c_str(), b.c_str()) < 0) {
                return true;
            }
        }
        return a.length() < b.length(); });

    for (auto w : list) {
        cout << w << " ";
    }
    cout << endl;


    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(0);
    v.push_back(9);
    v.push_back(1);

    int maxi = *max_element(v.begin(), v.end(), [](int a, int b) {return a < b; });
    cout << maxi << "\n";

    MyVector vec;
    vec.Add(4);
    vec.Add(3);
    vec.Add(1);
    vec.Add(5);
    vec.print();
    vec.Iterate([](int& a) { a = a * 3; });
    vec.print();
    vec.Filter([](int a) { return a % 2 == 0; });
    vec.print();
}

