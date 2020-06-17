/***
 * Runtime: 6 ms 100%
 * Memory Usage: 38.3 MB
 */
public class Q9_PalindromeNumber {
    public boolean isPalindrome(int x) {
        int mirror = 0;
        int tmp = x;
        while(tmp > 0) {
            mirror *= 10;
            mirror += tmp % 10;
            tmp /= 10;
        }
        return x == mirror;
    }
}
