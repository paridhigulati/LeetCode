class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        priority_queue<int>pq(nums.begin(), nums.end());
        
        int count=0 , a;
        while(count != k and !pq.empty())
        {
            count++;
             a = pq.top();
            pq.pop();
        }
        return a;
    }
};