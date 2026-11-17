// LeetCode 85 - Maximal Rectangle (Hard)
// Approach: treat each row as the base of a histogram. heights[j] = number of consecutive '1's
//           ending at this row in column j. For each row, find the largest rectangle in the
//           histogram using a monotonic increasing stack (LeetCode 84 idea).
// Time: O(rows * cols)   Space: O(cols)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    int largestInHistogram(vector<int>& h) {
        stack<int> st;                 // indices with increasing heights
        int best = 0, n = h.size();
        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : h[i];   // sentinel 0 flushes the stack
            while (!st.empty() && h[st.top()] >= curr) {
                int height = h[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, height * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int cols = matrix[0].size(), best = 0;
        vector<int> heights(cols, 0);
        for (auto& row : matrix) {
            for (int j = 0; j < cols; j++)
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            best = max(best, largestInHistogram(heights));
        }
        return best;
    }
};

int main() {
    Solution s;
    vector<vector<char>> a = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    vector<vector<char>> b = {{'0'}};
    vector<vector<char>> c = {{'1'}};
    vector<vector<char>> d = {{'1','1'},{'1','1'}};
    assert(s.maximalRectangle(a) == 6);
    assert(s.maximalRectangle(b) == 0);
    assert(s.maximalRectangle(c) == 1);
    assert(s.maximalRectangle(d) == 4);
    cout << "All tests passed\n";
    return 0;
}
