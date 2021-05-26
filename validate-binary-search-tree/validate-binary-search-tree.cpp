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
/*
class Solution {
public:
   
        
        int getMin(TreeNode* root){
        
        if(root->left && root->right || root->left && !root->right){
            return getMin(root->left);
        } 
        return root->val;
    }
    int getMax(TreeNode* root){
        if(root->left && root->right || !root->left && root->right)
            return getMax(root->right);
        
        return root->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)     return false;
        
        if(root->left)
            if(getMax(root->left) >= root->val) //get the max out of left subtree
                return false;
        
        if(root->right)
            if(getMin(root->right) <= root->val) // get the min out of right subtree and compare with root
                return false;
        
        return isValidBST(root->left) && isValidBST(root->right); //if and only if both conditions are true
        
    }
};


We know that Inorder traversal of a BST yields a sorted list.
In this case we will use O(n) space vector to store the inorder traversal and check every time if the new element to be inserted is greater than the previous element. 

for example
[10,5,15,null,null,12,20]
in this case when we will be processing the node 5 our prev=NULL
while processing 10 prev=5
while processing 12 prev=10
while processing 15 prev=12
while processing 20 prev=15
The catch is if the val of prev is less than the current node val then our given tree is a BST
otherwise given tree is not a BST.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        TreeNode*prev=NULL;
        bool ans=true;
        ValidateBST(root,prev,ans);
        return ans;
    }
private:
    void ValidateBST(TreeNode*root,TreeNode* &prev,bool &ans)
    {
        if(root==NULL)
            return;
        ValidateBST(root->left,prev,ans);
        if(prev!=NULL)
        {
            if(root->val <=  prev->val)/*check if current node value is less than or equal to previous node value than the given tree is not a BST*/
                ans=false;
        }
        prev=root;
        ValidateBST(root->right,prev,ans);
    }
};