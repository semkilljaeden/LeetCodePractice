/***
 * 8mins easy
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Element.
 * Memory Usage: 37.9 MB, less than 67.95% of Java online submissions for Remove Element.
 *
 */
public class Q26_RemoveElement {
    public int removeElement(int[] nums, int val) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        int index = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != val) {
                if(index != i) {
                    nums[index] = nums[i];
                }
                index++;
            }
        }
        return index;
    }
}
