import java.util.Arrays;

/***
 * 10mins medium
 * Runtime: 2 ms, faster than 88.03% of Java online submissions for Minimum Path Sum.
 * Memory Usage: 42.5 MB, less than 27.46% of Java online submissions for Minimum Path Sum.
 *
 * remove array fills and use boundary check is faster
 */
public class Q64_MinimumPathSum {
    public int minPathSum(int[][] grid) {
        //edge input check
        if(grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int[][] memo = new int[grid.length + 1][grid[0].length + 1];
        Arrays.fill(memo[0], Integer.MAX_VALUE);
        for(int i = 0; i <= grid.length; i++) {
            memo[i][0] = Integer.MAX_VALUE;
        }
        memo[1][0] = 0;
        for(int i = 1; i <= grid.length; i++) {
            for(int j = 1; j <= grid[0].length; j++) {
                memo[i][j] = Math.min(memo[i - 1][j], memo[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return memo[grid.length][grid[0].length];
    }
}
