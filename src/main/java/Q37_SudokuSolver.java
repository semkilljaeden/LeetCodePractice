import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

/***
 * 3Hour Hard, debugging one small bug
 * Runtime: 2 ms, faster than 99.32% of Java online submissions for Sudoku Solver.
 * Memory Usage: 38.6 MB, less than 29.27% of Java online submissions for Sudoku Solver.
 */
public class Q37_SudokuSolver {
    char[][] board;
    int[][] setList = new int[3][9];
    ArrayList<Cell> emptyCell = new ArrayList<>();
    public void solveSudoku(char[][] board) {
        this.board = board;
        loadSudokuSet(setList[0], setList[1], setList[2]);
        find(0);
    }

    boolean find(int index) {
        if(index == emptyCell.size()) {
            return true;
        }

        Cell c = emptyCell.get(index);
        int indexS = c.i / 3 * 3 + c.j / 3;
        int mask = setList[0][c.i] | setList[1][c.j] | setList[2][indexS];
        if(mask == 511) {
            return false;
        }
        for(int i = 0; i < 9; i++) {
            int tmp = 1 << i;
            if((tmp | mask) > mask) {
                setList[0][c.i] += tmp;
                setList[1][c.j] += tmp;
                setList[2][indexS] += tmp;
                if(find(index + 1)) {
                    board[c.i][c.j] = (char)('1' + i);
                    return true;
                }
                setList[0][c.i] -= tmp;
                setList[1][c.j] -= tmp;
                setList[2][indexS] -= tmp;
            }
        }
        return false;
    }


    class Cell {
        int i;
        int j;

        public Cell(int first, int second) {
            this.i = first;
            this.j = second;
        }

        public int getWeight() {
            return setList[0][i] + setList[1][j] + setList[2][i / 3 * 3 + j / 3];
        }
    }


    public void loadSudokuSet(int[] row, int[] col, int[] sqr) {
        Arrays.fill(row, 0);
        Arrays.fill(col, 0);
        Arrays.fill(sqr, 0);
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board.length; j++) {
                if(board[i][j] == '.') {
                    emptyCell.add(new Cell(i, j));
                    continue;
                }
                row[i] |= 1 << (board[i][j] - '1');
                col[j] |= 1 << (board[i][j] - '1');
                sqr[i / 3 * 3 + j / 3] |= 1 << (board[i][j] - '1');
            }
        }
    }

}
