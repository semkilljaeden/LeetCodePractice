import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

/***
 * 14:36
 */
public class Q300_LongestIncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        HashMap<Integer, Integer> memo = new HashMap();
        int result = 0;
        for(int i = nums.length - 1; i >= 0; i--) {
            int max = 0;
            for(Map.Entry<Integer, Integer> e : memo.entrySet()) {
                if(e.getKey() > nums[i]) {
                    max = Math.max(max, e.getValue());
                }
            }
            result = Math.max(max + 1, result);
            memo.put(nums[i], max + 1);
        }
        return result;
    }
}
