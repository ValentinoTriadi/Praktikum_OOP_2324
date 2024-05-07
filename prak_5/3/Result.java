public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;
  
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
        Result<T, E> result = new Result<T, E>();
        result.data = data;
        return result;
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
        Result<T, E> result = new Result<T, E>();
        result.error = error;
        return result;
    }
  
    // implement all other functions in the interface
    public boolean isOk() {
        return data != null;
    }

    public boolean isErr() {
        return error != null;
    }

    public T unwrap() throws Exception {
        if (isOk()) return data;
        throw error;
    }

    public T unwrapOrElse(T defaultValue) {
        if (isOk()) return data;
        return defaultValue;
    }

    public T unwrapOrThrow(Exception defaultException) throws Exception {
        if (isOk()) return data;
        throw defaultException;
    }
  }