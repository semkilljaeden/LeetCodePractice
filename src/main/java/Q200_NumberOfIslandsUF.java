/***
 * 20mins medium
 * Runtime: 11 ms, faster than 6.28% of Java online submissions for Number of Islands.
 * Memory Usage: 45.4 MB, less than 6.11% of Java online submissions for Number of Islands.
 */
public class Q200_NumberOfIslandsUF {
    char[][] grid;
    public int numIslands(char[][] grid) {
        //boundary check
        if(grid.length == 0) {
            return 0;
        }
        int count = 0;
        this.grid = grid;
        UF uf = new UF();
        int nr = grid.length;
        int nc = grid[0].length;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    if (r - 1 >= 0 && grid[r-1][c] == '1') {
                        uf.union(r, c, r - 1, c);
                    }
                    if (r + 1 < nr && grid[r+1][c] == '1') {
                        uf.union(r, c, r + 1, c);
                    }
                    if (c - 1 >= 0 && grid[r][c-1] == '1') {
                        uf.union(r, c, r, c - 1);
                    }
                    if (c + 1 < nc && grid[r][c+1] == '1') {
                        uf.union(r, c, r, c + 1);
                    }
                }
            }
        }
        return uf.count;
    }

    class UF {
        int[] parent;
        int[] size;
        int count;
        public UF() {
            parent = new int[grid.length * grid[0].length];
            size = new int[grid.length * grid[0].length];
            count = 0;
            for(int i = 0; i < grid.length; i++) {
                for(int j = 0; j < grid[0].length; j++) {
                    if(grid[i][j] == '1') {
                        parent[i * grid[0].length + j] = i * grid[0].length + j;
                        size[i * grid[0].length + j] = 1;
                        count++;
                    }
                }
            }
        }

        public int find(int i, int j) {
            int pos = i * grid[0].length + j;
            if(parent[pos] == pos) {
                return pos;
            }
            while(parent[pos] != pos) {
                //path compression
                parent[pos] = parent[parent[pos]];
                pos = parent[pos];
            }
            return parent[pos];
        }

        public void union(int i, int j, int ii, int ij) {
            int ip = find(i, j);
            int iip = find(ii, ij);
            if(ip == iip) {
                return;
            }
            if(size[ip] > size[iip]) {
                parent[iip] = ip;
            }
            else {
                parent[ip] = iip;
            }
            count--;
        }
    }
}
