import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/***
 * 12 mins
 * Runtime: 1 ms, faster than 83.42% of Java online submissions for N-Queens II.
 * Memory Usage: 36.3 MB, less than 49.08% of Java online submissions for N-Queens II.
 */
public class Q52_NQueensII {
    boolean[] row;
    boolean[] col;
    boolean[] leftDiag;
    boolean[] rightDiag;
    int result = 0;
    int n;
    public int totalNQueens(int n) {
        row = new boolean[n];
        col = new boolean[n];
        leftDiag = new boolean[n * 2 - 1];
        rightDiag = new boolean[n * 2 - 1];
        Arrays.fill(row, false);
        Arrays.fill(col, false);
        Arrays.fill(leftDiag, false);
        Arrays.fill(rightDiag, false);
        this.n = n;
        return result;
    }

    private void recurse(int index) {
        for(int i = 0; i < n; i++) {
            if(!row[index] && !col[i]
            && !leftDiag[n - (index - i) - 1]
            && !rightDiag[index + i]) {
                if(index == n - 1) {
                    result++;
                    return;
                }
                row[index] = true;
                col[i] = true;
                leftDiag[n - (index - i) - 1] = true;
                rightDiag[index + i] = true;
                recurse(index + 1);
                row[index] = false;
                col[i] = false;
                leftDiag[n - (index - i) - 1] = false;
                rightDiag[index + i] = false;
            }
        }
    }


}
