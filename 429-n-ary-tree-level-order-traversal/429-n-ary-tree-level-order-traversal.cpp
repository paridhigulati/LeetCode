/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      
                vector<vector<int>>ans;

        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
//vector<vector<int>>ans;
        while(!q.empty())
        {
             
             vector<int>temp;
             int size = q.size();
            
            for(int idx = 0; idx < size; idx++)
            {                
            temp.push_back(q.front()->val);
                
            Node* tmp = q.front();
            
            q.pop();
            for(Node* child : tmp->children)
            
                q.push(child);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};