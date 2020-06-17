import java.util.Arrays;
import java.util.stream.IntStream;

/***
 * untime: 2 ms 93.11%
 * Memory Usage: 39.6 MB  38.88%
 */
public class Q10_RegularExpressionDP {
    public boolean isMatch(String s, String p) {
        int[][] memo = new int[s.length() + 1][p.length() + 1];
        IntStream.range(0, memo.length).forEach(i -> Arrays.fill(memo[i], 0));
        return match(s, 0, p, 0, memo);
    }
    public boolean match(String s, int sIndex, String p, int pIndex, int[][] memo) {
        if(memo[sIndex][pIndex] != 0) {
            return memo[sIndex][pIndex] == 2;
        }
        if(sIndex >= s.length()) {
            if(pIndex >= p.length()) {
                memo[sIndex][pIndex] = 2;
                return true;
            }
            else {
                while(pIndex <= p.length() - 1) {
                    if(p.charAt(pIndex) == '*') {
                        memo[sIndex][pIndex] = 1;
                        return false;
                    }
                    else if(pIndex + 1 >= p.length() || p.charAt(pIndex + 1) != '*') {
                        memo[sIndex][pIndex] = 1;
                        return false;
                    }
                    pIndex += 2;
                }
                memo[sIndex][pIndex] = 2;
                return true;
            }
        }
        else if(p.length() <= pIndex) {
            memo[sIndex][pIndex] = 1;
            return false;
        }
        else{
            boolean isLocalMatch = p.charAt(pIndex) == '.' || p.charAt(pIndex) == s.charAt(sIndex);
            boolean result;
            if(pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*') {
                 result = (isLocalMatch &&
                        (match(s, sIndex + 1, p, pIndex + 2, memo)
                                || match(s, sIndex + 1, p, pIndex, memo)))
                        || match(s, sIndex, p, pIndex + 2, memo);
            }
            else {
                result = isLocalMatch && match(s, sIndex + 1, p, pIndex + 1, memo);
            }
            memo[sIndex][pIndex] = result ? 2 : 1;
            return result;
        }

    }
}
