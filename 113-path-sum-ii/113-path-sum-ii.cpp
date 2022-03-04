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
            vector<vector<int>>ans;
   vector<int>v;
   void dfs(TreeNode* root, int target, int curr)
    {
        
        

      if(!root) return;
        curr += root->val;
       v.push_back(root->val);
       
        if(root->left == NULL and root->right==NULL )
        {
            if(curr == target)
                ans.push_back(v);
        }
        
       else
       {
           dfs(root->left, target, curr );
           dfs(root->right, target, curr);
       }
        
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        dfs(root, targetSum, 0);
        return ans;
    }
};