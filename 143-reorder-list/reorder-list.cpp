class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        ListNode* curr = head;
        temp = prev;

        while(curr && temp) {
            ListNode* f1 = curr->next;
            ListNode* f2 = temp->next;

            curr->next = temp;
            temp->next = f1;

            curr = f1;
            temp = f2;
        }
    }
};
