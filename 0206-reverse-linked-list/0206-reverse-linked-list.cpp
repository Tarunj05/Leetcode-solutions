class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* back = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* front = curr->next; // Save the next node
            curr->next = back;           // Reverse the pointer
            back = curr;                 // Move back forward
            curr = front;                // Move curr forward
        }
        
        return back; // back is the new head
    }
};