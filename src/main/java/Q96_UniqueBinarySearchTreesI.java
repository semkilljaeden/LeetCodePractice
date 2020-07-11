import java.util.ArrayList;
import java.util.List;

/***
 *8mins with the understanding from previsou question, one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Unique Binary Search Trees.
 * Memory Usage: 38.1 MB, less than 7.80% of Java online submissions for Unique Binary Search Trees.
 */

public class Q96_UniqueBinarySearchTreesI {
    public int numTrees(int n) {
        if(n == 0) {
            return 0;
        }
        memo = new int[n + 2][n + 2];
        return recurse(1, n);
    }
    int[][] memo;
    public int recurse(int left, int right) {
        if(memo[left][right] > 0) {
            return memo[left][right];
        }
        if(left >= right) {
            memo[left][right] = 1;
            return 1;
        }
        int result = 0;
        for(int i = left; i <= right; i++) {
            int lc = recurse(left, i - 1);
            int rc = recurse(i + 1, right);
            result += lc * rc;
        }
        memo[left][right] = result;
        return result;
    }
}
