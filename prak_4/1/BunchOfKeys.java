public class BunchOfKeys {
    private int n_keys;

    public BunchOfKeys(){
        this.n_keys = 0;
    }
    public void add(){
        this.n_keys++;
    }
    public void shake(){
        if (n_keys <= 1){
            System.out.println("Tidak terjadi apa-apa");
        } else {
            for (int i = 0; i < n_keys; i++){
                System.out.println("krincing");
            }
        }
    }
}