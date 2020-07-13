import java.util.List;

/***
 * 7mins, one shot AC (one wrong answer due to the question didn't specify no result value.
 * Runtime: 12 ms, faster than 95.03% of Java online submissions for Longest Word in Dictionary through Deleting.
 * Memory Usage: 40.7 MB, less than 37.85% of Java online submissions for Longest Word in Dictionary through Deleting.
 */
public class Q524_LongestWordInDictionaryThroughDeleting {
    public String findLongestWord(String s, List<String> d) {
        d.sort((o1, o2) -> {
            return o1.length() - o2.length() == 0 ? o1.compareTo(o2) : o2.length() - o1.length();
        });

        for(int i = 0; i < d.size(); i++) {
            int h = 0;
            int j = 0;
            for(j = 0; j < d.get(i).length(); j++) {
                h = s.indexOf(d.get(i).charAt(j), h);
                if(h == -1) {
                    break;
                }
                h++;
            }
            if(j == d.get(i).length()) {
                return d.get(i);
            }
        }
        return "";
    }
}
