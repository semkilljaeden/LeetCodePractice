/***
 * 44mins medium small bug
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Spiral Matrix II.
 * Memory Usage: 37.1 MB, less than 87.40% of Java online submissions for Spiral Matrix II.
 *
 */
public class Q59_SpiralMatrixII {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int value = 1;
        int layer = 0;
        int i = 0;
        int j = 0;
        int left = layer;
        int right = n - layer;
        while(value <= (n * n)) {
            result[i][j] = value++;
            if(i == left) {
                if(j < right - 1) {
                    j++;
                }
                else {
                    i++;
                }
            }
            else if(j == right - 1) {
                if(i < right - 1) {
                    i++;
                }
                else {
                    j--;
                }
            }
            else if(i == right - 1) {
                if(j > left) {
                    j--;
                }
                else {
                    i--;
                }
            }
            else if(j == left) {
                if(i > left) {
                    i--;
                }
            }

            if(i == left && j == left) {
                layer++;
                left = layer;
                right = n - layer;
                i = left;
                j = left;
            }

        }
        return result;
    }
}
