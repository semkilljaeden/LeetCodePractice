import java.util.HashMap;

/***
 * 30mins hard
 * Runtime: 12 ms, faster than 86.02% of Java online submissions for Frog Jump.
 * Memory Usage: 50.5 MB, less than 7.63% of Java online submissions for Frog Jump.
 */
public class Q403_FrogJump {
    int[] s;
    HashMap<Integer, Integer> map;
    int vic;
    int memo[][];
    public boolean canCross(int[] stones) {
        s = stones;
        map = new HashMap();
        for(int i = 0; i < s.length; i++) {
            map.put(s[i], i);
        }
        vic = s[s.length - 1];
        memo = new int[s.length][s.length + 1];
        return rec(0, 1);
    }

    public boolean rec(int idx, int jp) {
        if(memo[idx][jp] != 0) {
            return memo[idx][jp] == 1;
        }
        int ppos = s[idx] + jp;
        if(ppos == vic) {
            return true;
        }
        if(!map.containsKey(ppos)) {
            memo[idx][jp] = -1;
            return false;
        }
        int iidx = map.get(ppos);
        if(iidx == idx) {
            memo[idx][jp] = -1;
            return false;
        }
        boolean result = rec(iidx, jp)
                || rec(iidx, jp - 1)
                || rec(iidx, jp + 1);
        memo[idx][jp] = result ? 1 : -1;
        return result;
    }
}
