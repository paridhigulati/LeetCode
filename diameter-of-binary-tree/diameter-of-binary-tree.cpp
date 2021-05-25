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
    /*O(n^2)
    // we need to know the longer path in left and right sub tree so height for that and then again we visit the nodes to fin the longest path i.e the diameter, hence visiting every node twice 
    int height(TreeNode* &root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+ max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
      int lh = height(root->left);
       int rh = height(root->right);
      int ld =  diameterOfBinaryTree(root->left);
      int rd = diameterOfBinaryTree(root->right);
      return max(lh + rh  , max(ld,rd));
    }
};

*/
      int solve(TreeNode* root,int &res){
        
        if(root==NULL)
            return 0;
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp = 1 + max(l,r);
        int ans = max(temp,l+r+1);
        res = max(res,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res-1;
    }
};