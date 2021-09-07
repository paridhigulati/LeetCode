/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //lca(4,7)
      if(root==NULL ||  root==p || root==q ) // if we reach let say 4 or 7 so we don't need to go further hence returning
          return root;
        TreeNode* left = lowestCommonAncestor(root->left, p ,q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
};

        
    