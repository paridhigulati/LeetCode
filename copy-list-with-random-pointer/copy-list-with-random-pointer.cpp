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
   // Node* copyRandomList(Node* head) {
        // brute force using hashmap , deepcopy = changes arent reflected  O(n) space and time
     /*if(head==NULL || head->next==NULL)
            return head;
        map<Node*, Node*> m; //key and value
        int i=0;
        Node* ptr = head;
       *traverse the list and make a new node everytime you visit a node. 
		Also store the pointer associated with it in a hashmap to use it
		later to connect all the nodes of the new list.
		
        while (ptr) {
            m[ptr] =new Node(ptr->val); // mapping the old node to the copy node
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
           using the pointers stored in the hashmap in the previous loop, 
		connect all the nodes in the copied list.
		
            m[ptr]->next = m[ptr->next]; //getting the value of next from map
            m[ptr]->random = m[ptr->random]; // getting the value of random from map
            ptr = ptr->next;
        } //EDGE CASE -> IF PTR->NEXT WAS NULL , MAP NULL TO NULL 
        return m[head];
    }
}; */
    // Idea is to create copy of original nodes and put them just after
    // their original counterparts. Eg: 1(orig)->1(Copy)->2(Orig)->2(Copy)->NULL
    // Since each copied node will be after their original, we can access the copied
    // counterpart by going to (orig->random)->next.
    Node* copyRandomList(Node* head) {
        Node* copy_head = nullptr, *copy_tail = nullptr;
        Node *nextptr = nullptr;
        
        // Add the copy nodes after the original nodes
        Node* temp = head;
        while(temp) {
            Node* node = new Node(temp->val);    
            nextptr = temp->next;
            // add the node copy
            temp->next = node;
            node->next = nextptr;
            
            temp = nextptr;
        }
        
        // update the random pointers
        temp = head;
        while(temp) {
            // set the random ptr of cloned node
            (temp->next)->random = temp->random ? (temp->random)->next : nullptr;
            // next node
            temp = temp->next->next;
        }
        
        temp = head;
        // remove the cloned list
        while(temp) {
            // remove the cloned node 
            // when current is the head of cloned list
            if(!copy_head) {
                copy_head = temp->next;
                copy_tail = copy_head;
            }
            else {
                copy_tail->next = temp->next;
                copy_tail = copy_tail->next;
            }
            // disconnect the cloned node
            temp->next = (temp->next)->next;
            temp = temp->next;
        }
        
        return copy_head;
    }
    };