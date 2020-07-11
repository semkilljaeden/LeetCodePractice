import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.TreeSet;

/***
 *22mins read the answer yesterday, one shot AC
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Unique Binary Search Trees II.
 * Memory Usage: 40 MB, less than 60.19% of Java online submissions for Unique Binary Search Trees II.
 */

public class Q95_UniqueBinarySearchTreesII {
    public List<TreeNode> generateTrees(int n) {
        if(n == 0) {
            return new ArrayList();
        }
        return recurse(1, n);
    }

    public List<TreeNode> recurse(int left, int right) {
        List<TreeNode> result = new ArrayList();
        if(left == right) {
            result.add(new TreeNode(left));
            return result;
        }
        if(right < left) {
            result.add(null);
            return result;
        }
        for(int i = left; i <= right; i++) {
            List<TreeNode> ln = recurse(left, i - 1);
            List<TreeNode> rn = recurse(i + 1, right);
            for(int x = 0; x < ln.size(); x++) {
                for(int y = 0; y < rn.size(); y++) {
                    TreeNode root = new TreeNode(i);
                    root.left = ln.get(x);
                    root.right = rn.get(y);
                    result.add(root);
                }
            }
        }
        return result;
    }
}
