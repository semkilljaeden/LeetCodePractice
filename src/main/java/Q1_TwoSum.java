import java.util.HashMap;
import java.util.Map;

/***
 * Runtime: 3 ms  53.72%
 * Memory Usage: 41.8 MB
 */

public class Q1_TwoSum {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> indMap = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            int t = target - nums[i];
            if(indMap.containsKey(t)) {
                return new int[] {indMap.get(t), i};
            }
            indMap.put(nums[i], i);
        }
        return null;
    }
}
