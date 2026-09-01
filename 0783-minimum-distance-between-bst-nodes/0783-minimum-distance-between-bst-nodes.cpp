class Solution {
public:

    void inorder( TreeNode* root , vector<int>& traversal ){
        if( !root ) return;

        inorder( root -> left , traversal);
        traversal.push_back( root -> val );
        inorder( root -> right , traversal );

    }

    int minDiffInBST(TreeNode* root) {
        
        vector<int> traversal;
        inorder( root , traversal );

        int minDiff = INT_MAX;
        for( int i=0 ; i<traversal.size()-1 ; i++){
            minDiff = min( minDiff , abs( traversal[i] - traversal[i+1] ) );
        }
        return minDiff;
    }   
};