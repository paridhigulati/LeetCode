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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        vector<double>ans;
        if(!root) return ans;
         double sum=0, count=0;
        q.push(root);
        while(!q.empty())

        {
            int n = q.size();
            
           sum=0;
            
            for(int  i=0;i<n;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                
                 sum +=tmp->val;
            
            }
           
            
        
    
    ans.push_back(double(sum)/n);
        }

return ans;
}
};