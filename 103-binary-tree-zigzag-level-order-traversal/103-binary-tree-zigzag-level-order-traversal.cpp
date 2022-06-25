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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
          bool flag = 0;
            
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp(n);
          
            for(int i=0;i<n;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                int index;
                if(flag == 0)
                    index = i;
                else
                    index = n-i-1;
                 temp[index] = tmp->val;
                
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp -> right)
                    q.push(tmp->right);
            }
            
        flag = !flag;
        ans.push_back(temp);
        }
        return ans;
    }
};