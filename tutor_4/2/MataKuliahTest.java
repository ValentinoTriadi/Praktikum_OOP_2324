public class MataKuliahTest {
    public static void main(String[] args) {
        MataKuliah m1 = new MataKuliah("Pemrograman Berorientasi Objek", 1, 2020, 4.0f);
        MataKuliah m2 = new MataKuliah("Pemrograman Berorientasi Objek", 1, 2020, 4.0f);
        MataKuliah m3 = new MataKuliah("Pemrograman Berorientasi Objek", 1, 2020, 3.0f);
        MataKuliah m4 = new MataKuliah("Pemrograman Berorientasi Objek", 1, 2019, 4.0f);
        MataKuliah m5 = new MataKuliah("Pemrograman Berorientasi Objek", 2, 2020, 4.0f);
        MataKuliah m6 = new MataKuliah("Pemrograman Berorientasi Objek", 2, 2019, 3.0f);
        MataKuliah m7 = new MataKuliah("Pemrograman Berorientasi Objek", 2, 2019, 3.0f);
        MataKuliah m8 = new MataKuliah("Pemrograman Berorientasi Objek", 2, 2019, 4.0f);
        MataKuliah m9 = new MataKuliah("Pemrograman Berorientasi Objek", 2, 2020, 3.0f);
        MataKuliah m10 = new MataKuliah("Pemrograman Berorientasi Objek", 1, 2019, 3.0f);
        System.out.println(m1.compareTo(m2)); // 0
        System.out.println(m1.compareTo(m3)); // 1
        System.out.println(m1.compareTo(m4)); // 1
        System.out.println(m1.compareTo(m5)); // -1
        System.out.println(m6.compareTo(m1)); // 1
        System.out.println(m7.compareTo(m1)); // 1
        System.out.println(m7.compareTo(m8)); // -1
        System.out.println(m9.compareTo(m8)); // 1
        System.out.println(m1.compareTo(m10)); // 1
    }    
}
