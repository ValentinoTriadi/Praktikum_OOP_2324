#include "User.h" 
#include "PremiumUser.h"
#include "ArtistUser.h"
#include <iostream>
using namespace std;

int main(){
    string str_name1 = "1";
    char* name1 = str_name1.data();
    string str_name2 = "2";
    char* name2 = str_name2.data();
    string str_name3 = "3";
    char* name3 = str_name3.data();
    string str_name4 = "4";
    char* name4 = str_name4.data();
    string str_pre1 = "Pre1";
    char* pre1 = str_pre1.data();
    string str_pre2 = "Pre2";
    char* pre2 = str_pre2.data();
    string str_art1 = "Art1";
    char* art1 = str_art1.data();
    string srt_art2 = "Art2";
    char* art2 = srt_art2.data();
    string str_song1 = "song1";
    char* song1 = str_song1.data();
    string str_song2 = "song2";
    char* song2 = str_song2.data();
    string str_song3 = "song3";
    char* song3 = str_song3.data();
    string str_song4 = "song4";
    char* song4 = str_song4.data();

    cout << "START" << endl;
    // Test case 1: Deleting an existing music from the list
    User user1(name1);
    cout << "EEEEE" << endl;
    user1.addFavouriteMusic(song1);
    cout << "EEEEE" << endl;
    user1.addFavouriteMusic(song2);
    cout << "EEEEE" << endl;
    user1.addFavouriteMusic(song3);
    cout << "EEEEE" << endl;
    user1.viewMusicList();
    cout << "EEEEE" << endl;
    user1.deleteFavouriteMusic(song2);
    cout << "EEEEE" << endl;
    user1.viewMusicList();
    cout << "EEEEE" << endl;
    // After deletion, the music list should contain "Song 1" and "Song 3"

    User user2(user1);
    user2.addFavouriteMusic(song2);
    user2.addFavouriteMusic(song4);
    user2.viewMusicList();
    user2.deleteFavouriteMusic(song1);
    user2.viewMusicList();

    // Test case 2: Deleting a non-existing music from the list
    User user3(name3);
    user3.deleteFavouriteMusic(song4);
    char* name_temp1 = user3.getName();
    cout << "get name 1 : " << name_temp1 << endl;
    user3.setName(name4);
    char* name_temp2 = user3.getName();
    cout << "get name 2 : " << name_temp2 << endl;


    cout << "get num of favorite 1 : " << user1.getNumOfFavouriteMusic() << endl;
    cout << "get num of favorite 2 : " << user2.getNumOfFavouriteMusic() << endl;
    cout << "get num of favorite 3 : " << user3.getNumOfFavouriteMusic() << endl;
    cout << "get num of user : " << User::getNumOfUser() << endl;

    User *temp = new User(name1);
    cout << "get name temp: " << temp->getName() << endl;
    delete temp;

    cout << "---------------------------------------------------------" << endl;

    PremiumUser Pre1(pre1);
    cout << "is " << Pre1.getName() << " active: " << Pre1.getPremiumStatus() << endl;
    cout << "total " <<  Pre1.getName() << " downloaded music: " << Pre1.getNumOfMusicDownloaded() << endl;
    cout << "total " <<  Pre1.getName() << " favorite music: " << Pre1.getNumOfFavouriteMusic() << endl;
    Pre1.downloadMusic(song1);
    Pre1.downloadMusic(song2);
    Pre1.addFavouriteMusic(song1);
    Pre1.addFavouriteMusic(song2);
    cout << "total " <<  Pre1.getName() << " downloaded music: " << Pre1.getNumOfMusicDownloaded() << endl;
    cout << "total " <<  Pre1.getName() << " favorite music: " << Pre1.getNumOfFavouriteMusic() << endl;
    Pre1.viewMusicList();
    Pre1.inactivatePremium();
    cout << "is" << Pre1.getName() << "active: " << Pre1.getPremiumStatus() << endl;
    Pre1.activatePremium();
    cout << "is" << Pre1.getName() << "active: " << Pre1.getPremiumStatus() << endl;
    Pre1.activatePremium();
    cout << "is" << Pre1.getName() << "active: " << Pre1.getPremiumStatus() << endl;

    PremiumUser *Pre2 = new PremiumUser(Pre1);
    cout << "Premium User 2: " << Pre2->getName() << endl;
    Pre2->setName(pre2);
    cout << "Premium User 2: " << Pre2->getName() << endl;
    delete Pre2;

    cout << "---------------------------------------------------------" << endl;

    cout << "total artist: " << ArtistUser::getNumOfArtist() << endl;
    ArtistUser Art1(art1);
    cout << "total artist: " << ArtistUser::getNumOfArtist() << endl;
    cout << Art1.getName() << " Uploaded music: " << Art1.getNumOfMusicUploaded() << endl;
    Art1.viewUploadedMusicList();
    Art1.uploadMusic(song1);
    Art1.uploadMusic(song2);
    Art1.uploadMusic(song3);
    Art1.viewUploadedMusicList();
    Art1.deleteUploadedMusic(song2);
    Art1.viewUploadedMusicList();

    ArtistUser *Art2 = new ArtistUser(Art1);
    cout << "total artist: " << ArtistUser::getNumOfArtist() << endl;
    Art2->viewUploadedMusicList();
    Art2->deleteUploadedMusic(song1);
    Art2->viewUploadedMusicList();
    Art2->setName(art2);

    delete Art2;




    return 0;
}