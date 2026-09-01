class Solution {
public:
    int minDiff = INT_MAX;
    void inorder( TreeNode* root , int& prev ){
        if( !root ) return;

        inorder( root -> left , prev);
        if( prev != -1){
            minDiff = min( minDiff , abs( prev - root -> val));
        }
        prev = root -> val;
        inorder( root -> right ,prev);

    }

    int minDiffInBST(TreeNode* root) {
        
        int prev = -1;

        inorder( root , prev);

        return minDiff;
    }   
};