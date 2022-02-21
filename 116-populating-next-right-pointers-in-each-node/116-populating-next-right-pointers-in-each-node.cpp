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
 
    Node* connect(Node* root) {

//          at each level, connect previously visited node to curr 
         if(!root) return root;
        queue<Node*>q;
         q.push(root);
         while(!q.empty())
         {
          
        int n=q.size();
             for(int i=0;i<n;i++)
            {
                 Node* t = q.front();
                 q.pop();
        
                 if(i!=n-1) //  to check if it's not the last node 
                  t->next = q.front();
                 if(t->left)
                     q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        return root;
     } };
    //       Node* connect(Node* root) {
    //     if(!root)return root;
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int n=q.size();
    //         for(int i=0;i<n;i++){
    //             Node* x=q.front();
    //             q.pop();
    //             if(i!=n-1)x->next=q.front();
    //             if(x->left)q.push(x->left);
    //             if(x->right)q.push(x->right);
    //         }
    //     }
    //     return root;
    // }