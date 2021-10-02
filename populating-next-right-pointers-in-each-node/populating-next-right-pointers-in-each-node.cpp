/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  /*  1- The question is of easy level if allowed to use extra space.
2-As evident from the question we have to perform BFS traversal without using any extra space. Here the 'next pointer' and complete binary tree comes into play.
3- Just traverse over the whole link formed by the next pointer over a level and simulaneously point the next levels node towards the node which falls over their right side.
4-Change the level by pointing towards the left most node.
5- Try to dry run for 15 nodes.

*/
    void bfs(Node * root)
    {
        while(root->left!=NULL)
        {
            Node * nextiter=root->left;
            root->left->next=root->right;
            while(root->next!=NULL)
            {
                root->right->next=root->next->left;
                root=root->next;
                root->left->next=root->right;                
            }
            root=nextiter;
        }
        return;
    }
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        bfs(root);
        return root;
    }
};