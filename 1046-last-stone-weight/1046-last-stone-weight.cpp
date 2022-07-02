class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(), stones.end());
        
        while(pq.size() != 0)
        {
            int a = pq.top();
            pq.pop();
            
            if(pq.size() == 0)
                return a;
            
            int b = pq.top();
            pq.pop();
            
            if(a==b) continue;
            else
                pq.push(abs(a-b));
        }
        return 0;
    }
};