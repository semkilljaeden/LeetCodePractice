import java.util.ArrayList;
import java.util.List;

/***
 * 2hr went into the wrong direction.
 *
 * DFS does not have overlapping sub problem!!!
 */
public class Q79_WordSearch {
    char[][] board;
    String word;
    public boolean exist(char[][] board, String word) {
        //TODO input boundary check
        this.board = board;
        this.word = word;
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(recurse(i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean recurse(int i, int j, int wPos, boolean[][] visited) {
        if(wPos == word.length()) {
            return true;
        }
        if(i < 0 || i == board.length || j < 0 || j == board[0].length) {
            return false;
        }
        if(visited[i][j]) {
            return false;
        }
        if(board[i][j] != word.charAt(wPos)) {
            return false;
        }
        visited[i][j] = true;
        boolean result = recurse(i - 1, j, wPos + 1, visited) ||
                recurse(i + 1, j, wPos + 1, visited) ||
                recurse(i, j - 1, wPos + 1, visited) ||
                recurse(i, j + 1, wPos + 1, visited);
        visited[i][j] = false;
        return result;
    }
}
