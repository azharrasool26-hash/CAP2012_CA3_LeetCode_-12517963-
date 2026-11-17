// LeetCode 35 - Search Insert Position (Easy)
// Approach: binary search for the first index whose value >= target (lower bound).
// Time: O(log n)   Space: O(1)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();      // answer lies in [0, n]
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,3,5,6};
    assert(s.searchInsert(a, 5) == 2);   // found
    assert(s.searchInsert(a, 2) == 1);   // insert in middle
    assert(s.searchInsert(a, 7) == 4);   // insert at end
    assert(s.searchInsert(a, 0) == 0);   // insert at start
    vector<int> b = {4};
    assert(s.searchInsert(b, 4) == 0);   // boundary: single element
    cout << "All tests passed\n";
    return 0;
}
