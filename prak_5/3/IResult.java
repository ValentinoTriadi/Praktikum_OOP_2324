public interface IResult<T, E extends Exception> {
    // returns true if the result data is not null
    boolean isOk();
  
    // returns true if the result Err is not null
    boolean isErr();
  
    // returns the data if the result is Ok, otherwise throws the error
    T unwrap() throws Exception;
  
    // returns the data if the result is Ok, otherwise returns the default value
    T unwrapOrElse(T defaultValue);
  
    // returns the data if the result is Ok, otherwise throws the default exception
    T unwrapOrThrow(Exception defaultException) throws Exception;
  }