import java.util.Arrays;

/***
 * 17mins 1shot AC
 * Runtime: 1 ms, faster than 96.31% of Java online submissions for Set Matrix Zeroes.
 * Memory Usage: 41.2 MB, less than 40.24% of Java online submissions for Set Matrix Zeroes.
 *
 * can use bitmap to get constant extra space
 */
public class Q73_SetMatrixZeroes {
    public void setZeroes(int[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int[] m = new int[matrix.length];
        int[] n = new int[matrix[0].length];// boundary check
        for(int i = 0; i < m.length; i++) {
            for(int j = 0; j < n.length; j++) {
                if(matrix[i][j] == 0) {
                    m[i] = 1;
                    n[j] = 1;
                }
            }
        }

        for(int i = 0; i < m.length; i++) {
            if(m[i] == 1) {
                Arrays.fill(matrix[i], 0);
            }
        }
        for(int i = 0; i < n.length; i++) {
            if(n[i] == 1) {
                for(int j = 0; j < m.length; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}
