/***
 * 23 mins
 * Runtime: 2 ms, faster than 99.73% of Java online submissions for Max Area of Island.
 * Memory Usage: 39.5 MB, less than 81.97% of Java online submissions for Max Area of Island.
 */
public class Q695_MaxAreaOfIsland {
    public int maxAreaOfIsland(int[][] grid) {
        //boundary check
        if(grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        visited = new boolean[grid.length][grid[0].length];
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int result = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                count = 0;
                rec(i, j);
                result = Math.max(result, count);
            }
        }
        return result;
    }
    int count;
    int m;
    int n;
    int[][] grid;
    boolean[][] visited;
    public void rec(int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if(grid[i][j] != 0) {
            count++;
            rec(i - 1, j);
            rec(i + 1, j);
            rec(i, j - 1);
            rec(i, j + 1);
        }
        return;
    }
}
