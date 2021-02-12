#include<vector>
#include<queue>
using namespace std;

//10:09 10:34, a bit long

class MyStack {
private:
    queue<int> in;
    queue<int> out;
    queue<int>* in_ptr;
    queue<int>* out_ptr;
    void move()
    {
        while (in_ptr->size() > 1)
        {
            out_ptr->push(in_ptr->front());
            in_ptr->pop();
        }
        auto tmp = out_ptr;
        out_ptr = in_ptr;
        in_ptr = tmp;
    }
public:
    /** Initialize your data structure here. */

    MyStack() {
        in_ptr = &in;
        out_ptr = &out;
    }

    /** Push element x onto stack. */
    void push(int x) {
        if (out_ptr->size() > 0)
        {
            in_ptr->push(out_ptr->front());
            out_ptr->pop();
            out_ptr->push(x);
        }
        else
        {
            in_ptr->push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (out_ptr->size() == 0)
        {
            move();
        }
        int o = out_ptr->front();
        out_ptr->pop();
        return o;
    }

    /** Get the top element. */
    int top() {
        if (out_ptr->size() == 0)
        {
            move();
        }
        int o = out_ptr->front();
        return o;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return in.size() == 0 && out.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */