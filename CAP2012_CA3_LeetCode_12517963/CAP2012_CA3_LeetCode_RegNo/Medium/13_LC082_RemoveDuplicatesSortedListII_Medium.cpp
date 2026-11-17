// LeetCode 82 - Remove Duplicates from Sorted List II (Medium)
// Delete EVERY node whose value appears more than once (keep only distinct values).
// Approach: dummy head + 'prev'. If curr has the same value as curr->next, skip the whole run
//           of equal values and link prev to the node after the run; otherwise advance prev.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int dup = curr->val;
                while (curr && curr->val == dup) curr = curr->next;   // skip whole run
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

ListNode* build(const vector<int>& v) {
    ListNode dummy(0); ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
vector<int> toVec(ListNode* h) {
    vector<int> v;
    for (; h; h = h->next) v.push_back(h->val);
    return v;
}

int main() {
    Solution s;
    assert((toVec(s.deleteDuplicates(build({1,2,3,3,4,4,5}))) == vector<int>{1,2,5}));
    assert((toVec(s.deleteDuplicates(build({1,1,1,2,3}))) == vector<int>{2,3}));   // duplicates at head
    assert((toVec(s.deleteDuplicates(build({1,1,1}))) == vector<int>{}));          // all removed
    assert((toVec(s.deleteDuplicates(build({}))) == vector<int>{}));               // empty
    assert((toVec(s.deleteDuplicates(build({7}))) == vector<int>{7}));             // single node
    cout << "All tests passed\n";
    return 0;
}
