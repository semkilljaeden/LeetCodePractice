import java.lang.reflect.Array;
import java.util.Arrays;

/***
 * 11mins medium
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find First and Last Position of Element in Sorted Array.
 * Memory Usage: 44.5 MB, less than 6.12% of Java online submissions for Find First and Last Position of Element in Sorted Array.
 */
public class Q34_FindFandLElementInSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid;
        int[] result = new int[2];
        Arrays.fill(result, -1);
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                result[0] = mid;
            }
            if(nums[mid] >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = 0;
        right = nums.length - 1;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                result[1] = mid;
            }
            if(nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
}
