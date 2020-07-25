import java.util.Arrays;

/***
 * 33mins medium
 * Runtime: 3 ms, faster than 99.72% of Java online submissions for Largest Number.
 * Memory Usage: 39.3 MB, less than 33.11% of Java online submissions for Largest Number.
 */
public class Q179_LargestNumber {
    public String largestNumber(int[] nums) {
        if(nums.length == 0) {
            return "0";
        }
        String[] n = new String[nums.length];
        for(int i = 0; i < n.length; i++) {
            n[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(n, (o1, o2) -> {
            return compare(o1, o2);
        });
        StringBuilder sb = new StringBuilder();
        if(sb.length() == 0 && n[0].equals("0")) {
            return "0";
        }
        for(int i = 0; i < n.length; i++) {
            sb.append(n[i]);
        }
        return sb.toString();
    }

    int compare(String a, String b) {
        int l = a.length() < b.length() ? a.length() : b.length();
        int i = 0;
        for(; i < l; i++) {
            char aa = a.charAt(i);
            char bb = b.charAt(i);
            if(aa != bb) {
                return bb - aa;
            }
        }
        if(a.length() > b.length()) {
            return compare(a.substring(i), b);
        }
        else if(a.length() < b.length()) {
            return compare(a, b.substring(i));
        }
        else {
            return 0;
        }
    }

}
