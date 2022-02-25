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
    TreeNode* invertTree(TreeNode* root) {
     
        // 1. recursive    
         if(root==NULL) return NULL;
        // TreeNode* temp = root->left;
        // root->left = invertTree(root->right);
        // root->right = invertTree(temp);
        // return root;
        
        //2. interative(bfs)
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
          TreeNode* temp = q.front();
            q.pop();
           //swap left , right
            TreeNode* swp = temp->left;
            temp->left = temp->right;
            temp->right = swp;
            //push left, right nodes to queue
            if(temp->left )
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        return root;
        
    }
};