import java.util.LinkedList;

/***
 * read the solution
 * Runtime: 13 ms, faster than 41.30% of Java online submissions for Serialize and Deserialize BST.
 * Memory Usage: 40.5 MB, less than 46.04% of Java online submissions for Serialize and Deserialize BST.
 */
public class Q449_SerializeDeserializeBST {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "";
        }
        return intToString(root.val) + serialize(root.left) + serialize(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        char[] d = data.toCharArray();
        LinkedList<Integer> list = new LinkedList();
        for(int i = 0; i < d.length; i += 4) {
            list.add(stringToInt(d, i));
        }
        return rec(list, Integer.MAX_VALUE, Integer.MIN_VALUE);
    }

    public TreeNode rec(LinkedList<Integer> d, int u, int l) {
        if(d.size() == 0 || d.get(0) < l || d.get(0) > u) {
            return null;
        }
        TreeNode root = new TreeNode(d.removeFirst());
        root.left = rec(d, root.val, l);
        root.right = rec(d, u, root.val);
        return root;
    }

    public String intToString(int x) { //sign
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 4; i++) {
            sb.append((char)(x & (1 << 8) - 1));
            x = x >> 8;
        }
        return sb.toString();
    }

    public int stringToInt(char[] c, int idx) {
        int x = 0;
        int j = 0;
        for(int i = idx; i < idx + 4; i++) {
            x += c[i] << (8 * j++);
        }
        return x;
    }
}
