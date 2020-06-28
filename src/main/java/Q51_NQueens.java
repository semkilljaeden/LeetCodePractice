import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/***
 * 1hr 40mins, algorithm is fast, took time to resolve silly bug
 * Runtime: 5 ms, faster than 53.59% of Java online submissions for N-Queens.
 * Memory Usage: 39.4 MB, less than 87.20% of Java online submissions for N-Queens.
 */
public class Q51_NQueens {
    boolean[] hSet;
    boolean[] vSet;
    boolean[] leftUpperSet;
    boolean[] rightLowerSet;
    List<List<Integer>> result = new ArrayList<>();
    int n;
    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        hSet = new boolean[n];
        vSet = new boolean[n];
        leftUpperSet = new boolean[n * 2 - 1];
        rightLowerSet = new boolean[n * 2 - 1];
        Arrays.fill(hSet, true);
        Arrays.fill(vSet, true);
        Arrays.fill(leftUpperSet, true);
        Arrays.fill(rightLowerSet, true);
        recurse(0, new ArrayList<>());
        for(int i = 0; i < result.size(); i++) {

            for(int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j));
            }
            System.out.println();
        }
        List<List<String>> realResult = new ArrayList<>();
        for(int i = 0; i < result.size(); i++) {
            StringBuilder sb = new StringBuilder();
            List<String> row = new ArrayList<>();
            for(int j = 0; j < result.get(i).size(); j++) {
                sb = new StringBuilder();
                for(int k = 0; k < n; k++) {
                    if(result.get(i).get(j) == k) {
                        sb.append('Q');
                    }
                    else {
                        sb.append('.');
                    }
                }
                row.add(sb.toString());
            }
            realResult.add(row);
        }
        return realResult;
    }

    public void recurse(int index, List<Integer> result) {
        for(int i = 0; i < n; i++) {
            if(hSet[index] && vSet[i]
                    && leftUpperSet[getLeftIndex(index, i)]
                    && rightLowerSet[getRightIndex(index, i)]){
                if(index == n - 1) {
                    result.add(i);
                    this.result.add(new ArrayList<Integer>(result));
                    result.remove(result.size() - 1);
                    return;
                }
                hSet[index] = false;
                vSet[i] = false;
                leftUpperSet[getLeftIndex(index, i)] = false;
                rightLowerSet[getRightIndex(index, i)] = false;
                result.add(i);
                recurse(index + 1, result);
                Integer x = result.remove(result.size() - 1);
                hSet[index] = true;
                vSet[i] = true;
                leftUpperSet[getLeftIndex(index, i)] = true;
                rightLowerSet[getRightIndex(index, i)] = true;
            }
        }
    }
    

    public int getLeftIndex(int i, int j) {
        return n - (i - j) - 1;
    }

    public int getRightIndex(int i, int j) {
        return i + j;
    }

}
