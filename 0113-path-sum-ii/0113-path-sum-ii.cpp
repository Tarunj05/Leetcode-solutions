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

    void backtracking( TreeNode* root ,int remSum , vector<int>&templist , vector<vector<int>>& list){
        if( !root) return;

        //include curr node
        templist.push_back( root->val);


        if(!root->left && !root->right){
            if( remSum == root->val){
                list.push_back(templist);
            }
            templist.pop_back();
            return;
        }

        // explore all choices
        backtracking( root->left , remSum-root->val,templist,list );
        backtracking( root->right, remSum-root->val , templist,list);
        //undo
        templist.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>list;
        vector<int> templist;
        backtracking( root , targetSum, templist , list);
        return list;
    }
};