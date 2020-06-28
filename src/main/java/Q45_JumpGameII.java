import java.util.Arrays;

/***
 * 1 hr debugging silly bug out of time
 */
public class Q45_JumpGameII {
    public int jump(int[] nums) {
        if(nums.length == 0 || nums.length == 1) {
            return 0;
        }
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        memo[memo.length - 1] = 0;
        recurse(nums, 0);
        return memo[0];
    }
    int[] memo;
    public int recurse(int[] nums, int index) {
        long step = Integer.MAX_VALUE;
        for(int i = nums[index]; i >= 1; i--) {
            if(index + i > nums.length - 1) {
                continue;
            }
            else if(memo[index + i] < 0) {
                recurse(nums, index + i);
            }
            if(memo[index + i] != Integer.MAX_VALUE) {
                step = Math.min(step, 1 + memo[index + i]);
            }

        }
        memo[index] = (int) step;
        return memo[index];
    }
}
