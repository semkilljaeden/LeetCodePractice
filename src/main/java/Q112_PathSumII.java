import java.util.ArrayList;
import java.util.List;

/***
 * 3mins medium one shot perfect AC
 * Runtime: 1 ms, faster than 99.88% of Java online submissions for Path Sum II.
 * Memory Usage: 40 MB, less than 55.52% of Java online submissions for Path Sum II.
 */
public class Q112_PathSumII {
    List<List<Integer>> result = new ArrayList();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        rec(root, sum, new ArrayList());
        return result;
    }

    public void rec(TreeNode root, int sum, List<Integer> row) {
        if(root == null) {
            return;
        }
        if(root.left == null && root.right == null) {
            if(sum != root.val) {
                return;
            }
            row.add(root.val);
            result.add(new ArrayList(row));
            row.remove(row.size() - 1);
            return;
        }
        row.add(root.val);
        rec(root.left, sum - root.val, row);
        rec(root.right, sum - root.val, row);
        row.remove(row.size() - 1);
    }
}
