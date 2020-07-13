/***
 * 22:35 easy question, did not think of the solution
 */
public class Q942_DIStringMatch {
    public int[] diStringMatch(String s) {
        int N = s.length();
        int hi = N;
        int lo = 0;
        int[] result = new int[N + 1];
        for(int i = 0; i < N; i++) {
            char c = s.charAt(i);
            if(c == 'I') {
                result[i] = lo++;
            }
            else {
                result[i] = hi--;
            }
        }
        result[N] = lo;
        return result;
    }
}
