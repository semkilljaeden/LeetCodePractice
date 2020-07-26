/***
 * 20mins
 * Runtime: 29 ms, faster than 29.42% of Java online submissions for Find the Smallest Divisor Given a Threshold.
 * Memory Usage: 42.1 MB, less than 27.89% of Java online submissions for Find the Smallest Divisor Given a Threshold.
 */
public class Q1283_FindtheSmallestDivisorGivenaThreshold {
    public int smallestDivisor(int[] nums, int t) {
        if(nums.length == 0) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
        }
        int left = 1;
        int right = max;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(can(nums, t, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return can(nums, t, left) ? left : left + 1;
    }

    public boolean can(int[] nums, int threshold, int div) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += divide(nums[i], div);
        }
        return sum <= threshold;
    }

    public int divide(int i, int j) {
        return (int) Math.ceil((double) i / (double) j);
    }
}
