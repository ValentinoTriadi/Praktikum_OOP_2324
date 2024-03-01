#include "PremiumUser.h"
#include <iostream>
using namespace std;

PremiumUser::PremiumUser(char* name) : User(name) {
    active = true;
    num_of_music_downloaded = 0;
}

PremiumUser::PremiumUser(const PremiumUser& user): User(user) {
    active = user.active;
    num_of_music_downloaded = user.num_of_music_downloaded;
    // cout << "Premium User Copied" << endl;
}

PremiumUser::~PremiumUser(){
    // cout << "Premium user " << name << " deleted" << endl;
}

void PremiumUser::downloadMusic(char * music){
    if (!active){
        cout << "Activate premium account to download music" << endl;
    } else {
        cout << "Music Downloaded: " << music << endl;
        num_of_music_downloaded++;
    }
}

void PremiumUser::inactivatePremium(){
    if (active) active = !active;
}

void PremiumUser::activatePremium(){
    if (!active) active = !active;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return active;
}