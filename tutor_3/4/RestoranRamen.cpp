#include "RestoranRamen.hpp"

void RestoranRamen::tambahOrder(int n, int p){
    map<int,int>::iterator itr = daftarMeja.begin();
    itr = daftarMeja.find(n);

    if (itr == daftarMeja.end()){
        daftarMeja.insert(pair<int,int>(n,p));
    } else {
        itr->second += p;
    }
}    

int RestoranRamen::tutupOrder(int n){
    map<int,int>::iterator itr = daftarMeja.begin();
    itr = daftarMeja.find(n);

    if (itr != daftarMeja.end()){
        int total = itr->second;
        daftarMeja.erase(itr);
        return total;
    }
    return 0;
}

int RestoranRamen::cekTotal(int n){
    if (daftarMeja.find(n) == daftarMeja.end()){
        return 0;
    }
    return daftarMeja[n];
}

int RestoranRamen::totalMeja(){
    return daftarMeja.size();
}

void RestoranRamen::cetakMeja(){
    if (daftarMeja.size() == 0){
        cout << "Restoran kosong" << endl;
    } else {
        map<int,int>::iterator itr = daftarMeja.begin();
        for(int i = 0; i < daftarMeja.size(); i++){
            cout << "Meja " << itr->first << " = " << itr->second << endl;
            itr++;
        }
    }

}