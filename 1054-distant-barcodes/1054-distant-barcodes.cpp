class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        map<int,int>mp;
        vector<int>ans;
        //if(barcodes.size()==0 || barcodes.size()==1)return ans;
        for(auto i : barcodes)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i : mp)
        {
            pq.push(make_pair(i.second, i.first));
            
            
        }
        while(pq.size()>1)
        {
            int maxFreq = pq.top().second;
            pq.pop();
            
            int nextFreq = pq.top().second;
            pq.pop();
            
            ans.push_back(maxFreq);
            ans.push_back(nextFreq);
            
            if(mp[maxFreq]-1  > 0)
            { 
                mp[maxFreq]-=1;
                pq.push(make_pair(mp[maxFreq], maxFreq));
            }
            
            if(mp[nextFreq]-1> 0)
            {
                mp[nextFreq]-=1;
                pq.push(make_pair(mp[nextFreq], nextFreq));
            }
            
            
            
        }
        if(pq.size() )
        {
            int last= pq.top().second;
            if(mp[last]-1 > 0)
            return ans;
          else 
            ans.push_back(last);
        }
        return ans;
        
    }
};