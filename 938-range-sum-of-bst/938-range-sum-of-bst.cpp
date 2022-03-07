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
     int sum = 0;
    int dfs(TreeNode* root, int low , int high )
    {
       
        if(!root) return 0;
        
    
       
        if(root->val >= low and root->val <= high)
            sum += root->val;
         dfs(root->left, low, high);
        dfs(root->right, low,high);
      
        return sum;
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
       
        return dfs(root,low,high);
        
    }
};