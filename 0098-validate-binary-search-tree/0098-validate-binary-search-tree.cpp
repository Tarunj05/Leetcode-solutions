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

    bool inorder( TreeNode* root , TreeNode*& prev ){
        if(!root ) return true;
        
        if( !inorder( root -> left ,prev)) return false;

        if( prev && root -> val <= prev-> val ) return false;
        else prev = root;

        if( !inorder( root -> right , prev )) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if( ! root ) return true;
        TreeNode* prev = nullptr;
        return inorder( root , prev );
    }
};