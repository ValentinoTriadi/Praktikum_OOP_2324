#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include <string>
#include <vector>
#include "Bangunan.hpp"
using namespace std;

#define DEFAULT_BANGUNAN 10
#define DEFAULT_KAYU 10
#define DEFAULT_GULDEN 100
#define DEFAULT_PEKERJA 5

class Walikota {
    private:
        vector<Bangunan> bangunan;
        int kayu;
        int gulden;
        int pekerja;
    public:
        /*
            Membuat objek Walikota dengan jumlah default kayu, gulden, dan pekerja
        */
        Walikota();
        /*
            Membuat objek Walikota dengan jumlah kayu, gulden, dan pekerja sesuai argumen.
        */
        Walikota(int kayu, int gulden, int pekerja);
        /*
            Menghancurkan objek walikota
        */
        ~Walikota();

        /*
            Membangun bangunan baru sesuai nama yang diberikan. Metode ini menggunakan metode pakaiKayu, pakaiGulden, perkejakanPekerja secara urut. Untuk membuat satu bangunan, akan menghabiskan kayu dan gulden sesuai input dan akan dialokasikan 1 pekerja.

            Bangunan gagal dibangun apabila:
            1. Kayu habis. Keluarkan pesan dari exception ditambah dengan ", beli kayu dulu."
            2. Gulden habis. Keluarkan pesan dari exception ditambah dengan ", tagih pajak dulu."
            3. Tidak ada pekerja. Keluarkan pesan dari exception ditambah dengan ", rekrut pekerja dulu."

            Jika gagal dibangun, jumlah kayu, gulden, dan pekerja tidak berkurang. Gunakan metode batalPakaiKayu, batalPakaiGulden, dan batalkanPekerja.

            Jika berhasil, masukkan bangunan ke daftar bangunan dengan metode push_back(Bangunan b) dari vector. Selain itu, tampilkan pesan "Bangunan [<nomor_bangunan>] <nama_bangunan> berhasil dibangun". Untuk mengetahui panjang list saat ini gunakan metode size()

            (semua output ditambah newline)
        */
        void bangunBangunan(string namaBangunan, int kayu, int gulden);
        /*
            Menambahkan kayu sesuai num
        */
        void tambahKayu(int num);
        /*
            Menambahkan gulden sesuai num
        */
        void tambahGulden(int num);
        /*
            Menambahkan pekerja sesuai num
        */
        void tambahPekerja(int num);
        /*
            Menggunakan kayu sesuai num

            Lemparkan exception KayuTidakCukupException jika kayu tidak cukup. Kayu tidak digunakan.
        */
        void pakaiKayu(int num);
        /*
            Menggunakan gulden sesuai num

            Lemparkan exception GuldenTidakCukupException jika gulden tidak cukup. Gulden tidak digunakan.
        */
        void pakaiGulden(int num);
        /*
            Mempekerjakan 1 pekerja

            Lemparkan exception PekerjaTidakCukupException jika pekerja tidak cukup. Pekerja batal bekerja.
        */
        void pekerjakanPekerja();
        /*
            Membatalkan penggunaan kayu sesuai num
        */
        void batalPakaiKayu(int num);
        /*
            Membatalkan penggunaan gulden sesuai num
        */
        void batalPakaiGulden(int num);
        /*
            Membatalkan 1 pekerja
        */
        void batalkanPekerja();
        /*
            Menyebut bangunan pada index idx. Gunakan metode at(int idx) untuk mengakses bangunan. Tampilkan "<nama_bangunan>"

            Tampilkan exception yang dilemparkan c++ ketika idx tidak valid. Akhiri dengan newline.
        */
        void sebutBangunan(int idx);
        /*
            Menampilkan status kota dengan format:
            
            Status kota:
              Kayu: <jumlah_kayu>
              Gulden: <jumlah_gulden>
              Pekerja: <jumlah_pekerja>
              Bangunan:
                Bangunan[i]: <nama_bangunan>
        */
        void statusKota();
};

#endif
