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

    TreeNode* build( int low , int high , vector<int>& arr ){
        //base case
        if( low > high || low >= arr.size()) return nullptr;


        //solve current state

        TreeNode* root = new TreeNode( arr[low] );

        int leftStart = low + 1;
        
        int rightStart = leftStart;
        while( rightStart < arr.size() && arr[rightStart] < arr[low] ){
            rightStart++;
        }
        int leftEnd = rightStart-1;
        int rightEnd = high;

        root -> left = build( leftStart , leftEnd , arr);

        root -> right = build( rightStart , rightEnd , arr );

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build( 0 , preorder.size() , preorder);
    }
};