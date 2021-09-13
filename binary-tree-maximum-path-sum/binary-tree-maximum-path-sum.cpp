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
    
    int solve(TreeNode* root, int& result)
    {
        if(!root) return 0;
        int left = solve(root->left, result);
        int right = solve(root->right, result);
        // for each node, we have 3 cases
        //case 1 -> to include the curr node
        int inc_curr = max(max(left, right) + root->val, root->val);
        //case 2 without splitting, to check if this is root of max sum path
        int inc_root = max(inc_curr, left + right + root->val);
        //case 3 -> to exclude the curr node
          result = max(inc_root, result);
        
        return inc_curr;
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
     solve(root, result);
        return result;
    }
};