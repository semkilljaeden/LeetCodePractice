#include<vector>
#include<string>
//15 mins werid question
//4mins, a better one

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
    int read(char* buf, int n) {
        int offset = 0;
        char bbuff[4];
        char* buff = bbuff;
        int read = 0;
        while (offset + 4 <= n)
        {
            read = read4(buf + offset);
            if (read < 4)
            {
                return offset + read;
            }
            offset += 4;
        }
        if (offset + 4 > n)
        {
            int rread = n - offset;
            read = read4(buff);
            read = read < rread ? read : rread;
            memcpy(buf + offset, buff, read);
        }
        return offset + read;
    }
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int offset = 0;
        char bbuff[4];
        char* buff = bbuff;
        int read = 0;
        while (offset + 4 <= n)
        {
            read = read4(buff);
            memcpy(buf + offset, buff, read < 4 ? read : 4);
            if (read < 4)
            {
                return offset + read;
            }
            offset += 4;
        }
        if (offset + 4 > n)
        {
            int rread = n - offset;
            read = read4(buff);
            read = read < rread ? read : rread;
            memcpy(buf + offset, buff, read);
        }
        return offset + read;
    }
};