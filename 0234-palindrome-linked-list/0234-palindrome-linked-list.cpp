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

    bool check( vector<int>& list){
        int i = 0 , j = list.size()-1;
        while( i<j){
            if( list[i] != list[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if( !head || !head -> next) return true;
        vector<int> list ;
        while( head ){
            list.push_back( head -> val);
            head = head -> next;
        }
        return check( list );
    }
};