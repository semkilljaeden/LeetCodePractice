import java.util.Arrays;

/***
 * Start Time: 14:32
 * End Time: 14:43
 *
 * Runtime: 3 ms, faster than 98.19% of Java online submissions for 3Sum Closest.
 * Memory Usage: 38.9 MB, less than 83.68% of Java online submissions for 3Sum Closest.
 *
 */


public class Q16_3SumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int mid;
        int right;
        int result = Integer.MAX_VALUE;
        int sum;
        int diff = Integer.MAX_VALUE;
        int tmp;
        for(int i = 0; i < nums.length; i++) {
            mid = i + 1;
            right = nums.length - 1;
            while (mid < right) {
                sum = nums[i] + nums[mid] + nums[right];
                if(sum > target) {
                    right--;
                }
                else if(sum < target) {
                    mid++;
                }
                else {
                    return target;
                }
                tmp = Math.abs(sum - target);
                if(tmp < diff) {
                    result = sum;
                    diff = tmp;
                }
            }
        }
        return result;
    }
}
