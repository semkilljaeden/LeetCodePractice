import java.util.HashMap;
import java.util.HashSet;

/***
 * 1:45 Algorithm got correct, but the detail requirement got wrong
 */
public class Q76_MinimumWindowSubstring {
    class Solution {
        public String minWindow(String s, String t) {
            if(s.equals("") || t.equals("")) {
                return "";
            }
            HashMap<Character, Integer> ttMap = new HashMap();
            for(int i = 0; i < t.length(); i++) {
                ttMap.put(t.charAt(i), ttMap.getOrDefault(t.charAt(i), 0) + 1);
            }
            HashMap<Character, Integer> tMap = new HashMap(ttMap);
            int i = 0;
            int j = 0;
            HashMap<Character, Integer> wMap = new HashMap();
            for(; j < s.length();) {
                if(ttMap.containsKey(s.charAt(j))) {
                    ttMap.put(s.charAt(j), ttMap.get(s.charAt(j)) - 1);
                    wMap.put(s.charAt(j), wMap.getOrDefault(s.charAt(j), 0) + 1);
                }
                if(ttMap.values().stream().allMatch(v -> v <= 0)) {
                    j++;
                    break;
                }
                j++;
            }
            if(!ttMap.values().stream().allMatch(v -> v <= 0) && j == s.length()) {
                return "";
            }
            int resultI = 0;
            int resultJ = j;
            int resultSize = j;
            i = 1;
            for(; i < s.length(); i++) {
                char pr = s.charAt(i - 1);
                if(wMap.containsKey(pr)) {
                    int v = wMap.get(pr) - 1;
                    if(v < tMap.get(pr)) {
                        while(j < s.length()) {
                            char c = s.charAt(j);
                            if(c == pr) {
                                v += 1;
                                j++;
                                break;
                            }
                            else if(wMap.containsKey(c)) {
                                wMap.put(c, wMap.get(c) + 1);
                            }
                            j++;
                        }
                        if(v < tMap.get(pr)) {
                            i--;
                            break;
                        }
                    }
                    else {
                        wMap.put(pr, wMap.get(pr) - 1);
                    }
                }
                System.out.println(i + "  " + j);
                if(resultSize > j - i) {
                    resultI = i;
                    resultJ = j;
                    resultSize = j - i;
                }
            }
            return s.substring(resultI, resultJ);

        }

    }
}
