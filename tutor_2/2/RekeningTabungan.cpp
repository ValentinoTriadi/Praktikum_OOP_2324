#include "Rekening.h"
#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo) {
    if(biayaTransaksi < 0) {
        this->biayaTransaksi = 0;
    } else {
        this->biayaTransaksi = biayaTransaksi;
    }
}

void RekeningTabungan::setBiayaTransaksi(double biayaTransaksi) {
    this->biayaTransaksi = biayaTransaksi;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return biayaTransaksi;
}

void RekeningTabungan::simpanUang(double nominal) {
    if(nominal > 0) {
        Rekening::simpanUang(nominal);
        double saldo = Rekening::getSaldo() - biayaTransaksi;
        Rekening::setSaldo(saldo);
    }
}

bool RekeningTabungan::tarikUang(double nominal) {
    if(nominal > 0 && Rekening::tarikUang(nominal)) {
        double saldo = Rekening::getSaldo() - biayaTransaksi;
        Rekening::setSaldo(saldo);
        return true;
    } else {
        return false;
    }
}