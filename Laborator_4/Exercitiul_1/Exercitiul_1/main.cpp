#include <iostream>
#include <cstring>
#include "Sort.h"




int main() {
    Sort s1(15, 5, 10); //n min max
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();
    s1.BubbleSort(false);
    s1.Print();

    std::cout << std::endl;
    
    Sort s2({ 10, 2, 3, 4, 5, 6 });
    s2.Print();
    s2.QuickSort(true);
    s2.Print();
    s2.QuickSort(false);
    s2.Print();

    std::cout << std::endl;

    int v[] = { 12, 2, 3, 43, 5, 3 };
    Sort s3(v, 6);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();
    s3.QuickSort(false);
    s3.Print();

    std::cout << std::endl;

    Sort s4(9, 21, 342, 23, 231, 432, 23, 324, 43, 3213);
    s4.Print();
    s4.QuickSort(true);
    s4.Print();
    s4.QuickSort(false);
    s4.Print();

    std::cout << std::endl;

    char st[] = "10,40,100,5,70";
    Sort s5(st); //n min max
    s5.Print();
    s5.InsertSort(true);
    s5.Print();
    s5.InsertSort(false);
    s5.Print();
}
