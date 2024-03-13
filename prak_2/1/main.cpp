#include "A.hpp"
#include "B.hpp"

int main() {
    B b;

    b.setMe(200);
    A *a = &b;
    a->setMe(10);
    
    b.print();
    return 0;
}
