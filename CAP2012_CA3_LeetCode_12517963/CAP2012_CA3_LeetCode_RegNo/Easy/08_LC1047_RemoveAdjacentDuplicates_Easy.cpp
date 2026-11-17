// LeetCode 1047 - Remove All Adjacent Duplicates In String (Easy)
// Approach: use the result string as a stack. If the incoming char equals the top, pop; else push.
// Time: O(n)   Space: O(n)
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for (char c : s) {
            if (!st.empty() && st.back() == c) st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
};

int main() {
    Solution s;
    assert(s.removeDuplicates("abbaca") == "ca");
    assert(s.removeDuplicates("azxxzy") == "ay");
    assert(s.removeDuplicates("aa") == "");      // everything removed
    assert(s.removeDuplicates("a") == "a");      // boundary: one char
    cout << "All tests passed\n";
    return 0;
}
