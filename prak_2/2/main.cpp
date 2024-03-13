#include "Axe.hpp"
#include "Hero.hpp"
#include "Invoker.hpp"

int main(){
    Invoker *I1 = new Invoker(10, 1000);
    I1->useSkill();
    Invoker *I2 = new Invoker(*I1);
    I2->Hero::heal(1);
    Invoker *I3 = new Invoker();
    I3->move(10,25);
    *I1=*I1;

    Axe *A1 = new Axe(200,10);
    A1->move(2,20);
    A1->heal(10);
    Axe *A2 = new Axe(*A1);
    Axe *A3 = new Axe(*A1 + *A2);
    A1->useSkill();
    A3->useSkill();

    delete A1;
    delete A3;

    delete I1;

    return 0;
}