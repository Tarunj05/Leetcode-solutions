/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if( !head || !head -> next || !head-> next -> next) return head;

        ListNode* temp = head;
        ListNode* odd = new ListNode( -1 );
        ListNode* even = new ListNode( -1 );
        ListNode* oPtr = odd;
        ListNode* ePtr = even;

        bool isOdd = 1;

        while( temp ){
            if( isOdd ){
                oPtr -> next = new ListNode( temp->val);
                oPtr = oPtr -> next;
            }else{
                ePtr -> next = new ListNode( temp-> val);
                ePtr = ePtr -> next;
            }
            temp = temp -> next;
            isOdd = !isOdd;
        }

        odd = odd -> next;
        even = even -> next;

        //join odd and even
        oPtr -> next = even;
        return odd;
    }
};