/***
 * 47mins. gone into a wrong direction. 28.4% acceptance rate. a really hard medium question
 * Runtime: 4 ms, faster than 91.69% of Java online submissions for Remove K Digits.
 * Memory Usage: 39.1 MB, less than 89.88% of Java online submissions for Remove K Digits.
 */
public class Q402_RemoveKDigits {
    public String removeKdigits(String num, int k) {
        if(k == 0) {
            return num;
        }
        StringBuilder sb = new StringBuilder();
        char[] c = num.toCharArray(); //not really necessary, could just use charAt to save space
        for(int i = 0; i < c.length; i++) {
            char x = 0;
            if(sb.length() > 0) {
                x = sb.charAt(sb.length() - 1);
            }
            while(x > c[i] && k > 0 && sb.length() > 0) {
                sb.setLength(sb.length() - 1);
                if(sb.length() > 0) {
                    x = sb.charAt(sb.length() - 1);
                }
                k--;
            }
            sb.append(c[i]);
        }
        while(k > 0) {
            sb.setLength(sb.length() - 1);
            k--;
        }
        //to remove the leading zeroes. can be optimized away.
        String tmp = sb.toString();
        c = tmp.toCharArray();
        sb.setLength(0);
        boolean flag = true;
        for(int i = 0; i < c.length; i++) {
            if(c[i] > '0') {
                flag = false;
            }
            if(flag) {
                continue;
            }
            sb.append(c[i]);
        }
        if(sb.length() == 0) {
            sb.append(0);
        }
        return sb.toString();
    }
}
