class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curr = 0;
        int jump = 0;
        int maxReach = 0;
        
  int n = nums.size();
        if(n==1) return 0;
     for(int i=0;i<n-1;i++){
     
         if(nums[i]+i  > curr){
             curr = nums[i] + i ; 
          }
        if(maxReach == i){
            jump++;
        maxReach = curr;
        }
    }
        return jump;
    }
};