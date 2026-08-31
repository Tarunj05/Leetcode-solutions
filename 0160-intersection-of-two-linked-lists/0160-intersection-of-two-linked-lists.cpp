/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> vis;
        ListNode* temp = headA;
        while( temp ){
            vis.insert( temp );
            temp = temp -> next;
        }
        temp = headB;
        while( temp ){
            if( !vis.count( temp )){
                vis.insert(temp);
            }else{
                return temp;
            }
            temp = temp -> next;
        }
        return nullptr;
    }
};