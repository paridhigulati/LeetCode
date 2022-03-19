class Solution {
public:

    int halveArray(vector<int>& nums) {
        
        priority_queue<double>pq;
        
        double sum=0;
        int op = 0;
        
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        double half = sum/2 ;
       while( sum > half)
       {
           
           double oof = pq.top();
           pq.pop();
            sum -= oof/2;
           pq.push(oof/2);
           
           op++;
       }
        return op;
    }
};