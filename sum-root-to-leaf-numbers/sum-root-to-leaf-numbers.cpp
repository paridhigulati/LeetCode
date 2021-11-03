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
   
    int ans =0;
    void dfs(TreeNode* root, int parent)
    {
      if(!root)
          return;
        parent*= 10;
        parent += root->val;
        if(root->right == NULL and root->left == NULL) // reached leaf node
        {
            ans+=parent;
            return;
        }
         dfs(root->left, parent);
        dfs(root->right, parent);
    }  
    public:
   int sumNumbers(TreeNode* root) {
        if(!root) 
         return 0;
        dfs(root, 0);
        return ans;
        
        }
};