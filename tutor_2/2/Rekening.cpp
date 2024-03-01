#include "Rekening.h"

Rekening::Rekening(double saldo) {
    if(saldo < 0) {
        this->saldo = 0;
    } else {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double saldo) {
    this->saldo = saldo;
}

double Rekening::getSaldo() const {
    return saldo;
}

void Rekening::simpanUang(double nominal) {
    if(nominal > 0) {
        saldo += nominal;
    }
}

bool Rekening::tarikUang(double nominal) {
    if(nominal > 0 && saldo - nominal >= 0) {
        saldo -= nominal;
        return true;
    } else {
        return false;
    }
}
