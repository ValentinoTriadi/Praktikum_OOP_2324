#include "PriorityQueue.hpp"

int main(){

    PriorityQueue<int> pq;
    PriorityQueue<int> pq2;
    cout << pq.GetSize() << endl;

    for (int i = 0; i < 10; i++){
        pq.Enqueue(i+1);
        pq2.Enqueue(i+5);
    }

    cout << pq;

    cout << pq.Front() << endl;

    cout << pq.GetSize() << endl;

    cout << pq.Dequeue() << endl;
    cout << pq;

    cout << pq.Front() << endl;

    cout << pq.GetSize() << endl;

    cout << pq.Dequeue() << endl;
    cout << pq;

    cout << pq.Front() << endl;

    cout << pq.GetSize() << endl;

    cout << pq.Dequeue() << endl;
    cout << pq;

    cout << pq;

    pq.MergeQueue(pq2);
    cout << pq.Front() << endl;

    cout << pq.GetSize() << endl;

    cout << pq;
    return 0;
}