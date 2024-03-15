#include "sekretaris.h"
#include <iostream>
using namespace std;

Sekretaris::Sekretaris(){
    kertas = KERTAS_DEFAULT;
    tinta = TINTA_DEFAULT;
    energi = ENERGI_MAX;
    memoLength = 0;
    memo = new Memo[0];
}

Sekretaris::Sekretaris(int kertas, int tinta){
    this->kertas = kertas;
    this->tinta = tinta;
    this->energi = ENERGI_MAX;
    memoLength = 0;
    memo = new Memo[0];
}

Sekretaris::~Sekretaris(){
    delete[] this->memo;
}

void Sekretaris::buatMemo(string pesan, string untuk){
    int total_tinta = pesan.length();
    try{
        pakaiKertas();
        pakaiTinta(total_tinta);
        pakaiEnergi();
        Memo newmemo(pesan, untuk);
        memoLength++;

        Memo* temp = new Memo[memoLength];
        for (int i = 0; i < memoLength-1; i++){
            temp[i] = memo[i];
        }
        temp[memoLength-1] = newmemo;
        delete[] this->memo;
        memo = temp;

        cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
    }
    catch(const KertasHabisException& e){
        cout << e.what() << ", segera isi kertas" << endl;
    }
    catch(const TintaKurangException& e){
        cout << e.what() << ", segera isi tinta" << endl;
        batalPakaiKertas();
    }
    catch(const EnergiHabisException& e){
        cout << e.what() << ", segera istirahat" << endl;
        batalPakaiKertas();
        batalPakaiTinta(total_tinta);
    }
    catch(const PesanKepanjanganException& e){
        cout << e.what() << ", perpendek pesannya" << endl;
        batalPakaiKertas();
        batalPakaiTinta(total_tinta);
        batalPakaiEnergi();
    }
    
}
void Sekretaris::pakaiKertas(){
    if (kertas <= 0) throw KertasHabisException();
    kertas--;
}
void Sekretaris::pakaiTinta(int num){
    if (tinta < num) throw TintaKurangException();
    tinta -= num;
}
void Sekretaris::pakaiEnergi(){
    if (energi <= 0) throw EnergiHabisException();
    energi--;
}
void Sekretaris::batalPakaiKertas(){
    kertas++;
}
void Sekretaris::batalPakaiTinta(int num){
    tinta += num;
}
void Sekretaris::batalPakaiEnergi(){
    energi++;
}
void Sekretaris::isiTinta(int num){
    tinta += num;
}
void Sekretaris::isiKertas(int num){
    kertas += num;
}
void Sekretaris::istirahat(){
    energi = ENERGI_MAX;
}
void Sekretaris::printStatus(){
    cout<< "Status" << endl
        << "  Energi : " << energi << endl
        << "  Tinta : " << tinta << endl
        << "  Kertas : " << kertas << endl
        << "  Memo : " << memoLength << endl;

    for (int i = 0; i < memoLength; i++){
        cout<< "    Memo [" << i+1 << "]" << endl
            << "      Pesan : " << memo[i].getPesan() << endl
            << "      Untuk : " << memo[i].getUntuk() << endl;
    }
}
