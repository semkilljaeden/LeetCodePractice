/***
 * 16mins easy
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search Insert Position.
 * Memory Usage: 39.2 MB, less than 57.44% of Java online submissions for Search Insert Position.
 */

public class Q35_SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        if(nums[nums.length - 1] < target) {
            return nums.length;
        }
        if(nums[0] >= target) {
            return 0;
        }
        int left = 0;
        int right = nums.length - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            System.out.println(mid);
            if(nums[mid] == target) {
                right = mid - 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return nums[mid] < target ? mid + 1: mid;
    }
}
