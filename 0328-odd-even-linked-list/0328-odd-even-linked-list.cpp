class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if( !head || !head -> next || !head -> next -> next ) return head;
        ListNode* temp = head -> next -> next;
        ListNode* oddEnd = head;
        ListNode* evenStart = head -> next;
        ListNode* evenEnd = head -> next;

        while( temp ){
            ListNode* front = temp -> next;

            oddEnd -> next = temp;
            temp -> next = evenStart;
            evenEnd -> next = front;

            oddEnd = temp;
            evenEnd = front;
            if( front ) temp = front -> next;
            else temp = nullptr;
        }
        return head;
    }
};