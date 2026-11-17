// LeetCode 54 - Spiral Matrix (Medium)
// Approach: keep four boundaries (top, bottom, left, right) and peel the matrix layer by layer:
//           left->right, top->bottom, right->left, bottom->top, shrinking after each side.
// Time: O(m*n)   Space: O(1) extra (output excluded)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) res.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) res.push_back(matrix[bottom][j]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> b = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> c = {{1,2,3}};          // single row
    vector<vector<int>> d = {{1},{2},{3}};      // single column
    assert((s.spiralOrder(a) == vector<int>{1,2,3,6,9,8,7,4,5}));
    assert((s.spiralOrder(b) == vector<int>{1,2,3,4,8,12,11,10,9,5,6,7}));
    assert((s.spiralOrder(c) == vector<int>{1,2,3}));
    assert((s.spiralOrder(d) == vector<int>{1,2,3}));
    cout << "All tests passed\n";
    return 0;
}
