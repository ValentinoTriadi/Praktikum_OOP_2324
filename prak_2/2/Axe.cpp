#include <iostream>
#include "Axe.hpp"

using namespace std;

Axe::Axe(): Hero(100, 20) {
    cout << "axe is born with " << hp << " " << mp << endl;
}

Axe::Axe(int hp, int mp): Hero(hp, mp) {
    cout << "axe is born with " << hp << " " << mp << endl;
}

Axe::Axe(const Axe& a): Hero(a) {
    cout << "axe copy is born with " << hp << " " << mp << endl;
}

Axe::~Axe() {
    cout << "no axe " << hp << " " << mp << endl;
}

Axe& Axe::operator=(const Axe& a) {
    hp = a.hp;
    mp = a.mp;

    cout << "axe copied " << hp << " " << mp << endl;

    return *this;
}

Axe& Axe::operator+(const Axe& a) {
    Axe* temp = new Axe(hp + a.hp, mp + a.mp);

    cout << "axe here with more power " << temp->hp << " " << temp->mp << endl;

    return *temp;
}

void Axe::move(int x, int y) {
    cout << "axe is moving to " << x << "," << y << " " << hp << " " << mp << endl;
}

void Axe::heal(int x) {
    cout << "axe is healing " << x << " " << hp << " " << mp << endl;
}

void Axe::useSkill() {
    cout << "axe is using skill " << hp << " " << mp << endl;
}