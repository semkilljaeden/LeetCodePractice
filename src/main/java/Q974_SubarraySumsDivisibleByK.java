/***
 * 1hr. get almost everything correct but failed on math. tried to use map[K - (sum % K + K) % K - 1]
 */
public class Q974_SubarraySumsDivisibleByK {
    public int subarraysDivByK(int[] A, int K) {
        int[] map = new int[K];
        int sum = 0;
        int result = 0;
        map[0]++;
        for(int x : A) {
            sum = sum + x;
            result += map[(sum % K + K) % K];
            map[(sum % K + K) % K]++;
        }
        return result;
    }
}
