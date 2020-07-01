/***
 * 13mins easy
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Climbing Stairs.
 * Memory Usage: 38.2 MB, less than 6.12% of Java online submissions for Climbing Stairs.
 */
public class Q70_ClimbingStairs {
    int x;
    int[] memo;
    public int climbStairs(int n) {
        x = n;
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        memo = new int[n + 1];
        memo[n] = 0;
        memo[n - 1] = 1;
        memo[n - 2] = 2;
        for(int i = n - 3; i >= 0; i--) {
            memo[i] = memo[i + 1] + memo[i + 2];
        }
        return memo[0];
    }
}
