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
   
      void solve(TreeNode*root,int &k,int &cnt,vector<int>&path){
        
        //base case
        if(root==NULL)return;
        
        //pushing elements in vector
        path.push_back(root->val);
        
        //recursive call
        solve(root->left,k,cnt,path);
        solve(root->right,k,cnt,path);
        
        //we will check if sum equals our targetSum or not
        
        int size = path.size()-1;
       long long int sum = 0;
        for(int i = size;i>=0;i--){
            sum+=path[i];
            if(sum==k)cnt++;
        }
        
        //while returning we will pop.
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int cnt=0;
        solve(root,targetSum,cnt,path);
        return cnt;
    }
};