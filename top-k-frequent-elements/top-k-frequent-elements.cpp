class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     // o(n) + klogN\
        // use minheap when asked top, largest,greatest 
      
       
        unordered_map<int,int>mp;
        for(auto i : nums){
         mp[i]++;
        }
        
            // key(frequency), element 
 
        
        priority_queue<pair<int, int>> pq;
        for(auto i: mp){
           
            pq.push({i.second, i.first});
        }
        vector<int> vv;
        while(k--){
            vv.push_back(pq.top().second);
            pq.pop();
        }
        return vv;
}
};
