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
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;

        queue<pair<TreeNode*, ll >> q; // node , idx in bfs
        q.push( {root , 0});

        ll maxWidth = 0;

        while( !q.empty()){
            int sz = q.size();
            ll minIdx ;
            ll maxIdx ;
            ll offset = q.front().second;
            for( int i=0 ; i<sz ; i++){
                TreeNode* curr = q.front().first;
                ll idx = q.front().second - offset;
                if( i == 0)minIdx = idx;
                if( i== sz-1)maxIdx = idx;
                q.pop();
                if(curr->left) q.push( { curr->left , 2*idx});
                if(curr->right) q.push( { curr->right , 2*idx+1});
            }
            maxWidth = max( maxWidth , maxIdx - minIdx + 1);
        }
        return maxWidth;
    }
};