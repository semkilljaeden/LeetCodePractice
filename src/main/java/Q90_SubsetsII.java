import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 *
 * 27mins medium (has hint from previous question)
 * Runtime: 1 ms, faster than 99.86% of Java online submissions for Subsets II.
 * Memory Usage: 39.5 MB, less than 86.62% of Java online submissions for Subsets II.
 */
public class Q90_SubsetsII {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList();
        result.add(new ArrayList());
        int prev = Integer.MIN_VALUE;
        int prevSize = 0;
        for(int i = 0; i < nums.length; i++) {
            int size = result.size();
            int start = 0;
            if(nums[i] == prev) {
                start = prevSize;
            }
            prevSize = size;
            for(int j = start; j < size; j++) {
                List<Integer> tmp = new ArrayList(result.get(j));
                tmp.add(nums[i]);
                result.add(tmp);
            }
            prev = nums[i];
        }
        return result;
    }
}
