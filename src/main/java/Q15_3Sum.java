import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * Duration: 90mins Medium
 * Runtime: 68 ms, faster than 30.06% of Java online submissions for 3Sum.
 * Memory Usage: 43.6 MB, less than 56.56% of Java online submissions for 3Sum.
 * O(n^2 * log(n))
 */
public class Q15_3Sum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int zeroIndex = Arrays.binarySearch(nums, 0);
        if(zeroIndex < 0) {
            zeroIndex = zeroIndex * -1 - 1;
        }
        else {
            while(zeroIndex - 1 >= 0 && nums[zeroIndex - 1] == 0) {
                zeroIndex--;
            }
        }
        System.out.println(zeroIndex);
        if(zeroIndex >= nums.length || nums == null || nums.length == 0) {
            return result;
        }
        int previousLeft = Integer.MAX_VALUE;
        int previousRight = Integer.MIN_VALUE;
        for(int i = 0; i < zeroIndex; i++) {
            if(nums[i] == previousLeft) {
                continue;
            }
            previousLeft = nums[i];
            previousRight = Integer.MIN_VALUE;
            for(int j = nums.length - 1; j >= zeroIndex; j--) {
                if(nums[j] == previousRight) {
                    continue;
                }
                previousRight = nums[j];
                int tmp = 0 - nums[i] - nums[j];
                int tIndex = Arrays.binarySearch(nums, i + 1, j, tmp);
                if(tIndex > 0 && tmp == nums[tIndex]) {
                    result.add(Arrays.asList(nums[i], tmp, nums[j]));
                }
            }
        }
        if(nums[zeroIndex] == 0) {
            int zeroCount = 0;
            while(zeroIndex < nums.length && nums[zeroIndex] == 0) {
                zeroCount++;
                zeroIndex++;
            }
            if(zeroCount > 2) {
                result.add(Arrays.asList(0, 0, 0));
            }

        }
        return result;
    }
}