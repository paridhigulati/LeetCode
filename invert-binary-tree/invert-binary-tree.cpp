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
     void swap(  TreeNode* root)
        {
           if(root==NULL) return;
         swap(root->left); // left subtree call
         swap(root->right); //right subtree call 
         
        //do a postorder traversal (for each subtree) and then swap
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right= temp;
        } 
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
       
    }
};