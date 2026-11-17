// LeetCode 24 - Swap Nodes in Pairs (Medium)
// Approach: dummy head + 'prev' pointer. For each pair (a, b): prev->b, b->a, a->next-of-b.
//           Nodes are relinked (values are NOT swapped).
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;
            a->next = b->next;
            b->next = a;
            prev->next = b;
            prev = a;
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
    assert((toVec(s.swapPairs(build({1,2,3,4}))) == vector<int>{2,1,4,3}));
    assert((toVec(s.swapPairs(build({1,2,3}))) == vector<int>{2,1,3}));  // odd length
    assert((toVec(s.swapPairs(build({}))) == vector<int>{}));            // empty
    assert((toVec(s.swapPairs(build({1}))) == vector<int>{1}));          // single node
    cout << "All tests passed\n";
    return 0;
}
