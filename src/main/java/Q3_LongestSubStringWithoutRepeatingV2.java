import java.util.HashMap;

/***
 * 8mins
 */
public class Q3_LongestSubStringWithoutRepeatingV2 {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) {
            return 0;
        }
        char[] ss = s.toCharArray();
        HashMap<Character, Integer> map = new HashMap();
        int start = 0;
        int end = 0;
        int result = 1;
        map.put(ss[0], 0);
        for(int i = 1; i < ss.length; i++) {
            if(map.containsKey(ss[i])) {
                int x = map.get(ss[i]);
                for(; start <= x; start++) {
                    map.remove(ss[start]);
                }

            }
            end = i;
            map.put(ss[i], i);
            result = Math.max(result, end - start + 1);
        }
        return result;
    }
}
