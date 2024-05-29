import java.util.*;

public class Main {
    public static void main(String[] args) {
        SebuahHandler handler = new SebuahHandler();
        HashMap<String, String> headers = new HashMap<>(){
            {
                put("Authorization", "Bearer 123");
            }
        };
        HashMap<String, String> body = new HashMap<>(){
            {
                put("name", "John Doe");
            }
        };
        HashMap<String, String> query = new HashMap<>(){
            {
                put("q", "Hello");
            }
        };
        HashMap<String, String> cookie = new HashMap<>(){
            {
                put("session", "123");
            }
        };

        
        HttpVarLoader loader = new HttpVarLoader(headers, body, query, cookie);
        
        try{
            loader.load(handler);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        handler.print();
    }
}
