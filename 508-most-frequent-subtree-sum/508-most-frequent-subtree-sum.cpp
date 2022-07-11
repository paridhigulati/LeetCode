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
     unordered_map<int, int>mp; //sum ---freq mapping 
    
    int dfs(TreeNode* root, int & maxi)
    {
        if(!root) return 0;
        
        int left = dfs(root->left, maxi);
        int right = dfs(root->right, maxi);
        
        int value = root->val;
        
        mp[left+right+value]++;
        
        if(maxi < mp[left+right+value])
            maxi =  mp[left+right+value];
        
        root->val =  left+right+value;
        return  left+right+value;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
    // sum up in bottom up manner and keep updating the frequency  
        vector<int>ans;
        if(!root) return ans;
        
       
        
        int maxi = 0;
    
        dfs(root,maxi);
        
      
        for(auto x:mp){
            if(x.second==maxi){
                ans.push_back(x.first);
        
                }
        }
            
            return ans;
            
            
    }
};



