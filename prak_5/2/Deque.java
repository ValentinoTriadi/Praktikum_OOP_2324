import java.util.ArrayList;
import java.util.List;

// Class Deque berikut merupakan suatu kelas Generic yang merepresentasikan suatu Deque.
// Deque merupakan suatu struktur data yang mirip dengan Queue, namun Deque memiliki dua ujung, yaitu front dan back.
// Deque disimpan dengan memanfaatkan ArrayList.
// Elemen front pada Deque disimpan pada indeks paling kiri, sedangkan elemen back disimpan pada indeks paling kanan.
public class Deque<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_Deque_SIZE = 500;


  //Constructor dengan size default
  public Deque(){
    this(DEFAULT_Deque_SIZE);
  }

  //Constructor dengan size = n
  public Deque(int n){
    data = new ArrayList<T>(n);
    lastElmIdx = -1;
    size = n;
  }

  //Copy Constructor dari Deque lain
  public Deque(final Deque<T> q){
    data = new ArrayList<T>(q.size);
    lastElmIdx = q.lastElmIdx;
    size = q.size;
    for(int i = 0; i <= lastElmIdx; i++){
      data.add(q.data.get(i));
    }
  }

  //Method untuk menambahkan elemen pada ujung front Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushFront(T t) throws Exception{
    if(isFull()){
      throw new Exception("Deque is full");
    }
    data.add(0, t);
    lastElmIdx++;
  }

  //Method untuk menambahkan elemen pada ujung back Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushBack(T t) throws Exception{
    if(isFull()){
      throw new Exception("Deque is full");
    }
    data.add(t);
    lastElmIdx++;
  }

  //Method untuk menghapus elemen pada ujung front Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popFront() throws Exception{
    if(isEmpty()){
      throw new Exception("Deque is empty");
    }
    T t = data.get(0);
    data.remove(0);
    lastElmIdx--;
    return t;
  }

  //Method untuk menghapus elemen pada ujung back Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popBack() throws Exception{
    if(isEmpty()){
      throw new Exception("Deque is empty");
    }
    T t = data.get(lastElmIdx);
    data.remove(lastElmIdx);
    lastElmIdx--;
    return t;
  }

  //Method untuk membalikkan urutan elemen pada Deque
  public void reverse(){
    List<T> temp = new ArrayList<T>(size);
    for(int i = lastElmIdx; i >= 0; i--){
      temp.add(data.get(i));
    }
    data = temp;
  }

  //Method untuk mengecek apakah Deque kosong
  public boolean isEmpty(){
    return data.isEmpty();
  }
  
  //Method untuk mengecek apakah Deque penuh
  public boolean isFull(){
    return data.size() == size;
  }

  //Method untuk mendapatkan ukuran Deque
  public int size(){
    return data.size();
  }
}