import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

/***
 * 44mins silly bug
 */
public class Q317_ShortestDistanceFromAllBuildings {
    public int shortestDistance(int[][] grid) {
        if(grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 1 || grid[i][j] == 2) {
                    continue;
                }
                boolean[][] visited = new boolean[grid.length + 2][grid[0].length + 2];
                for(int a = 0; a < visited.length; a++) {
                    visited[a][0] = true;
                    visited[a][visited[0].length - 1] = true;
                }
                Arrays.fill(visited[0], true);
                Arrays.fill(visited[visited.length - 1], true);
                Deque<Pair> queue = new ArrayDeque();
                queue.addLast(new Pair(i, j));
                int level = 0;
                int cc = 1;
                int ccount = 0;
                while(queue.size() > 0) {
                    int ccc = 0;
                    for(int x = 0; x < cc; x++) {
                        Pair p = queue.removeFirst();
                        int ii = p.i;
                        int jj = p.j;
                        if(visited[ii + 1][jj + 1] || grid[ii][jj] == 2) {
                        }
                        else if(grid[ii][jj] == 1) {
                            sum += level;
                            ccount++;
                        }
                        else {
                            queue.addLast(new Pair(ii + 1, jj));
                            ccc++;
                            queue.addLast(new Pair(ii - 1, jj));
                            ccc++;
                            queue.addLast(new Pair(ii, jj + 1));
                            ccc++;
                            queue.addLast(new Pair(ii, jj - 1));
                            ccc++;
                        }
                        visited[ii + 1][jj + 1] = true;

                    }
                    System.out.println();
                    cc = ccc;
                    level++;
                }
                if(ccount == count) {
                    min = Math.min(min, sum);
                }
                sum = 0;
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min;
    }

    public class Pair {
        int i;
        int j;

        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}
