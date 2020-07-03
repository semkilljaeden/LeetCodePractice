/**
 * 5:30
 * can only be O(n)
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search in Rotated Sorted Array II.
 * Memory Usage: 39.6 MB, less than 26.48% of Java online submissions for Search in Rotated Sorted Array II.
 */
public class Q81_SearchInRotatedSortedArrayII {
    public boolean search(int[] nums, int target) {
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == target) {
                return true;
            }
        }
        return false;
    }
}
