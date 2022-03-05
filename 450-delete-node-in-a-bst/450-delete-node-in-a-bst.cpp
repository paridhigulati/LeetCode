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
    
    TreeNode* findMin(TreeNode* root)
    {
        while(root->left)
            root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return NULL;
        
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else if(key < root->val) 
            root->left = deleteNode(root->left, key);
        
        else
        {
            // leaf node
            if(root->left == NULL and root->right ==NULL) 
               
            {
                delete root;
			     root = NULL;
                
            }
        
        else if(root->left == NULL)
        {
            //1 children 
            TreeNode* tmp = root;
            root = root->right;
            delete(tmp);
            //return root;
            
        }
        else if(root->right ==NULL)
        {
            TreeNode* tmp = root;
            root = root->left;
            delete(tmp);
            //return root;
        }
        else
        {
            TreeNode* tmp = findMin(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
            //2 children
        }
        }
        return root;
    }
};