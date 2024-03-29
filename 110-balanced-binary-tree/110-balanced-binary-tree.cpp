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
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        
       return max(lh,rh)+1;
        
        
    }
    bool isBalanced(TreeNode* root) {
       
        if(!root) return true;
        
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        
        if(abs(lh-rh) <= 1 and isBalanced(root->left) and isBalanced(root->right))
            return true;
        return false;
    }
    
};