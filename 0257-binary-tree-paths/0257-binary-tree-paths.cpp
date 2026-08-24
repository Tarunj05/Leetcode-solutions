class Solution {
public:
    void getPaths(TreeNode* root, string temp, vector<string>& result) {
        if (!root) return;

        temp += to_string(root->val);

        // If leaf node, record the path
        if (!root->left && !root->right) {
            result.push_back(temp);
            return;
        }

        // Otherwise, continue exploring
        temp += "->";
        if (root->left) getPaths(root->left, temp, result);
        if (root->right) getPaths(root->right, temp, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        getPaths(root, "", result);
        return result;
    }
};