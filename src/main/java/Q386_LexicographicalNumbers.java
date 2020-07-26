import java.util.ArrayList;
import java.util.List;

/***
 * 6mins medium
 * Runtime: 3 ms, faster than 75.50% of Java online submissions for Lexicographical Numbers.
 * Memory Usage: 45.3 MB, less than 37.50% of Java online submissions for Lexicographical Numbers.
 */
public class Q386_LexicographicalNumbers {
    List<Integer> result = new ArrayList();
    int n;
    public List<Integer> lexicalOrder(int n) {
        this.n = n;
        for(int i = 1; i < 10; i++) {
            rec(i);
        }
        return result;
    }

    public void rec(int x) {
        if(x > n) {
            return;
        }
        result.add(x);
        x *= 10;
        for(int i = 0; i < 10; i++) {
            rec(x + i);
        }
    }
}
