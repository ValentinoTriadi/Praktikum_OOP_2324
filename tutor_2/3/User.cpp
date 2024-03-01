#include "User.h"
#include <iostream>
using namespace std;



int User::n_user = 0;

User::User(char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    num_of_favourite_music = 0;
    this->music_list = new char*[0];
    User::n_user++;
}

User::User(const User& user) {
    this->name = new char[strlen(user.name) + 1];
    strcpy(this->name, user.name);
    this->num_of_favourite_music = user.num_of_favourite_music;
    this->music_list = new char*[num_of_favourite_music];
    for(int i = 0; i < num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(user.music_list[i]) + 1];
        strcpy(this->music_list[i], user.music_list[i]);
    }
    User::n_user++;
}

User::~User() {
    cout << "User " << name << " deleted" << endl;
    delete[] this->name;
    for(int i = 0; i < this -> num_of_favourite_music; i++){
        delete[] this->music_list[i];
    }
    delete[] this->music_list;
}

void User::addFavouriteMusic(char* music) {
    char** temp = new char*[getNumOfFavouriteMusic() + 1];
    for(int i = 0; i < num_of_favourite_music; i++) {
        temp[i] = new char[strlen(music_list[i]) + 1];
        strcpy(temp[i], music_list[i]);
    }
    temp[num_of_favourite_music] = new char[strlen(music) + 1];
    strcpy(temp[num_of_favourite_music], music);
    for(int i = 0; i < this -> num_of_favourite_music; i++){
        delete[] this -> music_list[i];
    }
    delete[] this->music_list;
    num_of_favourite_music++;
    music_list = temp;
    
}

void User::deleteFavouriteMusic(char* music){
    int idx = -1; // init with invalid idx

    // find music idx
    for (int i = 0; i < num_of_favourite_music; i++){
        if (strcmp(music_list[i], music) == 0){
            idx = i;
            break;
        }
    }

    if (idx == -1) return; // if music not found

    // create new list
    char** temp = new char*[num_of_favourite_music-1];
    for (int i = 0; i < idx; i++){
        temp[i] = new char[strlen(music_list[i]) + 1];
        strcpy(temp[i], music_list[i]);
    }
    for (int i = idx + 1; i < num_of_favourite_music; i++){
        temp[i - 1] = new char[strlen(music_list[i]) + 1];
        strcpy(temp[i - 1], music_list[i]);
    }
    for (int i = 0; i < num_of_favourite_music; i++){
        delete[] music_list[i];
    }

    delete[] this->music_list;

    num_of_favourite_music--;
    music_list = temp;
}

void User::setName(char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char* User::getName() const {
    return name;
}

int User::getNumOfFavouriteMusic() const {
    return num_of_favourite_music;
}

void User::viewMusicList() const {
    if (num_of_favourite_music == 0){
        cout << "No music in your favourite list" << endl;
    } else {
        for (int i = 0; i < num_of_favourite_music; i++){
            cout << i+1 << ". " << music_list[i] << endl;
        }
    }
}

int User::getNumOfUser() {
    return n_user;
}