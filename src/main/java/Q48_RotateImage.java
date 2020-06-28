/***
 * bad algorithm, too troublesome to implement
 */
public class Q48_RotateImage {
    public void rotate(int[][] matrix) {
        int layer = (matrix.length - 1 )/ 2;
        int[] tmp = new int[matrix.length];
        int[] prev = new int[matrix.length];
        int[] tmptmp;
        for(int layerIndex = 0; layerIndex < layer; layerIndex++) {
            int left = layerIndex;
            int right = matrix.length - layerIndex;
            for(int i = left; i < right; i++) {
                prev[i] = matrix[right - i - 1][left];
            }
            for(int i = left; i < right; i++) {
                tmp[i] = matrix[left][i];
                matrix[left][i] = prev[i];
            }
            tmptmp = prev;
            prev = tmp;
            tmp = tmptmp;
            for(int i = left; i < right; i++) {
                tmp[i] = matrix[i][right - 1];
                matrix[i][right - 1] = prev[i];
            }
            tmptmp = prev;
            prev = tmp;
            tmp = tmptmp;
            for(int i = left; i < right; i++) {
                tmp[i] = matrix[right - 1][right - i - 1];
                matrix[right - 1][right - i - 1] = prev[i];
            }
            tmptmp = prev;
            prev = tmp;
            tmp = tmptmp;
            for(int i = left; i < right; i++) {
                matrix[right - i - 1][left] = prev[i];
            }
        }
    }


}
