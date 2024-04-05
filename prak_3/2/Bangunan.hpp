#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include "Exception.hpp"
using namespace std;

class Bangunan {
    public:
        /*
            Membuat objek Bangunan dengan nama "Bangunan Kosong"
        */
        Bangunan();
        /*
            Membuat objek Bangunan dengan nama "namaBangunan"
        */
        Bangunan(string namaBangunan);
        /*
            Mendapatkan nama Bangunan
        */
        string getNamaBangunan();
    private:
        string namaBangunan;
};

#endif