import java.util.ArrayList;
import java.util.List;

/***
 * 1hr 20mins hard
 * Runtime: 1 ms, faster than 53.42% of Java online submissions for Text Justification.
 * Memory Usage: 37.3 MB, less than 95.17% of Java online submissions for Text Justification.
 */
public class Q68_TextJustification {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int count = 0;
        int index = 0;
        StringBuilder sb = new StringBuilder(maxWidth);
        List<String> result = new ArrayList();
        while(index < words.length) {
            int i = index;
            count = 0;
            int curL = 0;
            int wordLength = 0;
            sb.setLength(0);
            int h = 0;
            while(index < words.length && curL + words[index].length() + h <= maxWidth) {                       //need to check end case
                curL += words[index].length() + h;
                wordLength += words[index].length();
                index++;
                if(h == 0) {
                    h++;
                }
                count++;
            }
            //padding
            String[] pad = getPad(count, maxWidth - wordLength);
            int cu = 0;
            for(int x = i; x < index; x++) {
                sb.append(words[x]);
                if(cu < pad.length) {
                    sb.append(pad[cu]);
                    cu++;
                }
            }
            i = index;
            result.add(sb.toString());
        }
        //modify last row to left justified
        sb.setLength(0);
        String last = result.remove(result.size() - 1);
        boolean isWord = false;
        for(int i = 0; i < last.length(); i++) {
            char c = last.charAt(i);
            if(c != ' ') {
                isWord = true;
                sb.append(c);
            }
            else if(isWord) {
                sb.append(c);
                isWord = false;
            }
            else {
                continue;
            }
        }
        int l = sb.length();
        while(l++ < maxWidth) {
            sb.append(' ');
        }
        result.add(sb.toString().substring(0, maxWidth));
        return result;

    }

    public String[] getPad(int wordCount, int remain) {
        String[] r;
        if(wordCount == 1) {
            r =  new String[1];
            r[0] = generatePad(remain);
            return r;
        }
        r = new String[wordCount - 1];
        for(int i = 0;i < r.length && remain > 0; i++) {
            r[i] = " ";
            remain--;
        }
        while(remain > 0) {
            for(int i = 0;i < r.length && remain > 0; i++) {
                r[i] = r[i] + ' ';
                remain--;
            }
        }

        return r;
    }

    public String generatePad(int size) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < size; i++) {
            sb.append(' ');
        }
        return sb.toString();
    }
}
