import java.util.Arrays;

/***
 * 20mins
 */
public class Q329_LongestINcreasingPathInAMatrix {
    int[][] mt;
    int[][] memo;
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        mt = matrix;
        memo = new int[mt.length][mt[0].length];
        for(int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        int result = 0;
        for(int i = 0; i < memo.length; i++) {
            for(int j = 0; j < memo[0].length; j++) {
                result = Math.max(result, rec(i, j, Integer.MIN_VALUE));
            }
        }
        int[][] v = memo;
        return result;
    }


    public int rec(int i, int j, int prev) {
        if(i < 0 || i >= mt.length || j < 0 || j >= mt[0].length || mt[i][j] <= prev) {
            return 0;
        }
        if(memo[i][j] > -1) {
            return memo[i][j];
        }
        int left = rec(i, j - 1, mt[i][j]);
        int right = rec(i, j + 1, mt[i][j]);
        int up = rec(i - 1, j, mt[i][j]);
        int down = rec(i + 1, j, mt[i][j]);
        memo[i][j] = 1 + Math.max(Math.max(left, right), Math.max(up, down));
        return memo[i][j];
    }
}
