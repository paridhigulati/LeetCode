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
private:    unordered_map<int,int>mp;
public:


      
     
   int  dfs(TreeNode* root, int &maxf, vector<int>& ans)
    {
        
      
       
        if(!root) return 0;
        
        int left = dfs(root->left, maxf, ans);
        int right = dfs(root->right, maxf, ans);
        
        int sum = left + right + root->val;
        
        mp[sum]++;
      
           if( mp[sum] == maxf)
           ans.push_back(sum);
       
      else if( mp[sum] > maxf)
       {
           maxf = mp[sum]; 
           ans.clear();
           ans.push_back(sum);
       }
       return sum;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
         vector<int>ans;

         int maxf = 0;
         dfs(root, maxf, ans);
        
       return ans;
        
        
    }
};



      