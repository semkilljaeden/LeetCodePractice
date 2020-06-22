/***
 * 5mins easy
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted Array.
 * Memory Usage: 41.4 MB, less than 49.79% of Java online submissions for Remove Duplicates from Sorted Array.
 */
public class RemoveDuplicatesFromSorted {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        int index = 0;
        int prev = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] == prev) {
                continue;
            }
            else {
                nums[++index] = nums[i];
                prev = nums[i];
            }
        }
        return index + 1;
    }
}
