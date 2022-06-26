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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>>mp; 
        // horizontal dis,   level , nodes in sorted order hence the multiset and we can have more t han 1 nodes with same value 
        
        queue<pair<TreeNode*, pair<int, int>>>q; // node---horizontal distance ---level
        
        q.push({root, {0,0}});
        while(!q.empty())
        {
            auto  tmp = q.front();
            q.pop();
            
            TreeNode* frontNode = tmp.first;
            int hd = tmp.second.first;
            int level = tmp.second.second;
            
            mp[hd][level].insert(frontNode->val);
            
            if(frontNode->left)
                q.push({frontNode->left, {hd-1, level+1}});
            if(frontNode->right)
                q.push({frontNode->right, {hd+1, level+1}});
        }
        vector<vector<int>>ans;
        for(auto p : mp)
        {
            vector<int>col;
            for(auto q : p.second) // map<int, multiset<int>>
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};