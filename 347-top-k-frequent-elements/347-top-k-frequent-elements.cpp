class Solution {
public:
    
    // BRUTE -> PUT ALL IN A MAP, SORT THE MAP IN DESCENDING ORDER AND THEN PUT THE TOP K ELEMENTS IN A VECTOR
    //     NLOGN FOR SORTING + K 
    //     O(NLOGN + K)
    
//   static bool cmp(pair<int, int>& a, pair<int, int>& b) { //Sorting in decending order
//     return a.second > b.second;
// }
//     {
//         vector<int>ans;
//         map<int,int> mp;
//         for(int i = 0; i < nums.size(); i ++)
//         {   
//             mp[nums[i]]++;
//          }
//     vector<pair<int,int>> v(mp.begin(),mp.end());
//     sort(v.begin(),v.end(),cmp);
//     int j = 1;
//     for(auto& it : v) {
//      if(j <= k)
//     ans.push_back(it.first);
//     j++;
//     }
//     return ans;
//     }
//     };
//********************************************************************************
    // BETTER USING HEAP  in brute the problem is with sorting so  
    // k size ka minheap nlogk
//     Store count of numbers in Map.
// Insert number and count as pairs in Min Heap, as Min Heap size > k we pop from Min Heap
// Add all numbers from Min Heap to result vector

//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         if(k==n)return nums;    // base case
        
//         vector<int>res(k);  // result vector
        
//         // store number counts in Map
//         unordered_map<int,int>track;    
//         for(auto &t: nums)track[t]++;
        
//         // Min Heap to store K frequent numbers, pop item if MinHeap size > K
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pQ;
//         for(auto &t: track)
//         {
//             pQ.push(make_pair(t.second,t.first));
//             if(pQ.size()>k)pQ.pop();
//         }
        
//         // add all items from MinHeap in to result vector
//         for(int i=0;i<k;i++){res[i]=pQ.top().second;pQ.pop();}
//         return res;
//     }
// };
    
 //  ***********************************************************************
//        // OPTIMAL BUCKET SORT
//     Store count of numbers in Map.
// Create buskets of size N+1 and put count x number in to x index bucket
// Add K numbers from bottom of the buckets in to result
    
         vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k==n)return nums;    // base case
        
        vector<int>res;  // result vector
        
        // store number counts in Map
        unordered_map<int,int>track;    
        for(auto &t: nums)track[t]++;
        
        // add all numbers from Map in to buckets and track the max count
        int maxc =  INT_MIN;
        vector<int> bucket[n+1];
        for(auto &t: track)
        {
            bucket[t.second].push_back(t.first);
             maxc=max(maxc,t.second);
        }
        // add all items from max count bucket in to result and in descending order of count
        int curr = maxc;
        while(res.size()<k)
        {
            // It is guaranteed that the answer is unique.
            if(!bucket[curr].empty())res.insert(res.end(),bucket[curr].begin(),bucket[curr].end());
            curr--;
        }
        
        return res;
    }
};