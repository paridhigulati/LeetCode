/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

        
      class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> Result;
        ListNode* temp = root;
        int length=0,Extra=0;
        while(temp!=nullptr){   //Length of LL
            temp=temp->next;
            length++;
        }
        
        ListNode* itr = root;
        int Subpart_length = length/k;
        int Extra_Length = length%k;
        
        for(int i=0;i<k;i++)
        {
            Result.push_back(itr);
            if(Extra_Length>0){
                Extra=1;
                Extra_Length--;
            }
            else
                Extra=0;
            
            for(int j=0;j<Subpart_length+Extra-1 && itr!=nullptr;j++){
                itr=itr->next;      //Increment LL pointer equal to the length of subpart
            }
            if(itr!=nullptr){       
                ListNode* temp = itr;
                itr=itr->next;  
                temp->next=nullptr;                   
            }
        }
        return Result;
    }
};