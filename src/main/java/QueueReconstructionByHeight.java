import java.util.ArrayList;
import java.util.Arrays;

/***
 * 1:20mins, read the answer. failed
 * Runtime: 6 ms, faster than 86.32% of Java online submissions for Queue Reconstruction by Height.
 * Memory Usage: 40.7 MB, less than 11.03% of Java online submissions for Queue Reconstruction by Height.
 */
public class QueueReconstructionByHeight {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (o1, o2) -> {
            if(o1[0] == o2[0]) {
                return o1[1] - o2[1];
            }
            return o2[0] - o1[0];
        });
        ArrayList<int[]> tr = new ArrayList();
        for(int[] p : people) {
            tr.add(p[1], p);
        }
        int[][] result = new int[people.length][2];
        int i = 0;
        for(int[] p : tr) {
            result[i][0] = p[0];
            result[i++][1] = p[1];
        }
        return result;
    }
}
