// LeetCode 876 - Middle of the Linked List (Easy)
// Approach: slow moves 1 step, fast moves 2 steps; when fast reaches the end, slow is at the middle.
//           For even length this returns the second middle node (as required).
// Time: O(n)   Space: O(1)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode* build(const vector<int>& v) {
    ListNode dummy(0); ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}

int main() {
    Solution s;
    assert(s.middleNode(build({1,2,3,4,5}))->val == 3);
    assert(s.middleNode(build({1,2,3,4,5,6}))->val == 4);  // even: second middle
    assert(s.middleNode(build({9}))->val == 9);            // boundary: one node
    cout << "All tests passed\n";
    return 0;
}
