// LeetCode 560 - Subarray Sum Equals K (Medium)
// Approach: prefix sums + hash map. If prefix[j] - prefix[i] == k, the subarray (i, j] sums to k.
//           While scanning, count how many earlier prefixes equal (current - k).
// Time: O(n)   Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;                 // empty prefix
        int prefix = 0, count = 0;
        for (int x : nums) {
            prefix += x;
            auto it = freq.find(prefix - k);
            if (it != freq.end()) count += it->second;
            freq[prefix]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,1,1}, b = {1,2,3}, c = {1,-1,0}, d = {5};
    assert(s.subarraySum(a, 2) == 2);
    assert(s.subarraySum(b, 3) == 2);
    assert(s.subarraySum(c, 0) == 3);   // negatives and zeros
    assert(s.subarraySum(d, 5) == 1);   // boundary: single element
    assert(s.subarraySum(d, 4) == 0);
    cout << "All tests passed\n";
    return 0;
}
