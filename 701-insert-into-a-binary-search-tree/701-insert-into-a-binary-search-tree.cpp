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
    
    //RECURSIVE -> o(n) tc and sc --- worst case for bst -> skew 
   
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if (val > root->val) root->right = insertIntoBST(root->right, val); // Continue searching in the right subtree
        else root->left = insertIntoBST(root->left, val); // Continue searching in the left subtree
        return root;
    }
};
/*
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     
        if(root==NULL)
    return new TreeNode (val);
       TreeNode* temp = root;
        while(true)
        {
         if(temp->val > val)
        {
             if(temp->left !=NULL)
             {
                 temp = temp->left;
             }
             else{
                 temp->left = new TreeNode (val);
             break;
         }
             
            //go left
        }
        else 
            {
               if( temp->val <= val)
        {
             if(temp->right !=NULL)
             {
                 temp = temp->right;
             }
             else{
                 temp->right = new TreeNode (val);
             break;
             }
             
        }
        }
        }
            //go right 
      
        return root;
    }
};
*/