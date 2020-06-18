import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * Duration: 30mins Medium
 * Runtime: 28 ms, faster than 46.42% of Java online submissions for 3Sum.
 * Memory Usage: 43.2 MB, less than 85.98% of Java online submissions for 3Sum.
 * O(n^2)
 */
public class Q15_3SumGreedy {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int previousLeft = Integer.MAX_VALUE;
        int previousMid;
        int previousRight;
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] == previousLeft) {
                continue;
            }
            previousLeft = nums[i];
            int mid = i + 1;
            int right = nums.length - 1;
            previousMid = Integer.MIN_VALUE;
            previousRight = Integer.MIN_VALUE;
            for(int j = nums.length - 1; j > i + 1; j--) {
                while(right - mid > 0) {
                    if(nums[mid] == previousMid) {
                        mid++;
                        continue;
                    }
                    if(nums[mid] == previousRight) {
                        right--;
                        continue;
                    }
                    int v = nums[i] + nums[mid] + nums[right];
                    if(v == 0) {
                        result.add(Arrays.asList(nums[i], nums[mid], nums[right]));
                        previousMid = nums[mid];
                        previousRight = nums[right];
                        mid++;
                        right--;
                    }
                    else if(v < 0) {
                        mid++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
}