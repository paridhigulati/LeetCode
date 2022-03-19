class Solution {
public:
    
    
    
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        
        double sum=0;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        double half = sum/2 ;
       while( sum > half)
       {
           
           auto i = pq.top();
           pq.pop();
            sum -= i/2;
           pq.push(i/2);
           
           ++count;
       }
        return count;
    }
};