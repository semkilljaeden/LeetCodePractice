import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 *10mins one shot correct. medium
 *
 * Runtime: 1 ms, faster than 99.37% of Java online submissions for Permutations II.
 * Memory Usage: 40.2 MB, less than 54.82% of Java online submissions for Permutations II.
 */
public class Q47_PermutationsII {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        boolean[] mask = new boolean[nums.length];
        Arrays.fill(mask, false);
        recurse(nums, new ArrayList<>(), mask);
        return this.result;
    }

    void recurse(int[] nums, List<Integer> result, boolean[] mask) {
        int count = 0;
        int prev = nums[0] - 1;
        for(int i = 0; i < nums.length; i++) {
            if(mask[i] || nums[i] == prev) {
                count++;
                continue;
            }
            result.add(nums[i]);
            mask[i] = true;
            recurse(nums, result, mask);
            result.remove(result.size() - 1);
            mask[i] = false;
            prev = nums[i];

        }
        if(count == nums.length) {
            this.result.add(new ArrayList<>(result));
        }
    }

}
