import java.util.ArrayList;
import java.util.List;

/***
 * 27mins
 * Runtime: 47 ms, faster than 16.35% of Java online submissions for Combinations.
 * Memory Usage: 40.9 MB, less than 50.16% of Java online submissions for Combinations.
 */
public class Q77_Combinations {
    List<List<Integer>> result = new ArrayList();
    public List<List<Integer>> combine(int n, int k) {
        recurse(0, n, k, new ArrayList<Integer>());
        return result;
    }

    public void recurse(int mask, int n, int k, List<Integer> t) {
        if(k == 0) {
            result.add(new ArrayList<Integer>(t));
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(((1 << i) - 1  | mask) > mask) {
                t.add(i);
                recurse(mask | (1 << i) - 1, n, k - 1, t);
                t.remove(t.size() - 1);
            }
        }
    }
}
