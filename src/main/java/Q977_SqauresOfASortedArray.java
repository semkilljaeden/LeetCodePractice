/***
 * 18mins hard easy
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Squares of a Sorted Array.
 * Memory Usage: 41.3 MB, less than 36.14% of Java online submissions for Squares of a Sorted Array.
 */
public class Q977_SqauresOfASortedArray {
    public int[] sortedSquares(int[] A) {
        if(A.length == 0) {
            return null;
        }
        int[] result = new int[A.length];
        int p = 0;
        while(p < A.length && A[p] < 0) {
            p++;
        }
        int i = 0;
        int left;
        int right;
        if(p>= 0 && p <A.length && A[p] == 0) {
            result[i++] = 0;
            left = p - 1;
            right = p + 1;
        }
        else {
            left = p - 1;
            right = p;
        }
        while(left >= 0 || right < A.length) {
            if(left >= 0 && right < A.length) {
                int l = A[left] * A[left];
                int r = A[right] * A[right];
                if(l <= r) {
                    result[i++] = l;
                    left--;
                }
                else {
                    result[i++] = r;
                    right++;
                }
            }
            else if(left >= 0) {
                result[i++] = A[left] * A[left];
                left--;
            }
            else {
                result[i++] = A[right] * A[right];
                right++;
            }
        }
        return result;
    }
}
