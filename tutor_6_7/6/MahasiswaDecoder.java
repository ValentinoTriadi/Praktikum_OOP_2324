import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method addMatkul = Mahasiswa.class.getDeclaredMethod("addMatkul", String.class);
        addMatkul.setAccessible(true);
        addMatkul.invoke(mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Field NIM = Mahasiswa.class.getDeclaredField("NIM");
        NIM.setAccessible(true);
        return (int) NIM.get(mahasiswa);
    }

    public double getIPK() throws Exception {
        Field IPK = Mahasiswa.class.getDeclaredField("IPK");
        IPK.setAccessible(true);
        return (double) IPK.get(mahasiswa);
    }

}