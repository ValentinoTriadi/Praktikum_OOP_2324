#include <iostream>
#include "Hero.hpp"

using namespace std;

Hero::Hero() {
    this->hp = 100;
    this->mp = 100;
    cout << "hero is born with " << hp << " " << mp << endl;
}

Hero::Hero(int hp, int mp) {
    this->hp = hp;
    this->mp = mp;
    cout << "hero is born with " << hp << " " << mp << endl;
}

Hero::Hero(const Hero& h) {
    this->hp = h.hp;
    this->mp = h.mp;
    cout << "hero is copied with " << hp << " " << mp << endl;
}

Hero::~Hero() {
    cout << "hero has fallen " << hp << " " << mp << endl;
}

void Hero::move(int x, int y) {
    cout << "hero is moving to " << x << "," << y << " " << hp << " " << mp << endl;
}

void Hero::heal(int x) {
    cout << "hero is healing " << x << " " << hp << " " << mp << endl;
}

void Hero::useSkill() {
    cout << "hero is using a skill" << hp << " " << mp << endl;
}