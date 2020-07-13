import java.util.LinkedHashMap;
import java.util.Map;

/***
 * 22mins. best solution
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find Minimum in Rotated Sorted Array.
 * Memory Usage: 40 MB, less than 5.40% of Java online submissions for Find Minimum in Rotated Sorted Array.
 */
public class Q153_FindMinimumInRotatedSortedArray {
    public int findMin(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums[0] < nums[nums.length - 1]) {
            return nums[0];
        }
        int left = 0;
        int right = nums.length - 1; //to be decided
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid == nums.length - 1) {
                return nums[nums.length - 1];
            }
            if(mid > 0 && nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) {
                return nums[mid];
            }
            if(nums[mid] > nums[nums.length - 1]) { //left side
                left = mid + 1;
            }
            else if(nums[mid] < nums[0]) {
                right = mid - 1;
            }
            /***
             * Can use this approach to do a more neat boundary check
             *       // if the mid element is greater than its next element then mid+1 element is the smallest
             *       // This point would be the point of change. From higher to lower value.
             *       if (nums[mid] > nums[mid + 1]) {
             *         return nums[mid + 1];
             *       }
             *
             *       // if the mid element is lesser than its previous element then mid element is the smallest
             *       if (nums[mid - 1] > nums[mid]) {
             *         return nums[mid];
             *       }
             */
        }
        return 0;
    }
}
