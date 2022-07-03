class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
    
        
        priority_queue<int>pq(piles.begin(), piles.end());
        int ans=0;
        
        while(k != 0)
        {
            int a = pq.top();
            
            pq.pop();
            
            a -= floor(a/2);
           
            pq.push(a);
            
            k--;
        }
        while(!pq.empty())
        {
            
            ans+= pq.top();
           // cout<<ans;
            pq.pop();
        }
        return ans;
        
    }
};