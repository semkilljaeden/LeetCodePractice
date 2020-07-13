import java.util.ArrayList;
import java.util.List;

/***
 * 7mins
 */
public class Q706_DesignHashMap {
    List<Integer> a = new ArrayList<Integer>();
    /** Initialize your data structure here. */
    public Q706_DesignHashMap() {

    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        if(key > a.size() - 1) {
            while(key >= a.size() - 1) {
                a.add(-1);
            }
        }
        a.set(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        if(key >= a.size()) {
            return -1;
        }
        return a.get(key);
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        if(key < a.size()) {
            a.set(key, -1);
        }
    }
}
