#include<vector>
#include<string>
#include<deque>
using namespace std;
//3:56, 4:44 TLE, o(n^2) 5:09 o(n)
/*
Runtime: 12 ms, faster than 88.06% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 13.3 MB, less than 8.43% of C++ online submissions for Evaluate Reverse Polish Notation.
*/
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0)
        {
            return 0;
        }
        if (tokens.size() == 1)
        {
            return stoi(tokens[0]);
        }
        deque<string> dq;
        int result = 0;
        auto itr = tokens.cbegin();
        dq.push_back(*itr++);
        dq.push_back(*itr++);
        dq.push_back(*itr++);
        while (dq.size() > 1 || itr != tokens.cend())
        {
            if (dq.size() < 3 || !cal(*(dq.end() - 3), *(dq.end() - 2), *(dq.end() - 1), result))
            {
                dq.push_back(*itr++);
                continue;
            }
            dq.pop_back();
            dq.pop_back();
            dq.pop_back();
            dq.push_back(to_string(result));
        }
        return stoi(dq.back());
    }


    bool inline is_numeric(const string& s) noexcept
    {
        auto i = s.cbegin();
        if (*i == '-')
        {
            i++;
        }
        for (; i != s.cend(); i++)
        {
            if (!isdigit(*i))
            {
                return false;
            }
        }
        return true;
    }

    bool inline is_op(const string& s) noexcept
    {
        return s == "+" ||
            s == "-" ||
            s == "*" ||
            s == "/";
    }

    bool inline cal(const string& i, const string& j, const string& k, int& result)
    {
        if (!is_numeric(i) || !is_numeric(j) || !is_op(k))
        {
            return false;
        }
        if (k == "+")
        {
            result = stoi(i) + stoi(j);
            return true;
        }
        if (k == "-")
        {
            result = stoi(i) - stoi(j);
            return true;
        }
        if (k == "*")
        {
            result = stoi(i) * stoi(j);
            return true;
        }
        if (k == "/")
        {
            result = stoi(i) / stoi(j);
            return true;
        }
        return false;
    }
};




class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        int j = 0;
        int k = 0;
        if (!next(j, tokens))
        {
            return stoi(tokens[0]);
        }
        next(k, tokens);
        next(k, tokens);
        int result = 0;
        do {
            if (cal(tokens[i], tokens[j], tokens[k], result))
            {
                tokens[i] = to_string(result);
                tokens[j] = "";
                tokens[k] = "";
                tokens.erase(remove(tokens.begin(), tokens.end(), ""), tokens.end());
                break;
            }
        } while (next(k, tokens)
            && next(j, tokens)
            && next(i, tokens));
        return evalRPN(tokens);
    }

    bool next(int& i, vector<string>& token)
    {
        i++;
        while (i < token.size())
        {
            if (token[i] != "")
            {
                return true;
            }
            i++;
        }
        return false;
    }

    bool is_numeric(const string& s)
    {
        auto i = s.cbegin();
        if (*i == '-')
        {
            i++;
        }
        for (; i != s.cend(); i++)
        {
            if (!isdigit(*i))
            {
                return false;
            }
        }
        return true;
    }

    bool is_op(const string& s)
    {
        return s == "+" ||
            s == "-" ||
            s == "*" ||
            s == "/";
    }

    bool cal(string& i, string& j, string& k, int& result)
    {
        if (!is_numeric(i) || !is_numeric(j) || !is_op(k))
        {
            return false;
        }
        if (k == "+")
        {
            result = stoi(i) + stoi(j);
            return true;
        }
        if (k == "-")
        {
            result = stoi(i) - stoi(j);
            return true;
        }
        if (k == "*")
        {
            result = stoi(i) * stoi(j);
            return true;
        }
        if (k == "/")
        {
            result = stoi(i) / stoi(j);
            return true;
        }
        return false;
    }
};