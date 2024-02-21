#include "Item.hpp"
#include <iostream>
using namespace std;

int main(){
    Item a;
    Item b(10, 1000);
    Item c(b);
    Item d(5, 500);
    Item e(3, 300);
    Item f(2, 200);
    Item g(1, 100);
    Item h(10, 1000);
    Item i(10, 900);
    Item j(10, 800);
    Item k(10, 700);
    Item l(10, 600);
    Item m(10, 500);
    Item n(10, 400);
    cout << "a " << a.getSerialNum() << " " << a.getSold() << " " << a.getPrice() << endl;
    cout << "b " << b.getSerialNum() << " " << b.getSold() << " " << b.getPrice() << endl;
    cout << "c " << c.getSerialNum() << " " << c.getSold() << " " << c.getPrice() << endl;
    cout << "d " << d.getSerialNum() << " " << d.getSold() << " " << d.getPrice() << endl;
    cout << "e " << e.getSerialNum() << " " << e.getSold() << " " << e.getPrice() << endl;
    cout << "f " << f.getSerialNum() << " " << f.getSold() << " " << f.getPrice() << endl;
    cout << "g " << g.getSerialNum() << " " << g.getSold() << " " << g.getPrice() << endl;
    cout << "h " << h.getSerialNum() << " " << h.getSold() << " " << h.getPrice() << endl;
    cout << "i " << i.getSerialNum() << " " << i.getSold() << " " << i.getPrice() << endl;
    cout << "j " << j.getSerialNum() << " " << j.getSold() << " " << j.getPrice() << endl;
    cout << "k " << k.getSerialNum() << " " << k.getSold() << " " << k.getPrice() << endl;
    cout << "l " << l.getSerialNum() << " " << l.getSold() << " " << l.getPrice() << endl;
    cout << "m " << m.getSerialNum() << " " << m.getSold() << " " << m.getPrice() << endl;
    cout << "n " << n.getSerialNum() << " " << n.getSold() << " " << n.getPrice() << endl;

    a.setPrice(100);
    cout << "a new price: " << a.getPrice() << endl;
    n.sell(5);
    cout << "n sold: " << n.getSold() << endl;
    n.sell(10);
    cout << "n sold: " << n.getSold() << endl;
    n.addStock(5);
    n.sell(10);
    cout << "n sold: " << n.getSold() << endl;
    
    return 0;
}