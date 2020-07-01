import java.util.ArrayList;
import java.util.List;

/***
 * 10mins medium
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Subsets.
 * Memory Usage: 39.7 MB, less than 60.38% of Java online submissions for Subsets.
 */
public class Q78_Subsets {
    List<List<Integer>> result = new ArrayList();
    public List<List<Integer>> subsets(int[] nums) {
        result.add(new ArrayList());
        recurse(0, nums, new ArrayList());
        return result;
    }

    public void recurse(int pos, int[] nums, List<Integer> t) {
        for(int i = pos; i < nums.length; i++) {
            t.add(nums[i]);
            result.add(new ArrayList(t));
            recurse(i + 1, nums, t);
            t.remove(t.size() - 1);
        }
    }
}
