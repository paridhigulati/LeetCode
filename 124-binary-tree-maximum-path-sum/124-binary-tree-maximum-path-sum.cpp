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
    private :
    int maxi = INT_MIN;
    private :
    int postorder(TreeNode* root)
    {
       if(!root) return 0;
        int left= max(postorder(root->left),0);
        int right = max( postorder(root->right),0);
        maxi= max(maxi , right+left+root->val);
        return max(right,left) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
     
        postorder(root);
        return maxi;
    }
};
        
        
      