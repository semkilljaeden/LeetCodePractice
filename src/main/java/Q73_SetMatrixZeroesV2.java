import java.util.Arrays;

/***
 * 17mins 1shot AC
 * Runtime: 1 ms, faster than 96.31% of Java online submissions for Set Matrix Zeroes.
 * Memory Usage: 41.2 MB, less than 40.24% of Java online submissions for Set Matrix Zeroes.
 *
 * if do matrix vertical traversal, next time create a sepetate method to avoid bug
 */
public class Q73_SetMatrixZeroesV2 {
    public void setZeroes(int[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        boolean fr = false;
        boolean fc = false;
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                fc = true;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                fr = true;
                break;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                Arrays.fill(matrix[i], 0);
            }

        }
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(fr) {
            Arrays.fill(matrix[0], 0);
        }
        if(fc) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
