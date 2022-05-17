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
        int left= max(postorder(root->left),0); //max with zero so that we dont include the negative numbers 
        int right = max( postorder(root->right),0);
        maxi= max(maxi , right+left+root->val); // first we take sum
        return max(right,left) + root->val; // then we want a single max path so we choose the max left or right 
    }
public:
    int maxPathSum(TreeNode* root) {
     
        postorder(root);
        return maxi;
    }
};
        
        
      // https://www.youtube.com/watch?v=6cA_NDtpyz8