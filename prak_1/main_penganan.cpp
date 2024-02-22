#include "Penganan.hpp"
#include <iostream>
using namespace std;

int main(){
    Penganan a;
    Penganan b(10,10);
    Penganan c(b);
    cout << "keik a: "<< a.GetKeik() << endl;
    cout << "keik b: "<< b.GetKeik() << endl;
    cout << "keik c: "<< c.GetKeik() << endl;
    cout << "Panekuk a: "<< a.GetPanekuk() << endl;
    cout << "Panekuk b: "<< b.GetPanekuk() << endl;
    cout << "Panekuk c: "<< c.GetPanekuk() << endl;
    a.SetKeik(5);
    a.SetPanekuk(5);
    cout << "keik a: "<< a.GetKeik() << endl;
    cout << "Panekuk a: "<< a.GetPanekuk() << endl;

    cout << "Jumlah Uang: " << a.JumlahUang() << endl;    
    cout << "Jumlah Rumah: " << a.HitungNRumah() << endl;    

    Penganan plus = a+b;
    Penganan min1 = b-a;
    cout << "Jumlah Uang: " << a.JumlahUang() << endl;    
    cout << "Jumlah Rumah: " << a.HitungNRumah() << endl;    
    Penganan min2 = a-b;
    cout << "Jumlah Uang: " << a.JumlahUang() << endl;    
    cout << "Jumlah Rumah: " << a.HitungNRumah() << endl;    
    Penganan xor1 = a^10;
    Penganan xor2 = b^5;
    cout << "Jumlah Uang: " << a.JumlahUang() << endl;    
    cout << "Jumlah Rumah: " << a.HitungNRumah() << endl;    


}