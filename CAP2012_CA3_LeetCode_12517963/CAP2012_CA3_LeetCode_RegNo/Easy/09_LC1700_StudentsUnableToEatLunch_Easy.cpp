// LeetCode 1700 - Number of Students Unable to Eat Lunch (Easy)
// Approach: count how many students want 0 and 1. Serve sandwiches in stack order;
//           if nobody left wants the top sandwich, the remaining students are stuck.
//           (Student order does not matter, because they keep cycling in the queue.)
// Time: O(n)   Space: O(1)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2] = {0, 0};
        for (int s : students) cnt[s]++;
        int n = sandwiches.size();
        for (int i = 0; i < n; i++) {
            if (cnt[sandwiches[i]] == 0) return n - i;   // remaining students can't eat
            cnt[sandwiches[i]]--;
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> a1 = {1,1,0,0}, b1 = {0,1,0,1};
    vector<int> a2 = {1,1,1,0,0,1}, b2 = {1,0,0,0,1,1};
    vector<int> a3 = {0}, b3 = {1};
    assert(s.countStudents(a1, b1) == 0);
    assert(s.countStudents(a2, b2) == 3);
    assert(s.countStudents(a3, b3) == 1);   // boundary: one student, wrong sandwich
    cout << "All tests passed\n";
    return 0;
}
