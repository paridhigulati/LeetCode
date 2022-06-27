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
    
    vector<string> dfs(TreeNode* root, string str, vector<string>& ans)
    {
        if(!root) return ans;
        
        if(root->left || root->right)  
            str +=(to_string(root->val) + "->");
    
        else
        { 
            str += to_string(root->val);
            ans.push_back(str);
        }
        dfs(root->left,str, ans);
        dfs(root->right,str,ans);
        
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string>ans;
        string str = "";
        return dfs(root, str, ans);
    }
};

   