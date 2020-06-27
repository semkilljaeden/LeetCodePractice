import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * 20mins medium
 Runtime: 3 ms, faster than 80.94% of Java online submissions for Combination Sum II.
 Memory Usage: 39.7 MB, less than 63.88% of Java online submissions for Combination Sum II.
 */

public class Q40_CombinationSumII {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        recursion(candidates, target, 0, new ArrayList());
        return result;
    }

    public void recursion(int[] candidates, int target, int mask, List candidate) {
        if(target == 0) {
            result.add(new ArrayList<>(candidate));
            return;
        }
        if(target < 0) {
            return;
        }
        int pre = Integer.MAX_VALUE;
        for(int i = mask; i < candidates.length; i++) {
            if(candidates[i] == pre) {
                continue;
            }
            candidate.add(candidates[i]);
            recursion(candidates, target - candidates[i], i + 1, candidate);
            candidate.remove(candidate.size() - 1);
            pre = candidates[i];
        }
    }
}
