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
    void flatten(TreeNode* root) {
        

        if(!root) return;
        
        TreeNode* rightNode = root->right;
       
        flatten(root->left);
   
            //root's immediate right will now point to left Head
            root->right=root->left;
            //root'left to null
            root->left = NULL;
        while(root->right)
        {
           root = root->right; 
        }
        flatten(rightNode);
        root->right = rightNode;
    }
};
        
     
      