#pragma once

struct  Nod{
    int info;
    Nod* next = nullptr;
    Nod(int x) {
        info = x;
    }
    Nod(){}
};

class Sort {
    Nod* head;
public:
    Sort(int n, int min, int max) ;
    Sort(std::initializer_list<int> l);
    Sort(int v[], int size);
    Sort(int count, ...);
    Sort(char s[]);
   
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
   
};