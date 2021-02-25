
#include <iostream>
#include "NumberList.h"
int main(){
    NumberList list;
    list.Init();
    list.Add(3);
    list.Add(1);
    list.Add(5);
    list.Add(8);
    list.Add(0);
    list.Add(6);
    list.Print();
    list.Sort();
    list.Print();

}