// LeetCode 143 - Reorder List (Hard as per assignment sheet)
// Reorder L0->L1->...->Ln-1->Ln  into  L0->Ln->L1->Ln-1->L2->...
// Approach: (1) find middle with slow/fast pointers, (2) reverse the second half,
//           (3) merge the two halves alternately. Done in place (no value changes).
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1) find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2) split and reverse second half
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        // 3) merge alternately
        ListNode* first = head;
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
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
    ListNode* a = build({1,2,3,4});    s.reorderList(a);
    ListNode* b = build({1,2,3,4,5});  s.reorderList(b);
    ListNode* c = build({1});          s.reorderList(c);
    ListNode* d = build({1,2});        s.reorderList(d);
    assert((toVec(a) == vector<int>{1,4,2,3}));
    assert((toVec(b) == vector<int>{1,5,2,4,3}));
    assert((toVec(c) == vector<int>{1}));       // boundary: one node
    assert((toVec(d) == vector<int>{1,2}));     // boundary: two nodes
    cout << "All tests passed\n";
    return 0;
}
