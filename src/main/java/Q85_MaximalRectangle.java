import java.util.LinkedList;

/**
 * 1hr 6mins
 * Runtime: 9 ms, faster than 39.38% of Java online submissions for Maximal Rectangle.
 * Memory Usage: 43.3 MB, less than 23.17% of Java online submissions for Maximal Rectangle.
 * Brutal force
 *
 * the best solution is to merge matrix as histogram, then use O(n) histogram algorithm to calculate row by row
 * overall is O(n^2)
 */
public class Q85_MaximalRectangle {
    char[][] matrix;
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int result = 0;
        this.matrix = matrix;
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[0].length; j++) {
                result = Math.max(result, getMaxSize(i, j));
            }
        }
        return result;
    }

    public int getMaxSize(int i, int j) {
        if(matrix[i][j] == '0') {
            return 0;
        }
        int iEnd = i;
        int jEnd = j;
        int result = 0;
        while(iEnd < matrix.length && matrix[iEnd][j] == '1') {
            iEnd++;
        }
        while(jEnd < matrix[0].length && matrix[i][jEnd] == '1') {
            jEnd++;
        }
        for(int x = i; x < iEnd; x++) {
            for(int y = j; y < jEnd; y++ ) {
                if(matrix[x][y] == '0') {
                    jEnd = y;
                }
                else {
                    result = Math.max((x - i + 1) * (y - j + 1), result);
                }
            }
        }
        return result;
    }
}
