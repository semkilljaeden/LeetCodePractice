/***
 * 17mins second best solution
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Product of Array Except Self.
 * Memory Usage: 48.3 MB, less than 33.16% of Java online submissions for Product of Array Except Self.
 */
public class Q238_ProductOfArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int[] a = new int[nums.length];
        a[0] = nums[0];
        int[] b = new int[nums.length];
        for(int i = 1; i < nums.length; i++) {
            a[i] = a[i - 1] * nums[i];
        }
        b[nums.length - 1] = nums[nums.length - 1];
        for(int i = nums.length - 2; i >= 0; i--) {
            b[i] = b[i + 1] * nums[i];
        }

        for(int i = 0; i < nums.length; i++) {
            int left = i == 0 ? 1 : a[i - 1];
            int right = i == nums.length - 1 ? 1 : b[i + 1];
            result[i] = left * right;
        }
        return result;
    }
}
