#include<vector>
#include<string>
//11:16 to 11:56, 40mins hard, a bit slow for this question
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.
Memory Usage: 6.3 MB, less than 94.16% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.
*/
int read4(char* b)
{

}
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char bbuff[4];
    int buff_pos = 4;
    int actual_size = 4;
    int read(char* buf, int n) {
        char* buff = bbuff;
        int count = 0;
        int to_read = actual_size - buff_pos;;
        if (to_read > 0)
        {           
            to_read = n < to_read ? n : to_read;
            if (to_read > 0)
            {
                memcpy(buf, buff + buff_pos, to_read);
                count += to_read;
                buff_pos += to_read;
            }
            if (count >= n)
            {
                return count;
            }
        }
        int rc = 0;
        while (count + 4 <= n)
        {
            rc = read4(buf + count);
            count += rc;
            if (rc < 4)
            {
                return count;
            }

        }
        if (count + 4 > n)
        {
            to_read = n - count;
            rc = read4(buff);
            actual_size = rc;
            to_read = rc < to_read ? rc : to_read;
            memcpy(buf + count, buff, to_read);
            buff_pos = to_read;
            count += to_read;
        }
        return count;
    }
};