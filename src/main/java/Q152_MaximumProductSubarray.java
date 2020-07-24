/***
 * failed medium
 *
 * Runtime: 3 ms, faster than 25.62% of Java online submissions for Maximum Product Subarray.
 * Memory Usage: 40.5 MB, less than 5.19% of Java online submissions for Maximum Product Subarray.
 */
public class Q152_MaximumProductSubarray {
    public int maxProduct(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        int result = nums[0];
        int max = result;
        int min = result;
        for(int i = 1; i < nums.length; i++) {
            int tm = Math.min(nums[i], Math.min(max * nums[i], min * nums[i]));
            max = Math.max(nums[i], Math.max(max * nums[i], min * nums[i]));
            min = tm;
            result = Math.max(result, max);
        }
        return result;
    }
}
