class Kompleks {
    // atribute
    private static int n_kompleks;
    private int real;
    private int imaginer;

    // constructor
    public Kompleks(int r, int i) {
        real = r;
        imaginer = i;
        Kompleks.n_kompleks++;
    }
    public Kompleks(){
        this(0,0);
    }

    // getter
    public int getReal(){
        return real;
    }
    public int getImaginer(){
        return imaginer;
    }

    // setter
    public void setReal(int real){
        this.real = real;
    }
    public void setImaginer(int imaginer){
        this.imaginer = imaginer;
    }

    // method
    public Kompleks plus(Kompleks b){
        return new Kompleks(real + b.getReal(), imaginer + b.getImaginer());
    }
    public Kompleks minus(Kompleks b){
        return new Kompleks(real - b.getReal(), imaginer - b.getImaginer());
    }
    public Kompleks multiply(Kompleks b) {
        return new Kompleks(real * b.getReal() - imaginer * b.getImaginer(), real * b.getImaginer() + imaginer * b.getReal());
    }
    public Kompleks multiply (int n){
        return new Kompleks(real * n, imaginer * n);
    }
    public static int countKompleksInstance(){
        return Kompleks.n_kompleks;
    }
    public void print(){
        if (imaginer < 0){
            if (real == 0) System.out.println(imaginer + "i");
            else System.out.println(real + Integer.toString(imaginer) + "i");
        } else if (imaginer > 0) {
            if (real == 0) System.out.println(imaginer + "i");
            else System.out.println(real + "+" + imaginer + "i");
        } else {
            System.out.println(real);
        }
    }
}