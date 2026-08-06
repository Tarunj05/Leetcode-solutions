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

    void backtracking( TreeNode* root , vector<int>& path, vector<string>& pathList){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right){
            string withArrow = "";
            int n = path.size();
            for( int i=0 ; i<n ; i++){
                withArrow += to_string(path[i]);
                if( i < n-1) withArrow += "->";
            }

            pathList.push_back(withArrow);
        }else{
            backtracking( root->left , path , pathList);
            backtracking( root->right , path , pathList);
        }
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> pathList;
        vector<int> path;
        backtracking( root , path , pathList);
        return pathList;
    }
};