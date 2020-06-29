/***
 * 7mins
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Unique Paths II.
 * Memory Usage: 38.4 MB, less than 71.32% of Java online submissions for Unique Paths II.
 */
public class Q63_UniquePathII {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid.length == 0 || obstacleGrid[0].length == 0) {
            return 0;
        }
        int[][] memo = new int[obstacleGrid.length + 1][obstacleGrid[0].length + 1];
        memo[0][1] = 1;
        for(int i = 1; i < obstacleGrid.length + 1; i++) {
            for(int j = 1; j < obstacleGrid[0].length + 1; j++) {
                if(obstacleGrid[i - 1][j - 1] == 0) {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                }
                else {
                    memo[i][j] = 0;
                }
            }
        }
        return memo[obstacleGrid.length][obstacleGrid[0].length];
    }
}
