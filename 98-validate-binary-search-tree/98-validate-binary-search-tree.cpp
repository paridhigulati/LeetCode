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
    
    bool solve(TreeNode* root, long mini, long maxi)
    {
        if(!root) return true; //hai hi nhi koi node 
        
        if(root->val <= mini or root->val >= maxi)
            return false;
        
        return solve(root->left, mini, root->val) and solve(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        
       
        return solve(root, LONG_MIN, LONG_MAX);
    }
};