import java.util.Arrays;
import java.util.PriorityQueue;

/***
 * 4hr, total failure....
 *
 */
public class Q407_TrappingRainWaterII {
    public int trapRainWater(int[][] heightMap) {
        if(heightMap.length == 0 || heightMap[0].length == 0) {
            return 0;
        }
        int[][] map = heightMap;
        int m = map.length;
        int n = map[0].length;
        PriorityQueue<int[]> wall = new PriorityQueue<int[]>((o1, o2) -> {
            return o1[2] - o2[2];
        });
        boolean[][] visited = new boolean[m + 2][n + 2];
        for(int i = 0; i < visited.length; i++) {
            visited[i][0] = true;
            visited[i][visited[0].length - 1] = true;
        }
        Arrays.fill(visited[0], true);
        Arrays.fill(visited[visited.length - 1], true);
        for(int i = 0; i < m; i++) {
            wall.add(new int[]{i, 0, map[i][0]});
            visited[i + 1][1] = true;
            wall.add(new int[]{i, n - 1, map[i][n - 1]});
            visited[i + 1][n] = true;
        }
        for(int i = 0; i < n; i++) {
            wall.add(new int[]{0, i, map[0][i]});
            visited[1][i + 1] = true;
            wall.add(new int[]{m - 1, i, map[m - 1][i]});
            visited[m][i + 1] = true;
        }
        int result = 0;
        int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(wall.size() > 0) {
            int[] e = wall.poll();
            int k;
            for(int[] d : dir) {
                int i = e[0] + d[0];
                int j = e[1] + d[1];
                if(visited[i + 1][j + 1]) {
                    continue;
                }
                k = map[i][j];
                result += e[2] - k > 0 ? e[2] - k : 0;
                k = Math.max(k, e[2]);
                wall.add(new int[] {i, j, k});
                visited[i + 1][j + 1] = true;
            }

        }
        return result;
    }
}
