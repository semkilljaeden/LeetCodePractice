import java.util.Arrays;

/***
 * 20mins
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Jump Game II.
 * Memory Usage: 41.4 MB, less than 59.91% of Java online submissions for Jump Game II.
 */
public class Q45_JumpGameIIGreedy {
    public int jump(int[] nums) {
        if(nums.length == 1 || nums.length == 0) {
            return 0;
        }
        int th = nums[0];
        int sc = 1;
        int next = nums[0];
        int i = 0;
        while(next < nums.length - 1) {
            for(;i <= th; i++) {
                next = Math.max(next, i + nums[i]);
            }
            th = next;
            sc++;
        }
        return sc;
    }
}
