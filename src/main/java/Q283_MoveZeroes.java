/***
 * 3mins
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Move Zeroes.
 * Memory Usage: 42.4 MB, less than 5.26% of Java online submissions for Move Zeroes.
 */
public class Q283_MoveZeroes {
    public void moveZeroes(int[] nums) {
        int f = 0;
        int s = 0;
        for(f = 0; f < nums.length; f++) {
            if(nums[f] == 0) {
                continue;
            }
            if(s < f) {
                nums[s] = nums[f];
                nums[f] = 0;
            }
            s++;
        }
    }
}
