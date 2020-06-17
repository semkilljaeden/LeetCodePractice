import java.util.HashMap;

/***
 * Runtime: 3 ms  92.192%
 * Memory Usage: 39.6 MB
 */
public class Q3_LongestSubStringWithoutRepeating {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) {
            return 0;
        }
        HashMap<Character, Integer> visited = new HashMap<>();
        int start = 0;
        int result = 1;
        char[] list = s.toCharArray();
        for(int i = 0; i < list.length; i++) {
            if(visited.containsKey(list[i])) {
                int temp = i - start;
                start = visited.get(list[i]) + 1 > start ? visited.get(list[i]) + 1 : start;
                result = temp > result ? temp : result;
            }
            visited.put(list[i], i);
        }
        return result > list.length - start ? result : list.length - start;
    }
}
