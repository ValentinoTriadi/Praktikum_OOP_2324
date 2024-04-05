class TempatTinggal {
    // atribut
    protected int luas;
    protected double hargaBahanBangunan;
    

    // getter
    public int getLuas() {
        return luas;
    }
    public double getHargaBahanBangunan() {
        return hargaBahanBangunan;
    }
    // setter
    public void setLuas(int luas) {
        this.luas = luas;
    }
    public void setHargaBahanBangunan(double hargaBahanBangunan) {
        this.hargaBahanBangunan = hargaBahanBangunan;
    }
    
    // method
    public double hitungBiayaBangun() {
        return luas * hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal {
    // atribut

    // konstruktor
    public Rumah(int luas, double hargaBahanBangunan) {
        super.luas = luas;
        super.hargaBahanBangunan = hargaBahanBangunan;
    }
    public Rumah(int lebarTanah, int panjangTanah, double hargaBahanBangunan) {
        super.luas = lebarTanah * panjangTanah;
        super.hargaBahanBangunan = hargaBahanBangunan;
    }

    // setter
    public void setLuas(int luas) {
        super.luas = luas;
    }
    public void setLuas(int panjangBangunan, int lebarBangunan) {
        super.luas = panjangBangunan * lebarBangunan;
    }

    // method
    public double hitungBiayaBangun() {
        return super.hitungBiayaBangun();
    }
    public double hitungBiayaBangun(double biayaOrmas) {
        return super.hitungBiayaBangun() + biayaOrmas;
    }
}

/**
 * Kendaraan
 */
interface Kendaraan {
    public double hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan {
    // atribut
    private float bensin;
    private float pemakaianBensin;

    // getter
    public float getBensin() {
        return bensin;
    }
    public float getPemakaianBensin() {
        return pemakaianBensin;
    }
    // setter
    public void setBensin(float bensin) {
        this.bensin = bensin;
    }
    public void setPemakaianBensin(float pemakaianBensin) {
        this.pemakaianBensin = pemakaianBensin;
    }

    // method
    public double hitungBiayaBangun() {
        return super.hitungBiayaBangun() * 3;
    }
    public double hitungJarakTempuh(){
        return bensin * pemakaianBensin;
    }
}