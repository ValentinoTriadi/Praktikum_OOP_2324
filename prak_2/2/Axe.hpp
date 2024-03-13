#ifndef _AXE_HPP_
#define _AXE_HPP_

#include "Hero.hpp"

class Axe: public Hero {
    public:
        // Ctor, Cctor, Dtor, dan operasi assignment
        Axe();
        Axe(int hp, int mp);
        Axe(const Axe&);
        virtual ~Axe();
        Axe& operator=(const Axe&);
        Axe& operator+(const Axe&);

        void move(int x, int y);
        void heal(int x);
        void useSkill();
};

#endif