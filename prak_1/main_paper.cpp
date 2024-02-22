#include "Paper.hpp"
int main() {
    Paper *a = new Paper('A');
    Paper b('B');
    Paper c('C');
    Paper d(c);
    a->fold();
    b.fold();
    c.fold();
    c.glue();
    delete a;
    c.setName('X');
    d.fold();
    d.glue();
    return 0;
}