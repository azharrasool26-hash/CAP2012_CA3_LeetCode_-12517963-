// LeetCode 232 - Implement Queue using Stacks (Easy)
// Approach: two stacks. Push goes to 'in'. For pop/peek, if 'out' is empty move everything
//           from 'in' to 'out' (this reverses the order, giving FIFO).
// Time: push O(1), pop/peek amortised O(1), empty O(1)   Space: O(n)
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class MyQueue {
    stack<int> in, out;
    void transfer() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    MyQueue() {}
    void push(int x) { in.push(x); }
    int pop() {
        transfer();
        int v = out.top();
        out.pop();
        return v;
    }
    int peek() {
        transfer();
        return out.top();
    }
    bool empty() { return in.empty() && out.empty(); }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    assert(q.peek() == 1);
    assert(q.pop() == 1);
    assert(q.empty() == false);
    q.push(3);
    assert(q.pop() == 2);
    assert(q.pop() == 3);
    assert(q.empty() == true);
    cout << "All tests passed\n";
    return 0;
}
