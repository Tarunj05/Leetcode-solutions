/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)return false;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            
            bool xInLevel =0 , yInLevel = 0;
            for( int i=0 ; i<n ; i++){
                TreeNode* curr = q.front() ;  q.pop();
                bool xFound = 0 , yFound = 0;
                if( curr ->left){
                    q.push(curr->left);
                    if( curr->left->val == x) xFound = true;
                    if( curr -> left->val == y) yFound = true;
                }
                if( curr ->right){
                    q.push(curr->right);
                    if( curr->right->val == x) xFound = true;
                    if( curr -> right->val == y) yFound = true;
                }
                if( xFound && yFound ) return false;//same parent
                if( xFound ) xInLevel = true;
                else if( yFound ) yInLevel = true;
            }
            if( xInLevel && yInLevel ) return true;
            
        }
        return false;
    }
};