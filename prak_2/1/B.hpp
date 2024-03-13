#ifndef _B_HPP_
#define _B_HPP_

#include <iostream>
#include "A.hpp"
using namespace std;

class B: public A {
    public:
        void setMe(int x) {
            b = x;
        }

        void print() {
            getMe();
            cout << "The number above seems strange, but here's my number: " << b << endl;
        }

    private:
        int b;
};

#endif