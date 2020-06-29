/**
 * 7mins funny recursion
 *
 * out of limit
 */
public class Q62_UniquePath {
    int result = 0;
    int m;
    int n;
    public int uniquePaths(int m, int n) {
        this.m = m;
        this.n = n;
        recurse(0, 0);
        return result;
    }

    public void recurse(int i, int j) {
        if(i == m - 1 && j == n - 1) {
            result++;
            return;
        }
        if(i >= m || j >= n) {
            return;
        }
        recurse(i + 1, j);
        recurse(i, j + 1);
    }
}
