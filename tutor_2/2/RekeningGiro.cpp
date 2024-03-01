#include "Rekening.h"
#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo) {
    if(sukuBunga < 0) {
        this->sukuBunga = 0;
    } else {
        this->sukuBunga = sukuBunga;
    }
}

void RekeningGiro::setSukuBunga(double sukuBunga) {
    this->sukuBunga = sukuBunga;
}

double RekeningGiro::getSukuBunga() const {
    return sukuBunga;
}

double RekeningGiro::hitungBunga() {
    return Rekening::getSaldo() * sukuBunga;
}

