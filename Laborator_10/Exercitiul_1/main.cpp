#include <iostream>
#include "Array.h"



int main(){
    Array<int> arr(99);
    
    arr += 1;
    arr += 4;
    arr += 3;
    arr.Insert(1, 30);
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> arrc(arr);
    for (int i = 0; i < arrc.GetSize(); i++) {
        std::cout << arrc[i] << " ";
    }
    std::cout << std::endl;


    arr.Insert(1, arrc);
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    arr.Delete(0);
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::boolalpha << (arr = arrc) <<  '\n';
    auto comp = [](const int &a, const int &b)-> int{return a > b; };
    arr.Sort(comp);
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int a = 4;
    std::cout << "Elementul " << a << " gasit la poz " << arr.BinarySearch(a) << "\n";
    
   
}
