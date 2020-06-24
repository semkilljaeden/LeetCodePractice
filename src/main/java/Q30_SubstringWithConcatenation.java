import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

/***
 * 43mins, Brute Force
 * Runtime: 122 ms, faster than 51.03% of Java online submissions for Substring with Concatenation of All Words.
 * Memory Usage: 40.5 MB, less than 33.93% of Java online submissions for Substring with Concatenation of All Words.
 */
public class Q30_SubstringWithConcatenation {
    List<Integer> result = new ArrayList<>();
    public List<Integer> findSubstring(String s, String[] words) {
        if(words == null || words.length == 0 || words[0] == null || words[0].equals("")) {
            return result;
        }
        Map<String ,Long> wordSet = Arrays.stream(words).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        int count;
        int wordLength = words[0].length();
        String tmp;
        for(int i = 0; i < s.length() - words.length * wordLength + 1; i++) {
            count = 0;
            Map<String ,Long> tmpWordSet = new HashMap<>(wordSet);
            while(count < words.length) {
                tmp = s.substring(i + count * wordLength, i + (count + 1) * wordLength);
                if(!tmpWordSet.containsKey(tmp)) {
                    break;
                }
                else {
                    Long v = tmpWordSet.get(tmp);
                    System.out.println(i + count * wordLength + "  " + v + "   " + tmp);
                    if(v == 1) {
                        tmpWordSet.remove(tmp);
                    }
                    else {
                        tmpWordSet.put(tmp, v - 1);
                    }
                }
                count++;
            }
            if(count == words.length) {
                result.add(i);
            }
        }
        return result;
    }
}
