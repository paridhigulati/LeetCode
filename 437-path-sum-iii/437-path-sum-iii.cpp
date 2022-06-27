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
   
       int ans=0;
    void help(TreeNode* &root,int &tar,long long sum,unordered_map<int,int>mp){
        if(!root) return ;
        sum+=root->val;
        if(mp.find(sum-tar)!=mp.end()){
            ans+=mp[sum-tar];
        }
        mp[sum]++;
        help(root->left,tar,sum,mp);
        help(root->right,tar,sum,mp);
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<int,int>mp;
        mp.insert({0,1});
        help(root,targetSum,0,mp);
        return ans;
    }
};