#include "Walikota.hpp"

int main(){
    Walikota w1;
    Walikota w2(1,1,1);

    w1.bangunBangunan("B1", 4,5);
    w1.sebutBangunan(2);
    w1.sebutBangunan(1);
    w1.sebutBangunan(0);

    w1.statusKota();

    w2.bangunBangunan("B2",1,6);
    w2.bangunBangunan("B2",6,1);
    w2.bangunBangunan("B2",1,1);
    w2.bangunBangunan("B2",0,0);

    w2.sebutBangunan(2);
    w2.sebutBangunan(1);
    w2.sebutBangunan(0);

    w2.statusKota();

    return 0;
}