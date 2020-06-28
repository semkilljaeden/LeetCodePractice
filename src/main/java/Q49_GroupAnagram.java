import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/***
 * 20mins
 * Runtime: 7 ms, faster than 60.51% of Java online submissions for Group Anagrams.
 * Memory Usage: 42.5 MB, less than 60.10% of Java online submissions for Group Anagrams.
 */
public class Q49_GroupAnagram {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> r = new ArrayList();
        HashMap<String, List<String>> result = new HashMap();
        for(int i = 0; i < strs.length; i++) {
            String key = bucketSort(strs[i]);
            List<String> t = result.getOrDefault(key, new ArrayList<String>());
            t.add(strs[i]);
            result.put(key, t);
        }
        for(List i : result.values()) {
            r.add(i);
        }
        return r;
    }

    /***
     * can use prime list as hash factor to save time of bucketSort
     * int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
     * @param s
     * @return
     */
    public String bucketSort(String s) {
        int[] bucket = new int[26];
        for(int i = 0; i < s.length(); i++) {
            bucket[s.charAt(i) - 'a'] += 1;
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < bucket[i]; j++) {
                sb.append((char)(i + 'a'));
            }
        }
        return sb.toString();
    }
}
