#ifndef _A_HPP_
#define _A_HPP_

#include <iostream>
using namespace std;

class A {
    public:
        void getMe() {
            cout << "Brrrrr, my number is " << a << endl;
        }

        void setMe(int x) {
            a = x;
        }

    private:
        int a;
};

#endif