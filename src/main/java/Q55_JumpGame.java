import java.util.LinkedList;
import java.util.Queue;

/***
 * 10mins medium
 * dfs, out of limit
 */
public class Q55_JumpGame {
    int[] nums;
    public boolean canJump(int[] nums) {
        this.nums = nums;
        return recurse(0);
    }

    public boolean recurse(int index) {
        if(index >= nums.length - 1) {
            return true;
        }
        else if(index < nums.length - 1 && nums[index] == 0) {
            return false;
        }
        for(int i = nums[index]; i >= 1; i--) {
            if(recurse(index + i)) {
                return true;
            }
        }
        return false;
    }
}
