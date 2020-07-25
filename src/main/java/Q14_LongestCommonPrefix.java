/***
 * Implementation Duration: 8mins Easy
 * 0 ms, faster than 100.00%
 * 37.5 MB, less than 68.57%
 */

class Q14_LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        char tmp;
        int index = 0;

        while(true) {
            if(index >= strs[0].length()) {
                return sb.toString();
            }
            tmp = strs[0].charAt(index);
            for(int i = 0; i < strs.length; i++) {
                if(index >= strs[i].length() || tmp != strs[i].charAt(index)) {
                    return sb.toString();
                }
            }
            sb.append(tmp);
            index++;
        }
    }
}