import java.util.ArrayDeque;
import java.util.Deque;

/***
 * 15mins. easy medium
 * Runtime: 4 ms, faster than 92.62% of Java online submissions for Asteroid Collision.
 * Memory Usage: 39.9 MB, less than 81.13% of Java online submissions for Asteroid Collision.
 * Next challenges:
 */
public class Q_AsteroidCollision {
    public int[] asteroidCollision(int[] a) {
        if(a.length == 0) {
            return null;
        }
        //0?
        Deque<Integer> d = new ArrayDeque();
        for(int i = 0; i < a.length; i++) {
            if(a[i] >= 0) {
                d.add(a[i]);
            }
            else {
                while(d.size() > 0 && d.peekLast() >= 0 && d.peekLast() < -a[i]) {
                    d.removeLast();
                }
                if(d.size() > 0 && d.peekLast() == -a[i]) {
                    d.removeLast();
                }
                else if(d.size() > 0 && d.peekLast() >= 0 && d.peekLast() > -a[i]) {
                    continue;
                }
                else {
                    d.add(a[i]);
                }
            }
        }
        int[] result = new int[d.size()];
        int i = 0;
        while(d.size() > 0) {
            result[i++] = d.removeFirst();
        }
        return result;
    }
}
