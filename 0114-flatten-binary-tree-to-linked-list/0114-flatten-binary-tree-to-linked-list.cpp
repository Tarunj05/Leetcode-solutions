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

    void preorder( TreeNode* root , vector<int>& traversal){
        if(!root) return;
        traversal.push_back(root->val);
        preorder(root->left,traversal);
        preorder(root->right,traversal);
    }

    void flatten(TreeNode* root) {
        vector<int> traversal;
        preorder( root , traversal);
        TreeNode* temp = root ;
        int n =traversal.size();
        for(int i=0 ; i<n ; i++){
            temp->val = traversal[i];
            temp->left = nullptr;
            if( i < n-1) temp->right = new TreeNode;
            temp = temp->right;
        }
    }
};