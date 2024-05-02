import java.util.HashMap;
import java.util.Map;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> mapKata = new HashMap<String, Integer>();
        for (String kataTito : tito) {
            if (!mapKata.containsKey(kataTito)) {
                mapKata.put(kataTito, 1);
            }
        }
        
        for (String kataWiwid : wiwid) {
            if (mapKata.containsKey(kataWiwid)){
                System.out.println(kataWiwid);
                mapKata.remove(kataWiwid);
            }
        }
    }
}