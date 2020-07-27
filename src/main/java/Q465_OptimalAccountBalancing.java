import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/***
 * 1:30hr, out of time limit
 */
public class Q465_OptimalAccountBalancing {
    public int minTransfers(int[][] t) {
        HashMap<Integer, Integer> acc = new HashMap();
        if(t.length == 0 || t[0].length == 0) {
            return 0;
        }
        for(int i = 0; i < t.length; i++) {
            int s = acc.getOrDefault(t[i][0], 0);
            int r = acc.getOrDefault(t[i][1], 0);

            int us = s - t[i][2];
            int ur = r + t[i][2];
            acc.put(t[i][0], us);
            acc.put(t[i][1], ur);
        }
        int[] d = new int[acc.size()];
        int i = 0;
        for(Map.Entry<Integer, Integer> e : acc.entrySet()) {
            d[i++] = e.getValue();
        }
        return rec(0, d);
    }

    public int rec(int idx, int[] d) {
        while (idx < d.length && d[idx] == 0)
            idx++;
        if(idx == d.length) {
            return 0;
        }
        int result = Integer.MAX_VALUE;
        for(int i = idx + 1; i < d.length; i++) {
            if(d[i] * d[idx] >= 0) {
                continue;
            }
            int tmp = d[i];
            d[i] = d[i] + d[idx];
            result = Math.min(result, 1 + rec(idx + 1, d));
            d[i] = tmp;
        }
        return result;
    }
}
