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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*>s;
        vector<int> res;
        while(!s.empty() || root)
        {
            if(curr){
                s.push(curr);
                curr = curr->left;
            }
            else {
                if(s.empty())
                    break;
                curr = s.top()->right;
                if(curr ==NULL)
                {
                    TreeNode* last = NULL;
                    while(!s.empty() && s.top()->right==last)
                    {
                        last = s.top();
                        s.pop();
                     res.push_back(last->val);
                        
                    }
                }
            }
        }
        return res;
    }
        };