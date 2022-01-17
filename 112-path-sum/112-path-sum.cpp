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
    bool dfs(TreeNode* root, int sum)
    {
        int s = 0;
        
        if(!root) return false;
        if(root ->left ==NULL && root->right == NULL && sum-root->val ==0)
            return true;
        
       else
           return dfs(root->left, sum-root->val) || dfs(root->right, sum-root->val);
    
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return dfs(root, targetSum);
    }
};