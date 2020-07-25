/***
 * 2mins why is this question medium???
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Count Complete Tree Nodes.
 * Memory Usage: 42.1 MB, less than 40.78% of Java online submissions for Count Complete Tree Nodes.
 */
public class Q222_CountCompleteTreeNodes {
    TreeNode root;
    int level;
    public int countNodes(TreeNode root) {
        if(root == null) {
            return 0;
        }
        this.root = root;
        level = -1;
        TreeNode c = root;
        while(c != null) {
            c = c.left;
            level++;
        }
        int size = (1 << level) - 1;
        int left = 0;
        int right = size;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            TreeNode x = get(mid);
            if(x == null) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return size + left;
    }

    public TreeNode get(int x) {
        TreeNode c = root;
        if(level == 0) {
            return c;
        }
        String ii = Integer.toString(x, 2);
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < level - ii.length(); i++) {
            sb.append(0);
        }
        sb.append(ii);
        char[] path = sb.toString().toCharArray();
        TreeNode n = root;
        for(int i = 0; i < path.length; i++) {
            if(path[i] == '0') {
                n = n.left;
            }
            else {
                n = n.right;
            }
        }
        return n;
    }
}
