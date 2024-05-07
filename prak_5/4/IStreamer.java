import java.util.List;
import java.util.function.Function;

public interface IStreamer<T> {
  // mengembalikan list yang berisi semua elemen dalam stream
  List<T> collect();

  // memanggil fungsi consumer untuk setiap elemen dalam stream
  void forEach(Function<T, Void> consumer);

  // mengembalikan stream baru yang berisi hasil kembalian fungsi mapper untuk setiap elemen dalam stream
  <R> IStreamer<R> map(Function<T, R> mapper);

  // melakukan filter terhadap elemen dalam stream, jika fungsi predicate mengembalikan true, elemen tersebut akan dimasukkan ke dalam stream baru, jika false, elemen tersebut akan diabaikan
  IStreamer<T> filter(Function<T, Boolean> predicate);

  // mengumpulkan semua elemen dalam stream menjadi satu nilai
  // initialValue adalah nilai awal yang akan digunakan dalam proses reduksi
  // reducer adalah fungsi yang akan digunakan dalam proses reduksi
  // reducer merupakan suatu fungsi yang mengembalikan suatu fungsi lain
  // reducer menerima hasil reduksi sampai saat ini dan mengembalikan fungsi yang menerima elemen
  // stream dan mengembalikan hasil reduksi setelah elemen stream tersebut di proses Contoh:
  // stream.reduce(0.0, (Double acc) -> (Double item) -> acc + item);
  <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer);

  // panggil fungsi mapper untuk setiap elemen dalam stream, kemudian gabungkan hasilnya menjadi satu stream baru
  // misalkan stream berisi [1, 2, 3] dan mapper mengembalikan stream baru [1, 2, 3] untuk setiap elemen, maka hasilnya adalah stream baru [1, 2, 3, 1, 2, 3, 1, 2, 3]
  <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper);

  // mengembalikan elemen pertama dalam stream yang memenuhi kondisi dari fungsi predicate
  // jika tidak ada elemen yang memenuhi kondisi, kembalikan null
  T findFirst(Function<T, Boolean> predicate);

  // mengembalikan elemen terakhir dalam stream yang memenuhi kondisi dari fungsi predicate
  // jika tidak ada elemen yang memenuhi kondisi, kembalikan null
  T findLast(Function<T, Boolean> predicate);

  // mengembalikan elemen pertama dalam stream
  // jika stream kosong, kembalikan null
  T head();

  // mengembalikan stream baru yang berisi semua elemen dalam stream kecuali elemen pertama
  // jika stream kosong, kembalikan stream kosong
  IStreamer<T> tail();

  // mengembalikan elemen terakhir dalam stream
  // jika stream kosong, kembalikan null
  T last();

  // mengembalikan stream baru yang berisi semua elemen dalam stream kecuali elemen terakhir
  // jika stream kosong, kembalikan stream kosong
  IStreamer<T> init();

  // mengembalikan stream baru yang berisi n elemen pertama dalam stream
  // jika n lebih besar dari jumlah elemen dalam stream, ambil semua elemen dalam stream
  IStreamer<T> takeFirst(int n);

  // mengembalikan stream baru yang berisi n elemen terakhir dalam stream
  // contoh: [1, 2, 3, 4, 5].takeLast(3) -> [3, 4, 5]
  // jika n lebih besar dari jumlah elemen dalam stream, ambil semua elemen dalam stream
  IStreamer<T> takeLast(int n);

  // mengembalikan true jika stream kosong, false jika tidak
  Boolean isEmpty();

  // mengembalikan jumlah elemen dalam stream
  Integer count();

  // mengembalikan true jika stream mengandung minimal satu elemen yang memenuhi kondisi dari fungsi predicate, false jika tidak
  Boolean some(Function<T, Boolean> predicate);

  // mengembalikan true jika semua elemen dalam stream memenuhi kondisi dari fungsi predicate, false jika tidak
  Boolean every(Function<T, Boolean> predicate);

  // membalik urutan elemen dalam stream
  void reverse();
}