#include "Penganan.hpp"
#include <iostream>
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan(){
    keik = 0;
    panekuk = 0;
}

Penganan::Penganan(int keik, int panekuk){
    this->keik = keik;
    this->panekuk = panekuk;
}

int Penganan::GetKeik() const {
    return this->keik;
}

int Penganan::GetPanekuk() const {
    return this->panekuk;
}

void Penganan::SetKeik(int k){
    this->keik = k;
}

void Penganan::SetPanekuk(int p){
    this->panekuk = p;
}

Penganan operator+ (const Penganan&a, const Penganan&b){
    int temp_keik = a.GetKeik() + b.GetKeik();
    int temp_Panekuk = a.GetPanekuk() + b.GetPanekuk();
    Penganan temp(temp_keik,temp_Panekuk);
    Penganan::n_rumah++;
    return temp;
}


Penganan operator- (const Penganan&a, const Penganan&b){
    int temp_beli_keik = (a.GetKeik() - b.GetKeik()) > 0 ? b.GetKeik() : a.GetKeik();
    int temp_beli_Panekuk = (a.GetPanekuk() - b.GetPanekuk()) > 0 ? b.GetPanekuk() : a.GetPanekuk();
    Penganan::uang += temp_beli_keik*51 + temp_beli_Panekuk*37;
    Penganan temp(a.GetKeik()-temp_beli_keik, a.GetPanekuk()-temp_beli_Panekuk);
    return temp;
}

Penganan operator^ (const Penganan&a, const int n){
    int temp_keik = a.GetKeik() - n;
    if (temp_keik < 0) {
        Penganan::uang += temp_keik*51;
        temp_keik = 0;
    }
    int temp_Panekuk = a.GetPanekuk() - n;
    if (temp_Panekuk < 0) {
        Penganan::uang += temp_Panekuk*37;
        temp_Panekuk = 0;
    }
    Penganan temp(temp_keik,temp_Panekuk);
    return temp;
}

Penganan operator^ (const int n, const Penganan&a){
    int temp_keik = a.GetKeik() - n;
    if (temp_keik < 0) {
        Penganan::uang += temp_keik*51;
        temp_keik = 0;
    }
    int temp_Panekuk = a.GetPanekuk() - n;
    if (temp_Panekuk < 0) {
        Penganan::uang += temp_Panekuk*37;
        temp_Panekuk = 0;
    }
    Penganan temp(temp_keik,temp_Panekuk);
    return temp;
}    

int Penganan::JumlahUang(){
    return Penganan::uang; 
}

int Penganan::HitungNRumah(){
    return Penganan::n_rumah;
}

void Penganan::Print(){
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl;
}