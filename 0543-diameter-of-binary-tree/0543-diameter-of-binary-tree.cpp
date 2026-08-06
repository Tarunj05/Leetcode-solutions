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

    int rec( TreeNode* root , int& res ){

        int left=0 , right=0;
        if( root->left) left = rec( root -> left ,res)+1;

        if( root->right) right = rec( root -> right ,res)+1;

        res = max(res ,left + right);
        return max(left , right );
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        rec( root , res );
        return res;
    }
};