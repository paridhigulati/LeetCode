class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1 && k%2 == 1) return -1; 
        priority_queue<int>pq; 
        for (int i=0;i<nums.size() &&  i<k-1; ++i) {
            pq.push(nums[i]); 
        }
        int m{}; 
        if (!pq.empty()) {
            m = pq.top(); 
        }
        if (k<nums.size()) {
            m = max(m , nums[k]); 
        }
        return m; 
    }
};

  