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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if(!root) return traversal;

        queue<TreeNode*> q;
        q.push(root);
        bool flip = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            while(sz--){
                TreeNode* curr = q.front() ; q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if( curr -> right) q.push( curr -> right);
            }
            if( flip ){
                reverse( temp.begin() , temp.end());
            }
            traversal.push_back( temp );
            flip = !flip;
        }
        return traversal;
    }
};