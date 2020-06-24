import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

/***
 * Runtime: 8 ms, faster than 88.83% of Java online submissions for Substring with Concatenation of All Words.
 * Memory Usage: 39.6 MB, less than 96.67% of Java online submissions for Substring with Concatenation of All Words..
 *
 * sliding window, if somewhere in the middle is x, then any window starts before the x cannot be free of x.
 * |---x-|
 *   |-x
 *      |-----|
 *
 *      Greedy Algorithm
 */
public class Q30_SubstringWithConcatenationV2 {
    List<Integer> result = new ArrayList<>();
    public List<Integer> findSubstring(String s, String[] words) {
        if(words == null || words.length == 0 || words[0] == null || words[0].equals("")) {
            return result;
        }
        Map<String ,Long> wordSet = Arrays.stream(words).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        int count;
        int wordLength = words[0].length();
        int window = wordLength * words.length;
        String tmp;
        for(int i = 0; i < wordLength; i++) {
            int start = i;
            while(start + window <= s.length()) {
                Map<String ,Integer> seen = new HashMap<>();
                int j = start + window;
                boolean isMatch = true;
                for(j = j - wordLength; j >= start; j -= wordLength) {
                    String sub = s.substring(j, j + wordLength);
                    int value = seen.getOrDefault(sub, 0) + 1;
                    long c = wordSet.getOrDefault(sub, 0L);
                    if(c > 0 && value<= c) {
                        seen.put(sub, value);
                    }
                    else {
                        break;

                    }
                }
                if(j == start - wordLength) {
                    result.add(start);
                }

                start = (j + wordLength > start + wordLength ? j + wordLength : start + wordLength);
            }

        }
        return result;
    }
}
