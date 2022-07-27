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
     
        unordered_map<Node*, Node*>mp;
        
        Node* tp = head;
        while(tp)
        {
            Node * cpy = new Node(tp->val);
            mp[tp]= cpy;
            tp=tp->next;
            
        }
        tp = head;
        while(tp)
        {
           Node*  copy = mp[tp];
            copy->next = mp[tp->next];
            copy->random = mp[tp->random];
            tp = tp->next;
        }
        return mp[head];
    }
};

        
     
       