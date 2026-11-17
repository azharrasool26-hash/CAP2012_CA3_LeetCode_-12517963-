// LeetCode 1572 - Matrix Diagonal Sum (Easy)
// Approach: add primary diagonal mat[i][i] and secondary diagonal mat[i][n-1-i];
//           if n is odd the centre cell is counted twice, so subtract it once.
// Time: O(n)   Space: O(1)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += mat[i][n - 1 - i];
        }
        if (n % 2 == 1) sum -= mat[n / 2][n / 2];
        return sum;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> b = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    vector<vector<int>> c = {{5}};
    assert(s.diagonalSum(a) == 25);
    assert(s.diagonalSum(b) == 8);
    assert(s.diagonalSum(c) == 5);       // boundary: 1x1
    cout << "All tests passed\n";
    return 0;
}
