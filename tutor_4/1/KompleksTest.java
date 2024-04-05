public class KompleksTest {
    public static void main(String args[]){
        Kompleks a = new Kompleks(3, 4);
        Kompleks b = new Kompleks(1, 2);
        Kompleks c = a.plus(b);
        Kompleks d = a.minus(b);
        Kompleks e = a.multiply(b);
        Kompleks f = a.multiply(2);
        Kompleks g = new Kompleks(0, 2);
        Kompleks h = new Kompleks(0, -2);
        Kompleks i = new Kompleks(-1, -2);
        Kompleks j = new Kompleks(1, -2);
        Kompleks k = new Kompleks(1, 0);
        Kompleks l = new Kompleks(-1, 0);
        c.print();
        d.print();
        e.print();
        f.print();
        g.print();
        h.print();
        i.print();
        j.print();
        k.print();
        l.print();

        System.out.println(Kompleks.countKompleksInstance());
    }
}