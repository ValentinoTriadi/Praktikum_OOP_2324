#include "Bangunan.hpp"

Bangunan::Bangunan(){
    namaBangunan = "Bangunan Kosong";
}
Bangunan::Bangunan(string namaBangunan){
    this->namaBangunan = namaBangunan;
}
string Bangunan::getNamaBangunan(){
    return namaBangunan;
}