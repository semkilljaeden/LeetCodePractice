import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/***
 * 1 Hr Medium
 *
 * Runtime: 2 ms, faster than 99.39% of Java online submissions for Combination Sum.
 * Memory Usage: 39.4 MB, less than 91.43% of Java online submissions for Combination Sum.
 */

public class Q39_CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> r = recursion(candidates, target, 0);
        return r == null ? new ArrayList<>() : r;
    }

    public List<List<Integer>> recursion(int[] candidates, int target, int mask) {
        if(target == 0) {
            ArrayList<List<Integer>> re = new ArrayList<>();
            re.add(new ArrayList<Integer>());
            return re;
        }
        if(target < 0) {
            return null;
        }
        List<List<Integer>> result = new ArrayList<>();
        for(int i = mask; i < candidates.length; i++) {
            List<List<Integer>> r = recursion(candidates, target - candidates[i], i);
            if(r != null) {
                for(List l : r) {
                    l.add(candidates[i]);
                }
                result.addAll(r);
            }
        }
        return result.size() == 0 ? null : result;
    }
}
