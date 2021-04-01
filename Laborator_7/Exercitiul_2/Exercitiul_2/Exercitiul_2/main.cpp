#include <iostream>
#include "Vector.h"

bool compare_descending(const int& x, const int& y) {
    return x < y;
}

bool compare_ascending(const int& x, const int& y) {
    return x > y;
}

bool equal(const int& x, const int& y) {
    return x == y;
}

int main()
{
    Vector<int> v(100);
    v.push(3);
    v.push(5);
    v.push(6);
    v.push(9);
    v.push(3);
    v.push(4);
    v.push(36);
    v.push(145);
    v.print();
    v.pop();
    v.print();
    v.remove(1);
    v.print();
    v.insert(401, 2);
    v.print();
    v.sort(compare_descending);
    v.print();
    v.sort(compare_ascending);
    v.print();
    std::cout << v.count_ele() << std::endl;

    std::cout << v.firstIndexOf(9, equal) << std::endl;
}
