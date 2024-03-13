#include <iostream>
#include "Invoker.hpp"

using namespace std;

Invoker::Invoker(): Hero(50, 200) {
    cout << "invoker is born with " << hp << " " << mp << endl;
}

Invoker::Invoker(int hp, int mp): Hero(hp, mp) {
    cout << "invoker is born with " << hp << " " << mp << endl;
}

Invoker::Invoker(const Invoker& i): Hero(i) {
    cout << "invoker copy is born with " << hp << " " << mp << endl;
}

Invoker::~Invoker() {
    cout << "no invoker " << hp << " " << mp << endl;
}

Invoker& Invoker::operator=(const Invoker& i) {
    hp = i.hp;
    mp = i.mp;

    cout << "invoker copied " << hp << " " << mp << endl;

    return *this;
}

void Invoker::move(int x, int y) {
    cout << "invoker is moving to " << x << "," << y << " " << hp << " " << mp << endl;
}

void Invoker::heal(int x) {
    cout << "invoker is healing " << x << " " << hp << " " << mp << endl;
}

void Invoker::useSkill() {
    cout << "invoker is using skill " << hp << " " << mp << endl;
}