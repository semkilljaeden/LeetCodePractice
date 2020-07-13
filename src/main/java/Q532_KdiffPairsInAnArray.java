import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/***
 * 10mins, brutal force
 */
public class Q532_KdiffPairsInAnArray {
    public int findPairs(int[] nums, int k) {
        if(nums.length == 0) {
            return 0;
        }
        int count = 0;
        Arrays.sort(nums);
        int prev = nums[0] - 1;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == prev) {
                continue;
            }
            if(i + 1 < nums.length) {
                prev = nums[i + 1] - 1;
            }
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[j] == prev) {
                    continue;
                }
                if(Math.abs(nums[i] - nums[j]) == k) {
                    count++;
                }
                prev = nums[j];
            }
            prev = nums[i];
        }
        return count;
    }

    public int findPairs2(int[] nums, int k) {

        int result = 0;

        HashMap<Integer,Integer> counter = new HashMap<>();
        for (int n: nums) {
            counter.put(n, counter.getOrDefault(n, 0)+1);
        }


        for (Map.Entry <Integer, Integer> entry: counter.entrySet()) {
            int x = entry.getKey();
            int val = entry.getValue();
            if (k > 0 && counter.containsKey(x + k)) {
                result++;
            } else if (k == 0 && val > 1) {
                result++;
            }
        }
        return result;
    }
}
