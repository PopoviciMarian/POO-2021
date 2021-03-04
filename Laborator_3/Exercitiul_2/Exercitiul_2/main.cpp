#include <iostream>
#include "Canvas.h"

using namespace std;

int main(){
    Canvas canvas(51, 21);
    canvas.Clear();
    canvas.SetPoint(34, 5, '3');
    canvas.DrawLine(14, 10, 49, 20, 'a');
    canvas.FillCircle(20, 6, 4, '$');
    canvas.DrawCircle(20, 6, 4 , '@');
    canvas.DrawRect(3, 3, 11, 20, '#');
    canvas.FillRect(4, 4, 10, 19, '.');
    canvas.Print();
}

