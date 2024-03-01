#ifndef HEWAN_H
#define HEWAN_H

#include <iostream>
using namespace std;

class Hewan {
    protected:
        string nama;
    public:
        Hewan();
        Hewan(string nama){
            this->nama = nama;
        }
        ~Hewan(){
            cout << "Hewan mati " << nama << endl;
        }
        virtual void print(){
            cout << "Hewan ini namanya " << nama << endl;
        }
};

class Kucing : public Hewan {
    public:
        Kucing();
        Kucing(string nama) : Hewan(nama){
            this->nama = nama;
        }
        virtual ~Kucing(){
            cout << "Kucing mati " << nama << endl;
        }
        virtual void print(){
            cout << "Hewan ini namanya " << nama << endl;
        }
};

class Anjing : public Hewan {
    public:
        Anjing();
        Anjing(string nama) : Hewan(nama){
            this->nama = nama;
        }
        ~Anjing(){
            cout << "Anjing mati " << nama << endl;
        }
        virtual void print(){
            cout << "Anjing ini namanya " << nama << endl;
        }
};

class KucingAnggora : public Kucing {
    protected:
        string pemilik;
    public:
        KucingAnggora();
        KucingAnggora(string nama, string pemilik) : Kucing(nama){
            this->nama = nama;
            this->pemilik = pemilik;
        }
        ~KucingAnggora(){
            cout << "Kucing anggora mati " << nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        
        }
};

class AnjingBulldog : public Anjing {
    protected:
        string pemilik;
    public:
        AnjingBulldog();
        AnjingBulldog(string nama, string pemilik) : Anjing(nama){
            this->nama = nama;
            this->pemilik = pemilik;
        }   
        ~AnjingBulldog(){
            cout << "Anjing bulldog mati " << nama << endl;
        }
        void print(){
            cout << "Anjing bulldog ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        }
};

#endif