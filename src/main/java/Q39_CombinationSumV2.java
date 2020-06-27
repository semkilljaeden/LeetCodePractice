import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/***
 * 1 Hr Medium
 *
 * Not really faster than V1
 */

public class Q39_CombinationSumV2 {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        recursion(candidates, target, 0, new ArrayList<>());
        return result;
    }

    public void recursion(int[] candidates, int target, int mask, List<Integer> candidate) {
        if(target == 0) {
            result.add(new ArrayList<>(candidate));
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = mask; i < candidates.length; i++) {
            candidate.add(candidates[i]);
            recursion(candidates, target - candidates[i], i, candidate);
            candidate.remove(candidate.size() - 1);
        }
    }
}
