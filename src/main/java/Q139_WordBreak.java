import java.util.HashSet;
import java.util.List;

/***
 * 18mins medium
 * Runtime: 1 ms, faster than 99.35% of Java online submissions for Word Break.
 * Memory Usage: 39.5 MB, less than 56.62% of Java online submissions for Word Break.
 */
public class Q139_WordBreak {
    HashSet<String> dic;
    int max = Integer.MIN_VALUE;
    int[] memo;
    public boolean wordBreak(String s, List<String> wordDict) {
        dic = new HashSet(wordDict);
        for(int i = 0; i < wordDict.size(); i++) {
            if(wordDict.get(i).length() > max) {
                max = wordDict.get(i).length();
            }
        }
        memo = new int[s.length() + 1];
        return rec(s, 0);
    }

    public boolean rec(String s, int pos) {
        if(memo[pos] != 0) {
            return memo[pos] == 1;
        }
        if(pos >= s.length()) {
            return true;
        }
        memo[pos] = -1;
        for(int i = 1; i < max + 1; i++) {
            if(pos + i > s.length()) {
                break;
            }
            boolean tmp = dic.contains(s.substring(pos, pos + i)) && rec(s, pos + i);
            if(tmp) {
                memo[pos] = 1;
                break;
            }
        }
        return memo[pos] == 1;
    }
}
