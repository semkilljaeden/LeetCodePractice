import java.util.Arrays;

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Unique Paths.
 * Memory Usage: 36.6 MB, less than 21.14% of Java online submissions for Unique Paths.
 */
public class Q62_UniquePathDP {
    int result = 0;
    int m;
    int n;
    int[][] mn;
    public int uniquePaths(int m, int n) {
        this.m = m;
        this.n = n;
        mn = new int[m + 1][n + 1];
        Arrays.fill(mn[0], 0);
        for(int i = 0; i < m; i++) {
            mn[i][0] = 0;
        }
        mn[0][1] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                mn[i][j] = mn[i - 1][j] + mn[i][j - 1];
            }
        }
        return mn[m][n];
    }
}
