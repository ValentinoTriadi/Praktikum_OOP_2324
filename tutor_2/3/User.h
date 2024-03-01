#ifndef USER_H
#define USER_H

#include <cstring>

class User {
    public:
        // ctor, parameter: nama pengguna
        User(char*);
        
        // cctor
        User(const User&);

        // dtor
        // selain implementasi, print juga "User <nama user> deleted<endl>"
        // Contoh:
        // User A deleted
        //
        ~User();

        // Asumsi: musik unik, parameter: judul musik
        void addFavouriteMusic(char*);
        void deleteFavouriteMusic(char*);
            // int idx = -1;
            // for(int i = 0; i < num_of_favourite_music; i++) {
            //     if(strcmp(music_list[i], music) == 0) {
            //         idx = i;
            //         break;
            //     }
            // }
            // if(idx == -1) {
            //     return;
            // }
            // char** temp = new char*[num_of_favourite_music - 1];
            // for(int i = 0; i < idx; i++) {
            //     temp[i] = new char[strlen(music_list[i]) + 1];
            //     strcpy(temp[i], music_list[i]);
            // }
            // for(int i = idx + 1; i < num_of_favourite_music; i++) {
            //     temp[i - 1] = new char[strlen(music_list[i]) + 1];
            //     strcpy(temp[i - 1], music_list[i]);
            // }
            // for(int i = 0; i < num_of_favourite_music; i++) {
            //     delete[] music_list[i];
            // }
            // delete[] music_list;
            // num_of_favourite_music--;
            // music_list = temp;
        
        void setName(char*);
        char* getName() const;
        int getNumOfFavouriteMusic() const;

        // format print:
        // <No>. <Judul musik><endl>
        // contoh:
        // 1. Starship - Nicki Minaj
        // 2. To Be Human - Sia, Labrinth
        //
        // jika tidak ada musik, print: "No music in your favourite list<endl>"
        void viewMusicList() const;

        static int getNumOfUser();
    protected:
        char* name;
        int num_of_favourite_music; // jumlah musik yang ada pada music_list
        char** music_list; // daftar judul musik
        static int n_user;
};

#endif