import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 *Runtime: 2 ms, faster than 67.81% of Java online submissions for Decode Ways.
 * Memory Usage: 38.2 MB, less than 57.62% of Java online submissions for Decode Ways.
 * 31mins medium, can one shot AC but did not expect a input contains 0
 *
 * can be O(1) space since we only need memo[i + 1] and memo[i + 2]
 */
public class Q91_DecodeWays {
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
