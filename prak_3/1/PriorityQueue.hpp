#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue(){
        size = 0;
        content.clear();
    }
    /*
        Destructor
    */
    ~PriorityQueue(){
    }
    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
        vector<T> newTemp;
        bool isEntry = false;
        while (content.size()>0 && !isEntry){
            T temp = Front();
            if (temp > value){
                temp = Dequeue();
                newTemp.push_back(temp);
            } else {
                newTemp.push_back(value);
                isEntry = true;
            }
        }
        if (!isEntry){
            newTemp.push_back(value);
        }
        while (content.size() > 0){
            newTemp.push_back(Dequeue());
        }
        content = newTemp;
        size = content.size();
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T temp = content[0];
        content.erase(content.begin());
        size--;
        return temp;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        return content.front();
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue( PriorityQueue<T> pq){
        while (pq.size > 0){
            T temp = pq.Dequeue();
            this->Enqueue(temp);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize(){
        return size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& os, PriorityQueue<T> pq){
        T temp;
        os << "(";
        for(int i = 0; i < pq.content.size(); i++){
            temp = pq.content[i];
            os << temp;
            if (i < pq.size - 1){
                os << ", ";
            }
        }
        os << ")" << endl;
        return os;
    }


};



#endif