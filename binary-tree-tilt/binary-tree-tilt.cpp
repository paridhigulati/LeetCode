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

    /* compute the values of the left and right sub sums, recursively;
update res as the absolute value of left - right;
finally return the value of the cumulated sum of all the nodes up to here (current node included), as left + right + root->val */
class Solution {
public:
     int sum(TreeNode* root)
     {
         if(root==NULL)
             return 0;
        return root->val + sum(root->left)+sum(root->right);
         
     }
    int findTilt(TreeNode* root) {
        
        if(!root)
            return 0;
       int ls = sum(root->left);
       int rs = sum(root->right);
        int tilt = abs(ls-rs) ;
        return tilt + findTilt(root->left) + findTilt(root->right);
    }
     };


/*
class Solution {
public:
  int findTilt(TreeNode* root) {
    if (!root) return 0;
    return abs(sum(root->left) - sum(root->right)) + findTilt(root->left) + findTilt(root->right);
  }
  
  int sum(TreeNode* root) {
    if (!root) return 0;
    return root->val + sum(root->left) + sum(root->right);
  }
}; */