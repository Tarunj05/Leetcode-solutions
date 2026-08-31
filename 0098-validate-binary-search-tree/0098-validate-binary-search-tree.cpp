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

    void inorder( TreeNode* root , vector<int>& traversal ){
        if( !root ) return;
        inorder( root -> left , traversal );
        traversal.push_back( root -> val );
        inorder( root -> right , traversal );
    }

    bool isSorted( vector<int>& arr ){
        int n = arr.size();
        int num = arr[0];
        for( int i=1 ; i<n ; i++){
            if( arr[i] <= num){
                return false;
            }
            num = arr[i];
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if( !root ) return true;
        vector<int> traversal;
        inorder( root , traversal );
        return isSorted( traversal );
    }
};