#include "LCHeader.h"
#include<stack>
//2:10 2:17

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> in;
    stack<int> out;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.push(in.top());
                in.pop();
            }
        }
        int x = out.top();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.size() == 0 && out.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */