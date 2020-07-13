/***
 * 24mins medium
 * Runtime: 1 ms, faster than 99.97% of Java online submissions for Minimum Size Subarray Sum.
 * Memory Usage: 39.3 MB, less than 80.55% of Java online submissions for Minimum Size Subarray Sum.
 */
public class Q209_MinimumSizeSubarraySum {
    public int minSubArrayLen(int s, int[] nums) {
        //boundary case, s = 0, s = 1, numsl = 0
        if(s == 0 || nums.length == 0) {
            return 0;
        }
        int size = 0;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(sum < s && end < nums.length) {
            sum += nums[end++];
        }
        if(sum < s) {
            return 0;
        }
        size = end - start;
        while(end <= nums.length) {
            sum -= nums[start];
            start++;
            while(sum < s && end < nums.length) {
                sum += nums[end++];
            }
            if(sum < s) {
                break;
            }
            size = Math.min(size, end - start);
            if(size == 1) {
                return 1;
            }
        }
        return size;
    }
}
