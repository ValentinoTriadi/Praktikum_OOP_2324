#include "RestoranRamen.hpp"

int main(){
    RestoranRamen r;
    r.tambahOrder(1, 5000);
    r.tambahOrder(2, 3000);
    r.tambahOrder(4, 10000);
    r.cetakMeja();
    cout << r.cekTotal(1) << endl;
    cout << r.cekTotal(2) << endl;
    cout << r.cekTotal(3) << endl;
    cout << r.cekTotal(4) << endl;
    cout << r.tutupOrder(1) << endl;
    cout << r.tutupOrder(2) << endl;
    cout << r.tutupOrder(3) << endl;
    cout << r.tutupOrder(4) << endl;
    r.cetakMeja();
    

    return 0;
}