#include "PlasticCup.hpp"

bool PlasticCup::is_usable(){
    return Plastic::is_usable() && current_microplastics < maximum_microplastics;
}

void PlasticCup::fill(int volume, enum WaterType type){
    if (!PlasticCup::is_usable()) return;

    Cup::fill(volume,type);
    Plastic::use();
    int temp = Plastic::shred_microplastics(Cup::get_water_volume(), Cup::capacity);
    if (type == HOT_WATER){
        temp *= 2;
    }
    current_microplastics += temp;
}

void PlasticCup::drink(int volume){
    if (!PlasticCup::is_usable()) return;

    Cup::drink(volume);
    Plastic::use();
    current_microplastics -= volume;
    if (current_microplastics < 0){
        current_microplastics = 0;
    }
}

void PlasticCup::drop(int height){
    current_microplastics += Plastic::shred_microplastics(Cup::get_water_volume()*height, Cup::capacity);
}