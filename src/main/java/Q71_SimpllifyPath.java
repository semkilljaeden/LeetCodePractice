import java.util.LinkedList;

/***
 * 30mins one shot AC medium
 * Runtime: 3 ms, faster than 97.76% of Java online submissions for Simplify Path.
 * Memory Usage: 39.3 MB, less than 87.37% of Java online submissions for Simplify Path.
 */
public class Q71_SimpllifyPath {
    public String simplifyPath(String path) {
        //dont need to check path has space
        LinkedList<String> stack = new LinkedList<String>();
        LinkedList<String> stack2 = new LinkedList<String>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < path.length(); i++) {
            char c = path.charAt(i);
            if(c != '/') {
                sb.append(c);
            }
            if(c == '/') {
                stack.add(sb.toString());
                sb.setLength(0);
                sb.append('/');
            }
        }
        if(sb.length() > 0) {
            stack.add(sb.toString());
        }
        sb.setLength(0);
        while(stack.size() > 0) {
            String s = stack.pop();
            if(s.equals("/") || s.equals("/.")){
                continue;
            }
            else if(s.equals("/..")) {
                if(stack2.size() > 0){
                    stack2.removeLast();
                }
            }
            else {
                stack2.add(s);
            }
        }
        for(String s : stack2) {
            sb.append(s);
        }
        if(sb.length() == 0){
            sb.append("/");
        }
        return sb.toString();
    }
}
