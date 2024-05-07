import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = data;
    }

    public void forEach(Function<T, Void> consumer) {
        for (T item : data) {
            consumer.apply(item);
        }
    }

    public <R> IStreamer<R> map(Function<T, R> mapper) {
        Streamer<R> result = new Streamer<>(new ArrayList<>());
        for (T item : data) {
            result.data.add(mapper.apply(item));
        }
        return result;
    }

    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        Streamer<T> result = new Streamer<>(new ArrayList<>());
        for (T item : data) {
            if (predicate.apply(item)) {
                result.data.add(item);
            }
        }
        return result;
    }

    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R result = initialValue;
        for (T item : data) {
            result = reducer.apply(result).apply(item);
        }
        return result;
    }

    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        Streamer<R> result = new Streamer<>(new ArrayList<>());
        for (T item : data) {
            IStreamer<R> mapped = mapper.apply(item);
            for (R mappedItem : mapped.collect()) {
                result.data.add(mappedItem);
            }
        }
        return result;
    }

    public T findFirst(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    public T findLast(Function<T, Boolean> predicate) {
        for (int i = data.size() - 1; i >= 0; i--) {
            T item = data.get(i);
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    public T head() {
        if (!isEmpty()) return data.get(0);
        return null;
    }

    public IStreamer<T> tail() {
        Streamer<T> result = new Streamer<>(new ArrayList<>());
        for (int i = 1; i < data.size(); i++) {
            result.data.add(data.get(i));
        }
        return result;
    }

    public T last() {
        if (!isEmpty()) return data.get(data.size() - 1);
        return null;
    }

    public IStreamer<T> init() {
        Streamer<T> result = new Streamer<>(new ArrayList<>());
        for (int i = 0; i < data.size() - 1; i++) {
            result.data.add(data.get(i));
        }
        return result;    
    }

    public IStreamer<T> takeFirst(int n) {
        if (n >= data.size()) return new Streamer<>(data); // new Streamer<>(data) is equivalent to this.collect(
        Streamer<T> result = new Streamer<>(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            result.data.add(data.get(i));
        }
        return result;
    }

    public IStreamer<T> takeLast(int n) {
        if (n >= data.size()) return new Streamer<>(data);
        Streamer<T> result = new Streamer<>(new ArrayList<>());
        for (int i = data.size() - n; i < data.size(); i++) {
            result.data.add(data.get(i));
        }
        return result;
    }

    public Boolean isEmpty() {
        return data.isEmpty();
    }

    public Integer count() {
        return data.size();
    }

    public Boolean some(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return true;
            }
        }
        return false;
    }

    public Boolean every(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (!predicate.apply(item)) {
                return false;
            }
        }
        return true;
    }

    public List<T> collect() {
        return data;
    }

    public void reverse() {
        List<T> reversed = new ArrayList<>();
        for (int i = data.size() - 1; i >= 0; i--) {
            reversed.add(data.get(i));
        }
        data = reversed;
    }
}