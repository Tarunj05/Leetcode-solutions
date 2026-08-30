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

    int noOfNodes( ListNode* head ){
        int count = 0;
        while( head ){
            count++;
            head = head -> next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int sz = noOfNodes( head );
        if( sz == n) return head -> next;
        ListNode* curr = head;
        int count = 1;
        while( count < sz - n  ){
            count++;
            curr = curr -> next;
        }
        ListNode* toDelete = curr -> next;
        curr -> next = curr -> next -> next;
        delete toDelete;
        return head;
    }
};