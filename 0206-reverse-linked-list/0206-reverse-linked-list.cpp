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

    
    ListNode* reverseList(ListNode* head) {
        ListNode * resHead = new ListNode(-1);
        stack<int> st;
        ListNode* temp = head;
        while( temp != nullptr ){
            st.push( temp-> val);
            temp =temp -> next;
        }
        temp = resHead;
        while(!st.empty()){
            temp -> next = new ListNode( st.top());
            st.pop();
            temp = temp -> next;
        }
        return resHead -> next;
    }
};