#include "NumberList.h"
#include <iostream>
void NumberList::Init() {
    count = 0;  
}
bool NumberList::Add(int x) {
    if (x >= 10)
        return false;
    numbers[count++] = x;
}
void NumberList::Sort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int aux = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = aux;
            }
        }
    }
}

void NumberList::Print() {
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
