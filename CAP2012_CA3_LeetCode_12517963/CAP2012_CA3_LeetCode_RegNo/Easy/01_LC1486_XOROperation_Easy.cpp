// LeetCode 1486 - XOR Operation in an Array (Easy)
// Approach: build nums[i] = start + 2*i on the fly and XOR everything.
// Time: O(n)   Space: O(1)
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++)
            result ^= (start + 2 * i);
        return result;
    }
};

int main() {
    Solution s;
    assert(s.xorOperation(5, 0) == 8);   // example 1
    assert(s.xorOperation(4, 3) == 8);   // example 2
    assert(s.xorOperation(1, 7) == 7);   // boundary: n = 1
    cout << "All tests passed\n";
    return 0;
}
