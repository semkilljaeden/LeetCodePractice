/***
 * 18mins easy
 *Runtime: 1 ms  91.70%
 * Memory Usage: 36.8 MB
 */
public class Q38_CountAndSay {

    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder();

        String prevString = "1";
        for(int i = 1; i < n; i++) {
            sb.setLength(0);
            int count = 1;
            char prev = prevString.charAt(0);
            for(int j = 1; j < prevString.length(); j++) {
                char c = prevString.charAt(j);
                if(c == prev) {
                    count++;
                }
                else {
                    sb.append(count).append(prev);
                    count = 1;
                    prev = c;
                }
            }
            sb.append(count).append(prev);
            prevString = sb.toString();
        }
        return prevString;
    }


}
