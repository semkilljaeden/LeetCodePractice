/***
 * 11mins medium
 * Runtime: 4 ms, faster than 11.77% of Java online submissions for Maximum Swap.
 * Memory Usage: 36.3 MB, less than 28.92% of Java online submissions for Maximum Swap.
 * Next challenges:
 */
public class Q670_MaximumSwap {
    public int maximumSwap(int num) {
        char[] c = ("" + num).toCharArray();
        for(int i = 0; i < c.length; i++) {
            int max = c[i];
            int idx = i;
            for(int j = i + 1; j < c.length; j++) {
                if(c[j] > max) {
                    max = c[j];
                    idx = j;
                }
                else if(idx > i && c[j] == max) {
                    max = c[j];
                    idx = j;
                }
            }
            if(idx > i) {
                char tmp = c[idx];
                c[idx] = c[i];
                c[i] = tmp;
                break;
            }
        }
        return Integer.valueOf(new String(c));
    }

}
