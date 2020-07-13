import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.PriorityQueue;

/***
 * 21mins, still digested the question wrongly
 * Runtime: 10 ms, faster than 17.82% of Java online submissions for High Five.
 * Memory Usage: 44.4 MB, less than 5.09% of Java online submissions for High Five.
 */
public class Q1086_HighFive {
    public int[][] highFive(int[][] items) {
        LinkedHashMap<Integer, PriorityQueue<Integer>> score = new LinkedHashMap();
        for(int i = 0; i < items.length; i++) {
            PriorityQueue<Integer> s = score.getOrDefault(items[i][0], new PriorityQueue<Integer>((o1, o2) -> {
                return o2 - o1;
            }));
            s.add(items[i][1]);
            score.putIfAbsent(items[i][0], s);
        }
        int[][] result = new int[score.size()][2];
        int i = 0;
        for(Map.Entry<Integer, PriorityQueue<Integer>> m : score.entrySet()) {
            result[i][0] = m.getKey();
            PriorityQueue<Integer> s = m.getValue();
            int j;
            for(j = 0; j < 5; j++) {
                result[i][1] += s.poll();
            }
            result[i][1] /= 5;
            i++;
        }
        return result;
    }
}
