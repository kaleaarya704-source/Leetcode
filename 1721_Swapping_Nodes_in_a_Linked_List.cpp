#include <iostream>
#include <algorithm>
// Definition for singly-linked list.

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
          ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        // Step 1: Move first to k-th node from start
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 2: Move temp to end, second follows
        temp = first;
        while (temp->next) {
            temp = temp->next;
            second = second->next;
        }

        // Step 3: Swap values
        swap(first->val, second->val);

        return head;
    }
};