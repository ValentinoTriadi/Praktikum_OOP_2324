#include "Restaurant.hpp"
#include <iostream>
using namespace std;

int main (){

    Restaurant r;
    r.Push(1);
    r.Push(2);
    r.Push(3);
    r.Push(4);
    r.Push(5);
    r.Push(6);
    r.Push(7);
    r.Push(8);
    r.Push(9);
    r.Push(10);

    cout << r;

    r.Pop(11);
    r.Pop(5);
    cout << r;

    r.AddMenu(3, 5);    
    cout << r;
    r.AddMenu(10, 1);    
    cout << r;

    r.Reorder(3);
    cout << r;

    r.Reorder(10);
    cout << r;

    return 0;
}