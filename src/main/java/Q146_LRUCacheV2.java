import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

/***
 * 1:30hr, spend too much time on debugging double linked list
 */
public class Q146_LRUCacheV2 extends LinkedHashMap<Integer, Integer> {
    private int capacity;

    public Q146_LRUCacheV2(int capacity) {
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity;
    }
}
