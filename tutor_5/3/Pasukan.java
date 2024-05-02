import java.util.List;

public class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan(List<Integer> list, int n) {
        this.list = list;
        this.n = n;
    }

    public void reset() {
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }
    public long get(int idx){
        reset();
        Long start = Util.getTime();
        list.get(idx);
        Long end = Util.getTime();
        return end - start;
    }
    public long del(int idx, int len){
        reset();
        Long start = Util.getTime();
        for (int i = 0; i < len; i++) {
            list.remove(idx);
        }
        Long end = Util.getTime();
        return end - start;
    }
}
