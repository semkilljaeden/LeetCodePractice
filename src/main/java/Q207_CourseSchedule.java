import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/***
 * 1hr 10mins medium
 * Runtime: 233 ms, faster than 5.03% of Java online submissions for Course Schedule.
 * Memory Usage: 40.9 MB, less than 13.85% of Java online submissions for Course Schedule.
 */
public class Q207_CourseSchedule {
    HashMap<Integer, List<Integer>> el;
    HashSet<Integer> sp;
    public boolean canFinish(int n, int[][] p) {
        el = new HashMap();
        HashSet<Integer> rsp = new HashSet();
        for(int i = 0; i < p.length; i++) {
            List<Integer> l = el.getOrDefault(p[i][0], new ArrayList());
            l.add(p[i][1]);
            el.putIfAbsent(p[i][0], l);
            if(p[i][0] != p[i][1]) {
                rsp.add(p[i][0]);
            }
        }
        sp = new HashSet();
        for(int i = 0; i < n; i++) {
            if(rsp.contains(i)) {
                continue;
            }
            sp.add(i);
        }
        for(int i : rsp) {
            if(sp.contains(i)) {
                continue;
            }
            HashSet<Integer> visited = new HashSet();
            visited.add(i);
            if(!rec(el.get(i), visited)) {
                return false;
            }
        }
        return true;
    }

    public boolean rec(List<Integer> p, HashSet<Integer> visited) {
        for(int i = 0; i < p.size(); i++) {
            if(sp.contains(p.get(i))) {
                continue;
            }
            if(visited.contains(p.get(i))) {
                return false;
            }
            visited.add(p.get(i));
            boolean r = rec(el.get(p.get(i)), visited);
            visited.remove(p.get(i));
            if(!r) {
                return false;
            }
        }
        return true;
    }
}
