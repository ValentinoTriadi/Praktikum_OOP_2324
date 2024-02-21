#include "BigNumber.hpp"
#include <iostream>
using namespace std;

const int BigNumber::max_digit = 20;

BigNumber::BigNumber() {
  this->digit = new int[BigNumber::max_digit];
}

BigNumber::BigNumber(int number) {
  this->digit = new int[BigNumber::max_digit];
  for (int i = 0; i < BigNumber::max_digit; i++) {
    this->digit[i] = number % 10;
    number /= 10;
  }
}

BigNumber::BigNumber(string aVeryBigNumber) {
  this->digit = new int[BigNumber::max_digit];
  int strSize = aVeryBigNumber.size();
  for (int i = 0; i < BigNumber::max_digit ; i++) {
    if (i >= strSize) {
        this->digit[i] = 0;
    } else {
        this->digit[i] = aVeryBigNumber[strSize - 1 - i] - '0';
    }
  }
}

BigNumber::BigNumber(const BigNumber& bn) {
  this->digit = new int[BigNumber::max_digit];
  for (int i = 0; i < BigNumber::max_digit; i++) {
    this->digit[i] = bn[i];
  }
}

int BigNumber::getMaxDigit() {
  return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit) {
  this->digit[i] = digit;
}

int& BigNumber::operator[](int i) {
  return this->digit[i];
}

int BigNumber::operator[](int i) const {
  return this->digit[i];
}

BigNumber::~BigNumber() {
  delete[] this->digit;
}

// hint   : gunakan operator overload [] untuk mengakses digit
// contoh : other[i]
// hint   : untuk this, dapat langsung menggunakan this->digit[i]
bool BigNumber::operator==(const BigNumber& other) {
    for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] != other[i]) return false;
    }
    return true;
}

bool BigNumber::operator<(const BigNumber& other) {
    for(int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] < other[i]) {return true;}
        else if (this->digit[i] > other[i]) {return false;}
    }
    return false;
}

bool BigNumber::operator>(const BigNumber& other) {
    for(int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
        if (this->digit[i] > other[i]) {return true;}
        else if (this->digit[i] < other[i]) {return false;}
    }
    return false;
}

BigNumber BigNumber::operator+(const BigNumber& other) {
  BigNumber c;
  // hint: gunakan operator overload [] untuk mengakses dan mengubah digit
  // contoh:
  // - c[i] = this->digit[i]
  // - c[i] = other[i] 
  int carrier = 0;
  for (int i = 0; i < BigNumber::getMaxDigit(); i++) {
    if (this->digit[i] + other[i] + carrier >= 10) {
      c[i] = (this->digit[i] + other[i] + carrier) % 10;
      carrier = 1;
    } else {
      c[i] = this->digit[i] + other[i] + carrier;
      carrier = 0;
    }
  }
  return c;
}