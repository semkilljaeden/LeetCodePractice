/***
 * 10mins
 * Runtime: 7 ms, faster than 14.23% of Java online submissions for String Compression.
 * Memory Usage: 39.3 MB, less than 48.56% of Java online submissions for String Compression.
 */
public class Q443_StringCompression {
    public int compress(char[] chars) {
        int count = 1;
        int s = 1;
        int f = 1;
        for(f = 1; f < chars.length; f++) {
            if(chars[f] == chars[f - 1]) {
                count++;
                continue;
            }
            else {
                if(count > 1) {
                    String c = count + "";
                    for(int i = 0; i < c.length(); i++) {
                        chars[s++] = c.charAt(i);
                    }
                }
                chars[s++] = chars[f];
                count = 1;
            }
        }
        if(count > 1) {
            String c = count + "";
            for(int i = 0; i < c.length(); i++) {
                chars[s++] = c.charAt(i);
            }
        }
        return s;
    }
}
