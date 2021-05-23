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
  /*    void dfs(TreeNode* root, string s, vector<string>v)
    {
        s+=root->val;
        
        if(root->left ==NULL && root->right==NULL )
        {  v.push_back(s);
            return;
        }
        if(root->left!=NULL)
        {
            dfs(root->left, s+"->" + to_string(root->left->val),v);
        }
        if(root->right!=NULL)
        {
            dfs(root->right, s+"->"+ to_string(root->right->val),v);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        if(root==NULL) return v;
        dfs(root,"",v);
        return v;
    }
    
  
};



*/
   
    vector<string>V;
    
    void dfs(TreeNode* root, string s)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left == NULL and root->right==NULL)
        {
            V.push_back(s+to_string(root->val));
        }
        dfs(root->left, s+to_string(root->val)+"->");
        
        dfs(root->right, s+to_string(root->val)+"->");
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
     
        dfs(root, "");
        return V;
    }
};