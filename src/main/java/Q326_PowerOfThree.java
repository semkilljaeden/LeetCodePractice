/***
 * 15mins visited various solution
 * Runtime: 10 ms, faster than 100.00% of Java online submissions for Power of Three.
 * Memory Usage: 39.3 MB, less than 53.06% of Java online submissions for Power of Three.
 */
public class Q326_PowerOfThree {
    public boolean isPowerOfThree(int n) {
        int max = 1162261467;//(int)Math.pow(3, (int) (Math.log(Integer.MAX_VALUE) / Math.log(3)));
        return n > 0 && max % n == 0;


    }
}
