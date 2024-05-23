import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Objects;

public class HttpVarLoader {

  private HashMap<String, String> headers;
  private HashMap<String, String> body;
  private HashMap<String, String> query;
  private HashMap<String, String> cookie;

  /**
   * Variabel HTTP direpresentasikan dengan HashMap key-value.
   * Asumsikan:
   * - Tidak mungkin ada key berupa null
   * - Value mungkin null
   * 
   * @param headers
   * @param body
   * @param query
   * @param cookie
   */
  public HttpVarLoader(HashMap<String, String> headers, HashMap<String, String> body, HashMap<String, String> query,
      HashMap<String, String> cookie) {
    this.headers = new HashMap<>(headers);
    this.body = new HashMap<>(body);
    this.query = new HashMap<>(query);
    this.cookie = new HashMap<>(cookie);
  }

  /**
   * Melakukan load variabel HTTP terhadap objek pada atribut dan method yang
   * menggunakan annotation HttpVar
   * 
   * @param obj Objek
   * @throws NullPointerException      Jika parameter obj bernilai null, atau jika
   *                                   nama variabel yang diminta tidak ada pada
   *                                   daftar variabel HTTP. Throw exception ini
   *                                   tanpa string message apapun.
   * @throws InvocationTargetException Jika method yang dipanggil meng-throw
   *                                   exception. Perhatikan bahwa Method.invoke()
   *                                   meng-throw exception ini.
   */
  public void load(Object obj) throws NullPointerException, InvocationTargetException {
    if (obj == null) {
      throw new NullPointerException();
    }

    Field[] fields = obj.getClass().getDeclaredFields();
    for (Field field : fields) {
      if (field.isAnnotationPresent(HttpVar.class)) {
        HttpVar annotation = field.getAnnotation(HttpVar.class);
        String key = annotation.name();
        String value = null;
        if (annotation.type().equals(HttpVar.Type.Header)) {
          value = headers.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Body)) {
          value = body.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Query)) {
          value = query.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Cookie)) {
          value = cookie.get(key);
        }
        if (value == null) {
          throw new NullPointerException();
        }
        try {
          field.setAccessible(true);
          field.set(obj, value);
        } catch (IllegalAccessException e) {
          e.printStackTrace();
        }
      }
    }

    Method[] methods = obj.getClass().getDeclaredMethods();
    for (Method method : methods) {
      if (method.isAnnotationPresent(HttpVar.class)) {
        HttpVar annotation = method.getAnnotation(HttpVar.class);
        String key = annotation.name();
        String value = null;
        if (annotation.type().equals(HttpVar.Type.Header)) {
          value = headers.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Body)) {
          value = body.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Query)) {
          value = query.get(key);
        } else if (annotation.type().equals(HttpVar.Type.Cookie)) {
          value = cookie.get(key);
        }
        if (value == null) {
          throw new NullPointerException();
        }
        try {
          method.setAccessible(true);
          method.invoke(obj, value);
        } catch (InvocationTargetException e) {
          throw e;
        } catch (IllegalAccessException e) {
          e.printStackTrace();
        }
      }
    }
  }
}