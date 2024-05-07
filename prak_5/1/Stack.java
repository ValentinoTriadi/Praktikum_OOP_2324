import java.util.ArrayList;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_STACK_SIZE = 500;


  //Constructor dengan size default
  public Stack(){
    this(DEFAULT_STACK_SIZE);
  }
  
  //Constructore dengan size = n
  public Stack(int n){
    data = new ArrayList<T>(n);
    lastElmIdx = -1;
    size = n;
  }

  //Copy constructor dari stack lain
  public Stack(final Stack<T> q){
    data = new ArrayList<T>(q.size);
    lastElmIdx = q.lastElmIdx;
    size = q.size;
    for(int i = 0; i <= lastElmIdx; i++){
      data.add(q.data.get(i));
    }
  }

  //Tambahkan elemen t ke dalam stack
  //Jika stack penuh, lempar exception "Stack is full"
  public void push(T t) throws Exception{
    if(isFull()){
      throw new Exception("Stack is full");
    }
    data.add(t);
    lastElmIdx++;
  }

  //Hapus elemen terakhir dari stack
  //Jika stack kosong, lempar exception "Stack is empty"
  public T pop() throws Exception{
    if(isEmpty()){
      throw new Exception("Stack is empty");
    }
    T t = data.get(lastElmIdx);
    data.remove(lastElmIdx);
    lastElmIdx--;
    return t;
  }

  //Cek apakah stack kosong
  public boolean isEmpty(){
    return data.isEmpty();
  }

  //Cek apakah stack penuh
  public boolean isFull(){
    return lastElmIdx == size - 1;
  }
}