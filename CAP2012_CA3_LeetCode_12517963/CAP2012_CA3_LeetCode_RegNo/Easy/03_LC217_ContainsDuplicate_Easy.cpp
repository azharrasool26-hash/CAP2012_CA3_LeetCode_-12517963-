// LeetCode 217 - Contains Duplicate (Easy)
// Approach: insert elements into a hash set; if an element is already present, duplicate found.
// Time: O(n) average   Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return true;
            seen.insert(x);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,3,1}, b = {1,2,3,4}, c = {1,1,1,3,3,4,3,2,4,2}, d = {7};
    assert(s.containsDuplicate(a) == true);
    assert(s.containsDuplicate(b) == false);
    assert(s.containsDuplicate(c) == true);
    assert(s.containsDuplicate(d) == false);   // boundary: single element
    cout << "All tests passed\n";
    return 0;
}
