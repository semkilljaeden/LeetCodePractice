/***
 * 10mins medium
 * greedy
 * Runtime: 1 ms, faster than 99.06% of Java online submissions for Jump Game.
 * Memory Usage: 41.6 MB, less than 43.66% of Java online submissions for Jump Game.
 */
public class Q55_JumpGameV2 {
    public boolean canJump(int[] nums) {
        int max = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i > max) {
                return false;
            }
            else {
                max = Math.max(max, i + nums[i]);
            }
            if(max >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}
