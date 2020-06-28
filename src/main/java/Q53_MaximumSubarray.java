/***
 * 1hr
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Maximum Subarray.
 * Memory Usage: 39.4 MB, less than 66.18% of Java online submissions for Maximum Subarray.
 */
public class Q53_MaximumSubarray {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        int min = nums[0];
        int max = nums[0];
        for(int i = 1; i < nums.length; i++) {
            nums[i] = nums[i] + nums[i - 1];
            if(nums[i] > max) {
                max = nums[i];
            }
            if(nums[i] < min) {
                min = nums[i];
            }
        }
        return max - min;
    }
}
