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
      return max(lh + rh, max(ld,rd));
    }
};

/*
      int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    void findDiameter(TreeNode* root, int& diameter){
        if(!root or (!root->left and !root->right)) return;
        diameter = max(diameter,(depth(root->left)+depth(root->right)));
        findDiameter(root->left,diameter);
        findDiameter(root->right,diameter);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }
};

*/