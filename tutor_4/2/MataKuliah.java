import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
  // atribut
  private float rating;
  private String nama;
  private int kodeJurusan;
  private int tahunPengambilan;

  // constructor
  public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
    this.nama = nama;
    this.kodeJurusan = kodeJurusan;
    this.tahunPengambilan = tahunPengambilan;
    this.rating = rating;
  }

  // getter
  public String getNama() {
    return nama;
  }
  public int getKodeJurusan() {
    return kodeJurusan;
  }
  public int getTahunPengambilan() {
    return tahunPengambilan;
  }
  public float getRating() {
    return rating;
  }

  // method
  public int compareTo(MataKuliah m) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    int compareKode = Integer.valueOf(this.kodeJurusan).compareTo(Integer.valueOf(m.kodeJurusan));
    int compareTahun = Integer.valueOf(this.tahunPengambilan).compareTo(Integer.valueOf(m.tahunPengambilan));
    if (compareKode == 0) {
      if (compareTahun == 0) {
        if (this.rating == m.rating) {
          return 0;
        } else if (this.rating < m.rating) {
          return -1;
        } 
        return 1;
      } else {
        return compareTahun;
      }
    } else {
      return compareKode;
    }
  }
}