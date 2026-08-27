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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> vis ;
        ListNode* temp = head;
        vis.insert(temp);
        while( temp != nullptr ){
            if( !vis.count( temp -> next )){
                vis.insert( temp -> next);


            }
            else return true;
            temp = temp -> next;
        }
        return false;
    }
};