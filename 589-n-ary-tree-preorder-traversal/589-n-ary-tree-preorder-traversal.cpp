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
    private: vector<int>nodes;
public:
    
    vector<int>dfs ( Node* root)
    {
          if ( root == NULL ) {
            return nodes;
        }
        nodes.push_back(root->val);
        
        for( int i=0; i<root->children.size(); i++ ) {
            dfs(root->children[i]);
        }
        return nodes;
    }
    
    vector<int> preorder(Node* root)
    {
        //vector<int> nodes;
        return dfs(root);
    }
    // vector<int> preorder(Node* root) {
    //     return pre(root);
    // }
};