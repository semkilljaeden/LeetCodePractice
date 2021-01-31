#include<vector>
using namespace std;
//9:39 to 9:56, actually can be faster if i did not mixed the case of letter
/*
Runtime: 8 ms, faster than 99.96% of C++ online submissions for Surrounded Regions.
Memory Usage: 9.9 MB, less than 99.61% of C++ online submissions for Surrounded Regions.
Next challenges:

*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
        {
            return;
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = 'i';
                infect(board, i, 1);
            }
            if (board[i][board[0].size() - 1] == 'O')
            {
                board[i][board[0].size() - 1] = 'i';
                infect(board, i, board[0].size() - 2);
            }
        }
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[0][i] == 'O')
            {
                board[0][i] = 'i';
                infect(board, 1, i);
            }
            if (board[board.size() - 1][i] == 'O')
            {
                board[board.size() - 1][i] = 'i';
                infect(board, board.size() - 2, i);
            }
        }

        for (auto& b : board)
        {
            for (auto& c : b)
            {
                if (c == 'i')
                {
                    c = 'O';
                }
                else if (c == 'O')
                {
                    c == 'X';
                }
            }
        }
        return;
    }

    void infect(vector<vector<char>>& board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return;
        }
        if (board[i][j] != 'O')
        {
            return;
        }
        if (board[i][j] == 'O')
        {
            board[i][j] = 'i';
            infect(board, i + 1, j);
            infect(board, i - 1, j);
            infect(board, i, j + 1);
            infect(board, i, j - 1);
        }
    }
};