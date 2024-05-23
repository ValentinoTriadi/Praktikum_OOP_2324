import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> methods = new ArrayList<>();
        try {
            Class<?> ghost = Class.forName("Ghost");
            for (Method method : ghost.getDeclaredMethods()) {
                methods.add(method.getName());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return methods; 
    }   

    public Integer sumGhost() throws Exception{
        Integer sum = 0;
        try {
            Class<?> ghost = Class.forName("Ghost");
            for (Method method : ghost.getDeclaredMethods()){
                if (method.getReturnType().equals(Integer.class)){
                    method.setAccessible(true);
                    sum += (Integer) method.invoke(ghost.newInstance());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        String temp = "";
        try {
            Class<?> ghost = Class.forName("Ghost");
            for (Method method : ghost.getDeclaredMethods()){
                if (method.getReturnType().equals(String.class)){
                    method.setAccessible(true);
                    temp += (String) method.invoke(ghost.newInstance());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return temp;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret secret : sl){
            if (secret.isThis(email)){
                Field field = Secret.class.getDeclaredField("uniqueId");
                field.setAccessible(true);
                return (String) field.get(secret);
            }
        }
        return "NaN";
    }
}
