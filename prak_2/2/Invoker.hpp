#ifndef _INVOKER_HPP_
#define _INVOKER_HPP_

#include "Hero.hpp"

class Invoker: public Hero {
    public:
        // Ctor, Cctor, Dtor, dan operasi assignment
        Invoker();
        Invoker(int hp, int mp);
        Invoker(const Invoker&);
        virtual ~Invoker();
        Invoker& operator=(const Invoker&);

        void move(int x, int y);
        void heal(int x);
        void useSkill();
};

#endif