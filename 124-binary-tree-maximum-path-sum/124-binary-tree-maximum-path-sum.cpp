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
    private: int maxSum = INT_MIN; //since we are having negative so cannot be 0  
public:
    
    int getSum(TreeNode* root)
    {
        if(!root) return 0; 
        //performs postorder
        int left = max(getSum(root->left), 0);
        int right = max(getSum(root->right), 0);
        
        maxSum  = max(maxSum, left+right+ root->val);
        //EDGE CASE => IF WE GET NEG LEFT/RIGHT, REPLACE IT WITH ZERO
        return max(left, right) + root->val;
        
    }
    int maxPathSum(TreeNode* root) {
  
        
        if(!root) return 0;
        
          getSum(root);
            
            return maxSum;
        
     
    }
};