#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <stack>
#include <iostream>
using namespace std;

class Restaurant{
    private :
        stack<int> order;
    public:
        /*
            Constructor untuk membuat restaurant
            Order kosong
        */
        Restaurant();

        /*
            Destructor
       */
        ~Restaurant();

        /*
            Menambahkan satu order makanan sejumlah val menu

            Contoh:
            Order = (3, 4, 5)
            val = 2

            Maka order = (2, 3, 4, 5)
        */
        void Push(int val);
       
        /*
            Memproses order makanan sebanyak val
            Apabila val lebih banyak dari jumlah order makanan yang ada, keluarkan "Proses tidak valid"
            dan tidak ada order makanan yang diproses

            Contoh:
            Order = (3, 4, 5)
            val = 2

            maka order = (5)
        */
        void Pop(int val);

        /*
            Menambahkan k order makanan paling akhir diproses sejumlah val menu
            Apabila k lebih besar dari banyaknya order makanan, tambahkan semua order makan sejumlah val menu
        
            Contoh:
            Order = (1, 2, 3)
            k = 2, val = 3

            maka order = (1, 5, 6)
        */
        void AddMenu(int k, int val);
        

        /*
            Memutar urutan pemrosesan k order makanan paling bawah
            Contoh: 
            k = 3
            order =  1 2 3 4 5 (1 merupakan order makanan paling atas untuk diproses)

            Hasil
            order = 1 2 5 4 3

            Jika k > jumlah order, putar seluruh urutan order makanan
        */
        void Reorder(int k);
        
        /*
            Mencetak order makanan pada restaurant dimulai dari paling awal diproses
            Contoh = (1, 2, 3, 4, 5)
            Apabila order kosong cetak ()
        */
        friend ostream& operator<<(ostream&,Restaurant);
        
};


#endif