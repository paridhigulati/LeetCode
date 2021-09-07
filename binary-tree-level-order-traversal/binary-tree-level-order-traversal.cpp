//O(n) bfs
class Solution {
public: 
    /*
       vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>>ans;
        if(root==NULL) 
            return ans;
                
          queue<TreeNode*> q;
          q.push(root);
       while(!q.empty())
       {
             vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
           TreeNode* f = q.front();
           q.pop();
                v.push_back(f->val);
           if(f->left)
           {
           q.push(f->left);
           }
           if(f->right)
           {
           q.push(f->right);
           }
       }
   
          ans.push_back(v);
        }
        return ans;
    }
}; */
  /*RECURSIVE O(N^2)

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	recur_levelOrder(result, root, 0);
	return result;
}

void recur_levelOrder(vector<vector<int>> &result, TreeNode *root, int level)
{
	if (!root)
	{
    	return;
    }
    if ((level+1) > result.size())
    {
	    result.push_back(vector<int> {});
    }
    result[level].push_back(root->val);
    recur_levelOrder(result, root->left, level+1);
    recur_levelOrder(result, root->right, level+1);
}
}; */
    vector<vector<int>> levelOrder(TreeNode* root)
    {
         vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
       
        while(!q.empty())
        {
            vector<int>level;
            int n= q.size();
            for(int i=0;i<n;i++)
            {        
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) 
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                 
            }
            ans.push_back(level);
        }
        return ans;
    }
};