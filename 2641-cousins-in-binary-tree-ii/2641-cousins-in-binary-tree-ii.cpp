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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push( root );
        root -> val = 0;

        while(!q.empty()){
            int n = q.size();
            int nextLevelSum = 0;
            vector<TreeNode*> currNodes;
            for( int i=0 ; i<n ; i++){
                TreeNode* curr = q.front(); q.pop();
                currNodes.push_back( curr );
                if( curr ->left ){ 
                    nextLevelSum += curr->left ->val;
                    q.push( curr-> left);
                }
                if( curr->right){
                    nextLevelSum += curr->right-> val;
                    q.push( curr -> right);
                } 
            } 
            // now we have the total sum for next level
            // now we go to curr levels nodes one by one and update there childrens value
            // using val = total - siblings
            for( TreeNode* curr : currNodes ){
                int siblingSum = 0;

                if( curr -> left ){
                    siblingSum += curr -> left -> val;
                }
                if( curr -> right ){
                    siblingSum += curr -> right -> val;
                }

                    // update the values of next level nodes
                if( curr-> left){
                    curr -> left -> val = nextLevelSum - siblingSum;

                }
                if( curr -> right){
                    curr -> right -> val =  nextLevelSum - siblingSum;
                }

            }

            

        }
        return root;
    }
};