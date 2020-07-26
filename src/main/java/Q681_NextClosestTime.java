import java.util.HashSet;

/***
 * 25mins
 * Runtime: 8 ms, faster than 44.46% of Java online submissions for Next Closest Time.
 * Memory Usage: 39.2 MB, less than 16.88% of Java online submissions for Next Closest Time.
 */
public class Q681_NextClosestTime {
    public String nextClosestTime(String time) {
        String[] t = time.split(":");
        HashSet<Character> s = new HashSet();
        for(int i = 0; i < time.length(); i++) {
            s.add(time.charAt(i));
        }
        while(true) {
            inc(t);
            if(isValid(t, s)) {
                return t[0] + ":" + t[1];
            }
        }
    }

    public void inc(String[] time) {
        int a = Integer.valueOf(time[1]) + 1;
        int ca = 0;
        if(a == 60) {
            ca = 1;
            a = 0;
        }
        time[1] = intToString(a);
        a = Integer.valueOf(time[0]) + ca;
        if(a == 24) {
            a = 0;
        }
        time[0] = intToString(a);

    }

    public String intToString(int a) {
        if(a < 10) {
            return "0" + a;
        }
        else {
            return "" + a;
        }
    }

    public boolean isValid(String[] time, HashSet<Character> s) {
        String x = "" + time[0] + time[1];
        for(int i = 0; i < x.length(); i++) {
            if(!s.contains(x.charAt(i))) {
                return false;
            }
        }
        return true;
    }
}
