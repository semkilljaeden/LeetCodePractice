/***
 * easy  did badly, too slow
 *Runtime: 2528 ms, faster than 5.00% of Java online submissions for Implement strStr().
 * Memory Usage: 38.3 MB, less than 44.13% of Java online submissions for Implement strStr().
 *
 *
 * Substring comparison is much faster than charAt iteration since the latter need to cast byte to char everytime
 * and check boundary, the latter compare byte[] and bounday check for only once.
 */
public class Q28_ImplStrStr {
    public int strStr(String haystack, String needle) {
        int result = 0;
        int index = 0;
        int nextStart = -1;
        if(needle == null || needle.length() == 0) {
            return 0;
        }
        if(haystack == null ||  haystack.length() == 0 ) {
            return -1;
        }
        int i = 0;
        int j = i;
        int next = -1;
        while(i < haystack.length()) {
            j = i;
            while(j < haystack.length() && haystack.charAt(j) == needle.charAt(index)) {
                if(index >= needle.length() - 1) {
                    return i;
                }
                else if(next < i && haystack.charAt(j) == needle.charAt(0)) {
                    next = j;
                }
                j++;
                index++;
            }
            if(next > i) {
                i = next;
            }
            else {
                i++;
            }
            index = 0;
        }
        return -1;
    }

    public int strStr2(String haystack, String needle) {
        if( needle ==null) return 0;
        int m = haystack.length();
        int n = needle.length();
        for(int start = 0; start< m-n+1;start++){
            if( haystack.substring(start,start+n).equals(needle) ){
                return start;
            }
        }

        return -1;
    }
}
