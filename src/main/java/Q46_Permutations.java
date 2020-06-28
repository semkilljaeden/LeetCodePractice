import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * 12 mins medium, one shot correct
 *
 *Runtime: 1 ms, faster than 91.86% of Java online submissions for Permutations.
 * Memory Usage: 39.7 MB, less than 61.42% of Java online submissions for Permutations.
 */
public class Q46_Permutations {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        boolean[] mask = new boolean[nums.length];
        Arrays.fill(mask, false);
        recurse(nums, new ArrayList<>(), mask);
        return result;
    }

    public void recurse(int[] nums, List<Integer> result, boolean[] mask) {
        int count = 0;
        for(int i = 0; i < nums.length; i++) {
            if(mask[i]) {
                count++;
                continue;
            }
            mask[i] = true;
            result.add(nums[i]);
            recurse(nums, result, mask);
            mask[i] = false;
            result.remove(result.size() - 1);
        }
        if(count == nums.length) {
            this.result.add(new ArrayList<>(result));
        }
    }
}
