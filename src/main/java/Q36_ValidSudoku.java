import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.function.Supplier;
import java.util.stream.Stream;

/***
 * 30mins algorithm 2mins, implementation problem 28mins
 * Runtime: 13 ms, faster than 27.70% of Java online submissions for Valid Sudoku.
 * Memory Usage: 39.9 MB, less than 39.97% of Java online submissions for Valid Sudoku.
 */
public class Q36_ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character> base = new HashSet<Character>(Arrays.asList('1','2','3','4','5','6','7','8','9'));
        Supplier<HashSet<Character>> p = () -> new HashSet(base);
        HashSet<Character>[] vList = Stream.generate(p).limit(9).toArray(HashSet[]::new);
        HashSet<Character>[] hList = Stream.generate(p).limit(9).toArray(HashSet[]::new);
        HashSet<Character>[] sList = Stream.generate(p).limit(9).toArray(HashSet[]::new);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if((vList[i].remove(board[i][j]) &&
                hList[j].remove(board[i][j]) &&
                sList[(i / 3) * 3 + j / 3].remove(board[i][j])) == false) {
                    return false;
                }
            }
        }
        return true;
    }
}
