import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.PriorityQueue;

/***
 * 1hr10mins, going to the wrong direction.... damn
 * Runtime: 8 ms, faster than 41.38% of Java online submissions for Meeting Rooms II.
 * Memory Usage: 39.9 MB, less than 33.94% of Java online submissions for Meeting Rooms II.
 */
public class Q253_MeetingRoomsII {
    public int minMeetingRooms(int[][] intervals) {
        //boundary check
        if(intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, ((o1, o2) -> {
            return o1[0] - o2[0];
        }));
        PriorityQueue<Integer> room = new PriorityQueue();
        int count = 0;
        for(int i = 0; i< intervals.length; i++) {
            if(room.size() == 0 || room.peek() > intervals[i][0]) {
                room.add(intervals[i][1]);
                count = Math.max(count, room.size());
            }
            else {
                while(room.size() > 0 && room.peek() <= intervals[i][0]) {
                    room.poll();
                }
                room.add(intervals[i][1]);
            }
        }
        return count;
    }
}
