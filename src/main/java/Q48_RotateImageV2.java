/***
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate Image.
 * Memory Usage: 39.9 MB, less than 19.62% of Java online submissions for Rotate Image.
 */
public class Q48_RotateImageV2 {
    public void rotate(int[][] matrix) {
        int i = 0;
        int j = matrix.length - 1;
        while(i < j) {
            swap(matrix[i], matrix[j]);
            i++;
            j--;
        }
        int tmp;
        for(i = 1; i < matrix.length; i++) {
            for(j = i; j < matrix.length; j++) {
                tmp = matrix[i - 1][j];
                matrix[i - 1][j] = matrix[j][i - 1];
                matrix[j][i - 1] = tmp;
            }
        }
    }

    public void swap(int[] i1, int[] i2) {
        int tmp;
        for(int i = 0; i < i1.length; i++) {
            tmp = i2[i];
            i2[i] = i1[i];
            i1[i] = tmp;
        }
    }


}
