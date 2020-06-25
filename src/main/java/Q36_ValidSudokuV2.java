import java.util.Arrays;
import java.util.HashSet;
import java.util.function.Supplier;
import java.util.stream.Stream;

/***
 * bitmap
 * Runtime: 1 ms, faster than 100.00% of Java online submissions for Valid Sudoku.
 * Memory Usage: 39.3 MB, less than 85.32% of Java online submissions for Valid Sudoku.
 */
public class Q36_ValidSudokuV2 {
    public boolean isValidSudoku(char[][] board) {
        int[] vList = new int[9];
        int[] hList = new int[9];
        int[] sList = new int[9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int mask = 1 << board[i][j] - '1';
                int index = i / 3 * 3 + j / 3;
                int v = vList[i] | mask;
                int h = hList[j] | mask;
                int s = sList[index] | mask;
                if(!(vList[i] < v &&
                        hList[j] < h &&
                        sList[index] < s)) {
                    return false;
                }
                vList[i] = v;
                hList[j] = h;
                sList[index] = s;
            }
        }
        return true;
    }
}
