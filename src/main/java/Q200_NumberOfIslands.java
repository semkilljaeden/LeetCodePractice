import java.util.HashMap;

/***
 * 20mins medium
 * Runtime: 2 ms, faster than 59.72% of Java online submissions for Number of Islands.
 * Memory Usage: 45.2 MB, less than 7.64% of Java online submissions for Number of Islands.
 */
public class Q200_NumberOfIslands {
    char[][] grid;
    int[][] mask;
    public int numIslands(char[][] grid) {
        //boundary check
        if(grid.length == 0) {
            return 0;
        }
        int count = 0;
        this.grid = grid;
        mask = new int[grid.length][grid[0].length];
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(mask[i][j] == 1 || grid[i][j] == '0') {
                    continue;
                }
                count++;
                infect(i, j);
            }
        }
        return count;
    }

    public void infect(int i, int j) {
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0' || mask[i][j] == 1) {
            return;
        }
        mask[i][j] = 1;
        infect(i - 1, j);
        infect(i + 1, j);
        infect(i, j - 1);
        infect(i, j + 1);

    }
}
