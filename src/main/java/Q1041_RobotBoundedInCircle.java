import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 40mins, medium did not get the question in the first time.
 * Runtime: 1 ms, faster than 36.27% of Java online submissions for Robot Bounded In Circle.
 * Memory Usage: 39.2 MB, less than 10.07% of Java online submissions for Robot Bounded In Circle.
 */
public class Q1041_RobotBoundedInCircle {
    public boolean isRobotBounded(String instructions) {
        char[] s = instructions.toCharArray();
        Tuple prev = new Tuple(0, 0);
        Tuple d = new Tuple(1, 0);
        int n = 0;
        while(n++ < 4) {
            for(int i = 0; i < s.length; i++) {
                if(s[i] == 'G') {
                    prev = prev.add(d);
                }
                if(s[i] == 'L') {
                    if(Math.abs(d.a) == 1) {
                        d.b = -d.a;
                        d.a = 0;
                    }
                    else if(d.a == 0) {
                        d.a = d.b;
                        d.b = 0;
                    }
                }
                else if(s[i] == 'R') {
                    if(Math.abs(d.a) == 1) {
                        d.b = d.a;
                        d.a = 0;
                    }
                    else if(d.a == 0) {
                        d.a = -d.b;
                        d.b = 0;
                    }
                }
            }
            if(prev.a == 0 && prev.b == 0 && d.a == 1 && d.b == 0) {
                return true;
            }
        }
        return false;
    }

    public class Tuple {
        int a;
        int b;
        public Tuple(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public Tuple add(Tuple t) {
            return new Tuple(a + t.a, b + t.b);
        }
        public String toString() {
            return a + "|" + b;
        }
    }
}
