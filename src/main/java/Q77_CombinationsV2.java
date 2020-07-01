import java.util.ArrayList;
import java.util.List;

/***
 * 15mins
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Combinations.
 * Memory Usage: 40.7 MB, less than 65.77% of Java online submissions for Combinations.
 */
public class Q77_CombinationsV2 {
    List<List<Integer>> result = new ArrayList();
    public List<List<Integer>> combine(int n, int k) {
        recurse(0, n, k, new ArrayList<Integer>());
        return result;
    }

    public void recurse(int pos, int n, int k, List<Integer> t) {
        if(pos + k > n && k > 0) {
            return;
        }
        if(k == 0) {
            result.add(new ArrayList<Integer>(t));
            return;
        }
        int tmp;
        for(int i = pos; i + k <= n; i++) {
            t.add(i + 1);
            recurse(i + 1, n, k - 1, t);
            t.remove(t.size() - 1);
        }
    }
}
