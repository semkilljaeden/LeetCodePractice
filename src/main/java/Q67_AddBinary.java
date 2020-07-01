/***
 * 14mins easy, but one shot AC
 * runtime: 2 ms, faster than 76.96% of Java online submissions for Add Binary.
 * Memory Usage: 38.2 MB, less than 75.69% of Java online submissions for Add Binary.
 */
public class Q67_AddBinary {
    public String addBinary(String a, String b) {
        int reminder = 0;
        String s = "";
        String l = "";
        if(a.length() >= b.length()) {
            l = a;
            s = b;
        }
        else {
            l = b;
            s = a;
        }
        int si = s.length() - 1;
        int li = l.length() - 1;
        StringBuilder sb = new StringBuilder();
        int tmp = s.charAt(si) + l.charAt(li) - '0' * 2;
        reminder = tmp >> 1;
        tmp %= 2;
        sb.append(tmp);
        si--;
        li--;
        while(si >= 0) {
            tmp = s.charAt(si) + l.charAt(li) - '0' * 2 + reminder;
            reminder = tmp >> 1;
            tmp %= 2;
            sb.append(tmp);
            si--;
            li--;
        }
        while(li >= 0) {
            tmp = l.charAt(li) - '0' + reminder;
            reminder = tmp >> 1;
            tmp %= 2;
            sb.append(tmp);
            li--;
        }
        if(reminder == 1) {
            sb.append(reminder);
        }
        return sb.reverse().toString();
    }
}
