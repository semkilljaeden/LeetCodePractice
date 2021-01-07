import java.util.*;

/***
 * 8mins, not bad for recovery, but the question is really easy
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Pascal's Triangle.
 * Memory Usage: 36.9 MB, less than 64.18% of Java online submissions for Pascal's Triangle.
 */
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList();

        if(numRows == 0) {
            return result;
        }
        result.add(Arrays.asList(1));
        if(numRows == 1) {
            return result;
        }
        result.add(Arrays.asList(1, 1));
        if(numRows == 2) {
            return result;
        }
        numRows -= 2;
        for(int i = 0; i < numRows; i++) {
            List<Integer> last = result.get(result.size() - 1);
            List<Integer> tmp = new ArrayList();
            tmp.add(last.get(0));
            for(int j = 1; j < last.size(); j++) {
                tmp.add(last.get(j) + last.get(j - 1));
            }
            tmp.add(last.get(last.size() - 1));
            result.add(tmp);
        }
        return result;
    }
}