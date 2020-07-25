/***
 * 10mins medium
 * Runtime: 8 ms, faster than 42.77% of Java online submissions for Search a 2D Matrix II.
 * Memory Usage: 45.3 MB, less than 18.56% of Java online submissions for Search a 2D Matrix II.
 */
public class Q240_Search2DMatrixII {
    public boolean searchMatrix(int[][] matrix, int target) {
        //boundary check
        if(matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        for(int i = 0; i < matrix.length; i++) {
            if(matrix[i][0] > target) {
                return false;
            }
            else if(matrix[i][0] == target) {
                return true;
            }
            else {
                if(matrix[i][b(matrix[i], target)] == target) {
                    return true;
                }
            }
        }
        return false;

    }

    public int b(int[] a, int t) {
        int left = 0;
        int right = a.length - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(a[mid] == t) {
                return mid;
            }
            else if(a[mid] > t) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if(a[mid] > t && mid > 0) {
            mid--;
        }
        return mid;
    }
}
