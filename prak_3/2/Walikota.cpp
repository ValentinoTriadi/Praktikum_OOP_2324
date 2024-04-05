#include "Walikota.hpp"
#include <iostream>
using namespace std;

Walikota::Walikota(){
    kayu = DEFAULT_KAYU;
    gulden = DEFAULT_GULDEN;
    pekerja = DEFAULT_PEKERJA;
}

Walikota::Walikota(int kayu, int gulden, int pekerja){
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja; 
}

Walikota::~Walikota(){
}
void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden){
    try {
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();

        Bangunan b(namaBangunan);
        bangunan.push_back(b);

        cout << "Bangunan ["<< bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << endl;

    } catch (KayuTidakCukupException e){
        cout << e.what() << ", beli kayu dulu." << endl;
    } catch (GuldenTidakCukupException e){
        cout << e.what() << ", tagih pajak dulu." << endl;
        batalPakaiKayu(kayu);
    } catch (PekerjaTidakCukupException e){
        cout << e.what() << ", rekrut pekerja dulu." << endl;
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden);
    }
}
void Walikota::tambahKayu(int num){
    kayu += num;
}
void Walikota::tambahGulden(int num){
    gulden += num;
}
void Walikota::tambahPekerja(int num){
    pekerja += num;
}
void Walikota::pakaiKayu(int num){
    if (kayu < num) throw KayuTidakCukupException();
    kayu -= num;
}
void Walikota::pakaiGulden(int num){
    if (gulden < num) throw GuldenTidakCukupException();
    gulden -= num;
}
void Walikota::pekerjakanPekerja(){
    if (pekerja < 1) throw PekerjaTidakCukupException();
    pekerja--;
}
void Walikota::batalPakaiKayu(int num){
    kayu += num;
}
void Walikota::batalPakaiGulden(int num){
    gulden += num;
}
void Walikota::batalkanPekerja(){
    pekerja++;
}
void Walikota::sebutBangunan(int idx){
    try {
        string temp = bangunan.at(idx).getNamaBangunan();
        cout << temp << endl;
    } catch (const exception& e){
        cout << e.what() << endl;
    }
}
void Walikota::statusKota(){
    cout << "Status" << endl;
    cout << "  Kayu: " << kayu << endl;
    cout << "  Gulden: " << gulden << endl;
    cout << "  Pekerja: " << pekerja << endl;
    cout << "  Bangunan:" << endl;
    for (int i = 0; i < bangunan.size(); i++){
        cout << "    Bangunan[" << i+1 << "]: " << bangunan[i].getNamaBangunan() << endl;
    }
    
}