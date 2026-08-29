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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> vis ;
        ListNode* temp = head ;
        while( temp ){
            if( !vis.count( temp )){
                
                vis.insert( temp );
                temp = temp -> next;
                
            }
            else return temp;
        }

        return nullptr;
    }
};