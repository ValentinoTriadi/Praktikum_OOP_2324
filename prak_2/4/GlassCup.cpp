#include "GlassCup.hpp"

bool GlassCup::is_usable(){
    return Glass::is_usable();
}

void GlassCup::fill(int volume, enum WaterType type){
    if (GlassCup::is_usable()){
        Cup::fill(volume, type);
    }
}

void GlassCup::drink(int volume){
    if (GlassCup::is_usable()){
        Cup::drink(volume);
    }
}

void GlassCup::drop(int height){
    if (Cup::get_water_volume()){
        Glass::apply_force(Cup::get_water_volume() * height);
    } else {
        Glass::apply_force(height);
    }
}