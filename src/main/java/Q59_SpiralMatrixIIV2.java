/***
 * 17ms avoid long if else, too easy to make mistake
 *Runtime: 0 ms, faster than 100.00% of Java online submissions for Spiral Matrix II.
 * Memory Usage: 37.5 MB, less than 41.89% of Java online submissions for Spiral Matrix II.
 */
public class Q59_SpiralMatrixIIV2 {
    public int[][] generateMatrix(int n) {
        int left = 0;
        int right = n;
        int[][] result = new int[n][n];
        int value = 1;
        while(left < right) {
            for(int i = left; i < right; i++) {
                result[left][i] = value++;
            }
            for(int i = left + 1; i < right; i++) {
                result[i][right - 1] = value++;
            }
            for(int i = right - 2; i >= left; i--) {
                result[right - 1][i] = value++;
            }
            for(int i = right - 2; i >= left + 1; i--) {
                result[i][left] = value++;
            }
            left++;
            right--;
        }
        return result;
    }
}
