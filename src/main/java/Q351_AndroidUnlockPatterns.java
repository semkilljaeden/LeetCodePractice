/***
 * 1hr, but with multiple optimization. accepted
 * Runtime: 14 ms, faster than 63.33% of Java online submissions for Android Unlock Patterns.
 * Memory Usage: 39.7 MB, less than 5.63% of Java online submissions for Android Unlock Patterns.
 */
public class Q351_AndroidUnlockPatterns {
    int[][][] memo = new int[10][1 << 9][10];
    public int numberOfPatterns(int m, int n) {
        Bm s = new Bm();
        int result = 0;
        for(int i = 0; i < memo.length; i++) {
            for(int j = 0; j < memo[0].length; j++) {
                for(int z = 0; z < memo[0][0].length; z++) {
                    memo[i][j][z] = -1;
                }
            }
        }
        for(int x = m; x <= n; x++) {
            for(int i = 1; i <= 9; i++) {
                s.add(i);
                result += rec(i, s, x - 1);
                s.remove(i);
            }
        }
        return result;
    }

    public int rec(int x, Bm visited, int step) {
        if(step == 0) {
            return 1;
        }
        int m = visited.m;
        if(memo[x][m][step] != -1) {
            return memo[x][m][step];
        }
        memo[x][m][step] = 0;
        for(int i = 1; i <= 9; i++) {
            if(x == i || !can(x, i, visited)) {
                continue;
            }
            visited.add(i);
            memo[x][m][step] += rec(i, visited, step - 1);
            visited.remove(i);
        }
        return memo[x][m][step];
    }

    public boolean can(int x, int y, Bm visited) {
        if(visited.contains(y)) {
            return false;
        }
        int l = x <= y ? x : y;
        int m = x > y ? x : y;
        boolean r =
                !(m == 9 && l == 1 && !visited.contains(5)
                        || m == 7 && l == 3 && !visited.contains(5)
                        || m == 3 && l == 1 && !visited.contains(2)
                        || m == 9 && l == 3 && !visited.contains(6)
                        || m == 9 && l == 7 && !visited.contains(8)
                        || m == 7 && l == 1 && !visited.contains(4)
                        || m == 6 && l == 4 && !visited.contains(5)
                        || m == 8 && l == 2 && !visited.contains(5));
        return r;
    }

    private class Bm {
        int m = 0;

        public void add(int i) {
            m |= (1 << (i - 1));
        }

        public void remove(int i) {
            if((m | 1 << (i - 1)) == m) {
                m -= (1 << (i - 1));
            }
        }

        public boolean contains(int i) {
            return (m | 1 << (i - 1)) == m;
        }
    }
}
