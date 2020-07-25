import java.util.ArrayList;
import java.util.List;

/***
 * 39mins medium
 * Runtime: 13 ms, faster than 56.51% of Java online submissions for Generalized Abbreviation.
 * Memory Usage: 44.6 MB, less than 59.63% of Java online submissions for Generalized Abbreviation.
 */
public class Q320_GeneralizedAbbreviation {
    List<String> result = new ArrayList();
    int size;
    String word;
    StringBuilder sb;
    public List<String> generateAbbreviations(String word) {
        sb = new StringBuilder();
        size = word.length();
        this.word = word;
        char[] c = word.toCharArray();
        for(int i = 0; i <= size; i++) {
            rec(c, i, 0);
        }
        return result;
    }

    public void rec(char[] c, int count, int pos) {
        if(count == 0) {
            sb.setLength(0);
            count = 0;
            for(int i = 0; i < c.length; i++) {
                if(c[i] == '1') {
                    count++;
                }
                else {
                    if(count > 0) {
                        sb.append(count);
                        count = 0;
                    }
                    sb.append(c[i]);
                }
            }
            if(count > 0) {
                sb.append(count);
            }
            result.add(sb.toString());
            return;
        }
        if(pos > size - count) {
            return;
        }
        for(int i = pos; i < size && count > 0; i++) {
            char tmp = c[i];
            c[i] = '1';
            rec(c, count - 1, i + 1);
            c[i] = tmp;
        }
    }
}
