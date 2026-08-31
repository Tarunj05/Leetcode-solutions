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

    ListNode* findMid( ListNode* head ){
        ListNode* slow = head;
        ListNode* fast = head ->next;

        while( fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* mergeTwoSorted( ListNode* head1 , ListNode* head2){
        ListNode* dummy = new ListNode( -1 );
        ListNode* curr = dummy;
        while( head1 && head2 ){
            if( head1 -> val < head2 -> val){
                curr -> next = head1;
                curr = head1 ;
                head1 = head1-> next;
            }else{
                curr -> next = head2;
                curr = head2;
                head2 = head2 -> next;
            }
        }
        if( head1 ) curr -> next = head1;
        else curr -> next = head2;
        return dummy -> next;
    }

    ListNode* sortList(ListNode* head) {
        if( !head || !head -> next ) return head;
        ListNode* mid = findMid( head );
        
        ListNode* leftHead = head;
        ListNode* rightHead = mid -> next;
        mid -> next = nullptr;

        leftHead = sortList( leftHead);
        rightHead = sortList( rightHead);

        return mergeTwoSorted( leftHead , rightHead);

    }
};