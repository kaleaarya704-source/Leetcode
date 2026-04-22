
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
     // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
          // Step 1: Reverse the list
        head = reverse(head);

        // Step 2: Track max and remove smaller nodes
        int maxVal = head->val;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val < maxVal) {
                // delete node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxVal = curr->val;
            }
        }

        // Step 3: Reverse back
        return reverse(head);
    }
};