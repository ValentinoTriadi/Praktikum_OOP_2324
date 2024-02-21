#include <iostream>
#include "BigNumber.hpp"
using namespace std;

ostream& operator<<(ostream& os, const BigNumber& bn) {
  bool foundNonZero = false;
  for (int i = max_digit - 1; i >= 0; i--) {
    if (bn[i] > 0) {
      foundNonZero = true;
    }
    if (foundNonZero) {
      os << bn[i];
    }
  }
  if (!foundNonZero) {
    os << "0";
  }
  return os;
}

int main() {
  BigNumber a(123), b("2210"), c(a), d("1234"), e("9999"), f(e);
  cout << a << endl; // 123
  cout << b << endl; // 2210
  cout << c << endl; // 123
  cout << d << endl; // 1234
  cout << (a < b) << endl; // 1
  cout << (a > b) << endl; // 0
  cout << (a == b) << endl; // 0
  cout << (a > c) << endl; // 0
  cout << (a < c) << endl; // 0
  cout << (a == c) << endl; // 1
  cout << (a > d) << endl; // 0
  cout << (a < d) << endl; // 1
  cout << (a == d) << endl; // 0
  cout << (b > c) << endl; // 1
  cout << (b < c) << endl; // 0
  cout << (b == c) << endl; // 0
  cout << (b > d) << endl; // 1
  cout << (b < d) << endl; // 0
  cout << (b == d) << endl; // 0
  cout << (c > d) << endl; // 0
  cout << (c < d) << endl; // 1
  cout << (c == d) << endl; // 0
  cout << (a + b) << endl; // 2333
  cout << (a + c) << endl; // 246
  cout << (a + d) << endl; // 1357
  cout << (b + c) << endl; // 2333
  cout << (b + d) << endl; // 3444
  cout << (c + d) << endl; // 1357
  cout << (e + f) << endl; // 19998
  return 0;
}