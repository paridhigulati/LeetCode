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
    bool hasPathSum(TreeNode* root, int sum) {
      if(root== NULL)
          return false;
        if(root->right ==NULL &&root->left==NULL && sum - root->val ==0)
        { 
            return true;  // found the leaf node with the target sum
        }
        else 
            return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right , sum-root->val);
    }
};