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
    TreeNode* solve(vector<int>& nums, int lo, int hi)
    {
            if(lo>hi) {return NULL;}
            int mid = (lo+hi)/2;
            TreeNode* temp = new TreeNode(nums[mid]);
             temp->left = solve(nums, lo, mid-1);
             temp->right = solve(nums, mid+1, hi);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return solve(nums,0,nums.size()-1);
    }
};