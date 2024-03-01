#include "ArtistUser.h"
#include <iostream>
using namespace std;

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* name) : User(name) {
    num_of_music_uploaded = 0;
    uploaded_music_list = new char*[0];
    ArtistUser::num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& user) : User(user.name) {
    num_of_music_uploaded = user.num_of_music_uploaded;
    uploaded_music_list = new char*[num_of_music_uploaded];
    for(int i = 0; i < num_of_music_uploaded; i++) {
        uploaded_music_list[i] = new char[strlen(user.uploaded_music_list[i]) + 1];
        strcpy(uploaded_music_list[i], user.uploaded_music_list[i]);
    }
    ArtistUser::num_of_artist++;
}

ArtistUser::~ArtistUser() {
    cout << "Artist user " << name << " deleted" << endl;
    delete[] this->uploaded_music_list;
}

void ArtistUser::uploadMusic(char* music) {
    char** temp = new char*[num_of_music_uploaded + 1];
    for (int i = 0; i < num_of_music_uploaded; i++){
        temp[i] = new char[strlen(uploaded_music_list[i]) + 1];
        strcpy(temp[i], uploaded_music_list[i]);
        delete[] this->uploaded_music_list[i];
    }
    temp[num_of_music_uploaded] = new char[strlen(music) + 1];
    strcpy(temp[num_of_music_uploaded], music);
    delete[] this->uploaded_music_list;
    num_of_music_uploaded++;
    uploaded_music_list = temp;
}

void ArtistUser::deleteUploadedMusic(char* music) {
    int idx = -1;
    for (int i = 0; i < num_of_music_uploaded; i++){
        if (strcmp(uploaded_music_list[i], music) == 0){
            idx = i;
            break;
        }
    }
    if (idx == -1) return;
    char** temp = new char*[num_of_music_uploaded - 1];
    for (int i = 0; i < idx; i++){
        temp[i] = new char[strlen(uploaded_music_list[i]) + 1];
        strcpy(temp[i], uploaded_music_list[i]);
    }
    for (int i = idx + 1; i < num_of_music_uploaded; i++){
        temp[i - 1] = new char[strlen(uploaded_music_list[i]) + 1];
        strcpy(temp[i - 1], uploaded_music_list[i]);
    }
    for (int i = 0; i < num_of_music_uploaded; i++){
        delete[] this->uploaded_music_list[i];
    }
    delete[] this->uploaded_music_list;
    num_of_music_uploaded--;
    uploaded_music_list = temp;
}

void ArtistUser::viewUploadedMusicList() const {
    if (num_of_music_uploaded == 0){
        cout << "No music uploaded" << endl;
    } else {
        for (int i = 0; i < num_of_music_uploaded; i++){
            cout << i + 1 << ". " << uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}