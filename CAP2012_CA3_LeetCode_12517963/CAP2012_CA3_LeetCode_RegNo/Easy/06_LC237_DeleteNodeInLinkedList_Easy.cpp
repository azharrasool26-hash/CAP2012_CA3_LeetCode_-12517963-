// LeetCode 237 - Delete Node in a Linked List (Easy)
// We are given only the node to delete (never the tail), not the head.
// Approach: copy the next node's value into this node, then skip the next node.
// Time: O(1)   Space: O(1)
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
    void deleteNode(ListNode* node) {
        ListNode* toFree = node->next;
        node->val = toFree->val;
        node->next = toFree->next;
        delete toFree;
    }
};

int main() {
    // build 4 -> 5 -> 1 -> 9
    vector<int> v = {4,5,1,9};
    ListNode* head = new ListNode(v[0]);
    ListNode* t = head;
    for (size_t i = 1; i < v.size(); i++) { t->next = new ListNode(v[i]); t = t->next; }

    Solution s;
    s.deleteNode(head->next);            // delete node with value 5
    vector<int> expected = {4,1,9};
    ListNode* p = head;
    for (int x : expected) { assert(p && p->val == x); p = p->next; }
    assert(p == nullptr);
    cout << "All tests passed\n";
    return 0;
}
