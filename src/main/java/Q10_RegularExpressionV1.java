/***
 * Runtime: 798 ms
 * Memory Usage: 37.8 MB
 */
public class Q10_RegularExpressionV1 {
    public boolean isMatch(String s, String p) {
        if(p.length() == 0) {
            return s.length() == 0;
        }
        Node root = new Node();
        root.c = p.charAt(0);
        Node iterator = root;
        int level = 1;
        for(int i = 1; i < p.length(); i++) {
            char c = p.charAt(i);
            if(c == '*') {
                iterator.left = iterator;
                continue;
            }
            Node next = new Node();
            next.level = level++;
            next.c = c;
            iterator.right = next;
            iterator = next;
        }
        return check(root, s, 0);
    }


    public boolean check(Node root, String s, int index) {
        if(root == null) {
            return false;
        }
        int incIndex = index + 1;
        Node tmp = root;
        if(index >= s.length()) {
            while(tmp.right != null) {
                if(tmp.left == null) {
                    return false;
                }
                tmp = tmp.right;

            }
            return tmp.left != null;
        }
        return root.isMatch(s.charAt(index))
                && (incIndex >= s.length() && root.right == null
                || check(root.left, s, incIndex)
                || check(root.right, s, incIndex))
                || (root.left != null && check(root.right, s, index));
    }
}

class Node {
    char c;
    Node left = null;
    Node right = null;
    int level = 0;
    public boolean isMatch(char s) {

        return c == '.' ? true : c == s;
    }
}