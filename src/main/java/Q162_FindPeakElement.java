/***
 * 15mins medium
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find Peak Element.
 * Memory Usage: 39.6 MB, less than 7.01% of Java online submissions for Find Peak Element.
 */
public class Q162_FindPeakElement {
    public int findPeakElement(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        int left = 0;
        int right = nums.length - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            long ll = mid - 1 < 0 ? Integer.MIN_VALUE - 1L : nums[mid - 1];
            long rr = mid + 1 >= nums.length ? Integer.MIN_VALUE - 1L : nums[mid + 1];
            if(ll < nums[mid] && rr <nums[mid]) {
                return mid;
            }
            else if(ll <= nums[mid]  && rr >= nums[mid]) {
                left = mid + 1;
            }
            else if(ll >= nums[mid] && rr <= nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
}
