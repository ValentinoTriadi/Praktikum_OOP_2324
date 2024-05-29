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

    // Ambil semua field dari objek
    Field[] fields = obj.getClass().getDeclaredFields();
    for (Field field : fields) {

      // Jika field memiliki annotation HttpVar
      if (field.isAnnotationPresent(HttpVar.class)) {
        HttpVar annotation = field.getAnnotation(HttpVar.class);
        
        // Ambil key dari annotation
        String key = annotation.name();

        // Ambil type dari annotation
        HttpVar.Type type = annotation.type();

        // Jika key bernilai null atau key tidak ada pada daftar variabel HTTP
        if (key == null || !isVariableExist(key, type)) {
          throw new NullPointerException();
        }
        
        // Ambil value dari key sesuai dengan type
        String value = getValue(key, type);

        // Set field dengan value
        try {
          field.setAccessible(true);
          field.set(obj, value);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
      }
    }

    // Ambil semua method dari objek
    Method[] methods = obj.getClass().getDeclaredMethods();
    for (Method method : methods) {
      // Jika method memiliki annotation HttpVar
      if (method.isAnnotationPresent(HttpVar.class)) {
        HttpVar annotation = method.getAnnotation(HttpVar.class);

        // Ambil key dari annotation
        String key = annotation.name();

        // Ambil type dari annotation
        HttpVar.Type type = annotation.type();

        // Jika key bernilai null atau key tidak ada pada daftar variabel HTTP
        if (key == null || !isVariableExist(key, type)) {
          throw new NullPointerException();
        }

        // Ambil value dari key sesuai dengan type
        String value = getValue(key, type);

        // Panggil method dengan value sebagai parameter
        try {
          method.setAccessible(true);
          method.invoke(obj, (value));
        // } catch (InvocationTargetException e) {
        //   throw new InvocationTargetException(e);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
      }
    }
  }

  private String getValue(String key, HttpVar.Type type) {
    if (type.equals(HttpVar.Type.Header)) {
      return headers.get(key);
    } else if (type.equals(HttpVar.Type.Body)) {
      return body.get(key);
    } else if (type.equals(HttpVar.Type.Query)) {
      return query.get(key);
    } else if (type.equals(HttpVar.Type.Cookie)) {
      return cookie.get(key);
    }
    return null;
  }

  private boolean isVariableExist(String key, HttpVar.Type type) {
    if (type.equals(HttpVar.Type.Header)) {
      return headers.containsKey(key);
    } else if (type.equals(HttpVar.Type.Body)) {
      return body.containsKey(key);
    } else if (type.equals(HttpVar.Type.Query)) {
      return query.containsKey(key);
    } else if (type.equals(HttpVar.Type.Cookie)) {
      return cookie.containsKey(key);
    }
    return false;
  }
}