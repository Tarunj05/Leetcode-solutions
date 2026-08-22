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

        if( ! root ) return {};

        queue<TreeNode*> q;
        bool toFlip = false;

        vector<vector<int>> result;

        q.push( root );

        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            for( int i=0 ; i<sz ; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back( curr -> val );
                if( curr->left ) q.push( curr -> left);
                if( curr ->right ) q.push( curr -> right);
            }
            if( toFlip ) reverse( temp.begin() , temp.end());
            result.push_back( temp );
            toFlip = !toFlip;
        }
        return result;
    }
};