#ifndef _HERO_HPP_
#define _HERO_HPP_

class Hero {
    public:
        // Ctor, Cctor, Dtor, dan operasi assignment
        Hero();
        Hero(int hp, int mp);
        Hero(const Hero&);
        virtual ~Hero();

        void move(int x, int y);
        void heal(int x);
        virtual void useSkill() = 0;

    protected:
        int hp; // health point hero
        int mp; // mana point hero
    };

#endif