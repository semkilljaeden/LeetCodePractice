import java.util.ArrayDeque;

/***
 * 1hr hard
 * Runtime: 35 ms, faster than 99.27% of Java online submissions for Dinner Plate Stacks.
 * Memory Usage: 116.8 MB, less than 53.85% of Java online submissions for Dinner Plate Stacks.
 */
public class Q172_DinnerPlateStacks {
    ArrayDeque<Integer>[] s = new ArrayDeque[100001];
    int cap;
    int left = 0;
    int right = 0;
    public Q172_DinnerPlateStacks(int capacity) {
        cap = capacity;
    }

    public void push(int val) {
        if(s[left] == null) {
            s[left] = new ArrayDeque();
        }
        s[left].addLast(val);
        if(left > right) {
            right = left;
        }
        while(left < s.length && s[left] != null && s[left].size() == cap) {
            left++;
        }
    }

    public int pop() {
        if(s[right] == null || s[right].size() == 0) {
            return -1;
        }
        int result = s[right].removeLast();
        while(right > 0 && s[right].size() == 0) {
            right--;
        }
        return result;
    }

    public int popAtStack(int index) {
        if(index == right) {
            return pop();
        }
        if(index >= s.length || index < 0 || s[index] == null || s[index].size() == 0) {
            return -1;
        }
        int result = s[index].removeLast();
        if(index < left) {
            left = index;
        }
        return result;
    }
}
