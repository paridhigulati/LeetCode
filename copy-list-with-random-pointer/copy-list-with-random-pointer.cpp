/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // brute force using hashmap , deepcopy = changes arent reflected 

        map<Node*, Node*> m; //key and value
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val); // mapping the old node to the copy node
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next]; //getting the value of next from map
            m[ptr]->random = m[ptr->random]; // getting the value of random from map
            ptr = ptr->next;
        } //*EDGE CASE -> IF PTR->NEXT WAS NULL , MAP NULL TO NULL 
        return m[head];
    }
};