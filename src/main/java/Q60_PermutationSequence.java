import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/***
 * 45mins medium
 * Runtime: 4 ms, faster than 29.58% of Java online submissions for Permutation Sequence.
 * Memory Usage: 36.6 MB, less than 97.29% of Java online submissions for Permutation Sequence.
 *
 * use forloop to create array is much faster than IntStream
 * Runtime: 1 ms, faster than 98.44% of Java online submissions for Permutation Sequence.
 * Memory Usage: 37 MB, less than 65.79% of Java online submissions for Permutation Sequence.
 */
public class Q60_PermutationSequence {
    public String getPermutation(int n, int k) {
        StringBuilder sb = new StringBuilder();
        List<Integer> pile = IntStream.range(1, 10).mapToObj(i -> i).collect(Collectors.toList());
        k--;
        for(int i = n; i >= 1; i--) {
            int factor = factorial(i - 1);
            int pos = k / factor;
            sb.append(pile.remove(pos));
            k = k % factor;
        }
        return sb.toString();
    }

    public int factorial(int n) {
        int result = 1;
        while(n > 1) {
            result *= n--;
        }
        return result;
    }
}
