// LeetCode 150 - Evaluate Reverse Polish Notation (Medium)
// Approach: stack of operands. On a number push it; on an operator pop two operands
//           (right operand is popped first), apply the operator, push the result.
//           C++ integer division truncates toward zero, as the problem requires.
// Time: O(n)   Space: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoll(t));
            }
        }
        return (int)st.top();
    }
};

int main() {
    Solution s;
    vector<string> a = {"2","1","+","3","*"};
    vector<string> b = {"4","13","5","/","+"};
    vector<string> c = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> d = {"7"};                       // boundary: single operand
    vector<string> e = {"-7","2","/"};              // truncation toward zero -> -3
    assert(s.evalRPN(a) == 9);
    assert(s.evalRPN(b) == 6);
    assert(s.evalRPN(c) == 22);
    assert(s.evalRPN(d) == 7);
    assert(s.evalRPN(e) == -3);
    cout << "All tests passed\n";
    return 0;
}
