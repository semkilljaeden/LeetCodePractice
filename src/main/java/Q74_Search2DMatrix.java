import java.util.Arrays;

/***
 * 26mins. not one shot AC but it is because i am not familar with Array.binarySearch which returns -(insert point) -1
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search a 2D Matrix.
 * Memory Usage: 42 MB, less than 9.23% of Java online submissions for Search a 2D Matrix.
 */
public class Q74_Search2DMatrix {
    int[][] matrix;
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        this.matrix = matrix;
        int index = verticalBinarySearch(target);
        int result = Arrays.binarySearch(matrix[index], target);
        return result < matrix[0].length && matrix[index][result] == target;
    }

    public int verticalBinarySearch(int i) {
        int left = 0;
        int right = matrix.length;
        int mid = left + (right - left) / 2;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(i == matrix[mid][0]) {
                return mid;
            }
            else if(i < matrix[mid][0]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if(mid == matrix.length || matrix[mid][0] > i) {
            mid--;
        }
        return mid;
    }
}
